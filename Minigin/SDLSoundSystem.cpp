#include "SDLSoundSystem.h"
#include <iostream>
#include <vector>
#include <mutex>
#include <queue>

namespace dae
{
	enum class SoundType
	{
		PlayMusic,
		PlaySound,
		ChangeMasterVolume
	};
	struct SoundData
	{
		SoundType type;
		const SoundId id;
		int loops{ 0 };
	};

	class SDLSoundSystem::SDLSoundSystemImpl final
	{
	public:
		SDLSoundSystemImpl();
		~SDLSoundSystemImpl();

		void Play(const SoundId id, int loops = 0);
		void PlayMusic(const SoundId id, int = -1);

		void PauseMusic();

		void AddSound(SoundId soundId, const std::string& fileName);
		void AddMusic(SoundId soundId, const std::string& fileName);

		void ChangeMasterVolume(int volume);

	private:
		void ProcessQueue();

		bool m_RunQueue{true};

		std::map<SoundId, Mix_Chunk*> m_Sounds{};
		std::map<SoundId, Mix_Music*> m_Music{};

		std::mutex m_SoundMutex;
		std::mutex m_MusicEffectMutex;

		std::queue<SoundData> m_SoundQueue{};
		std::condition_variable m_ConditionalVariable{};
		std::jthread m_SoundThread{};
	};
}

dae::SDLSoundSystem::SDLSoundSystemImpl::SDLSoundSystemImpl()
{
	m_SoundThread = std::jthread(&SDLSoundSystemImpl::ProcessQueue, this);
}

dae::SDLSoundSystem::SDLSoundSystemImpl::~SDLSoundSystemImpl()
{
	
	m_RunQueue = false;
	m_ConditionalVariable.notify_all();

	for (auto music : m_Music)
	{
		Mix_FreeMusic(music.second);
	}

	Mix_CloseAudio();
}

void dae::SDLSoundSystem::SDLSoundSystemImpl::Play(const SoundId id, int loops)
{
	if (m_Sounds.find(id) == m_Sounds.end()) return;

	std::lock_guard<std::mutex> lock(m_SoundMutex);
	m_SoundQueue.push({ SoundType::PlaySound, id, loops });
	m_ConditionalVariable.notify_all();

}

void dae::SDLSoundSystem::SDLSoundSystemImpl::PlayMusic(const SoundId id, int loops)
{
	if (m_Music.find(id) == m_Music.end()) return;

	std::lock_guard<std::mutex> lock(m_SoundMutex);
	m_SoundQueue.push({ SoundType::PlayMusic, id, loops });
	m_ConditionalVariable.notify_all();
}

void dae::SDLSoundSystem::SDLSoundSystemImpl::PauseMusic()
{
	if (Mix_PausedMusic() == 0) Mix_PauseMusic();
	else Mix_ResumeMusic();
}

void dae::SDLSoundSystem::SDLSoundSystemImpl::AddSound(SoundId soundId, const std::string& fileName)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cerr << "SDL_mixer could not initialize! " << Mix_GetError() << std::endl;
	}

	m_Sounds.emplace(soundId, Mix_LoadWAV(fileName.c_str()));
}

void dae::SDLSoundSystem::SDLSoundSystemImpl::AddMusic(SoundId soundId, const std::string& fileName)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cerr << "SDL_mixer could not initialize! " << Mix_GetError() << std::endl;
	}

	m_Music.emplace(soundId, Mix_LoadMUS(fileName.c_str()));
}

void dae::SDLSoundSystem::SDLSoundSystemImpl::ChangeMasterVolume(int volume)
{
	// Check if Volume is not over max
	if (volume > MIX_MAX_VOLUME)
		volume = MIX_MAX_VOLUME;

	Mix_VolumeMusic(volume);
	//for (auto chunk : m_Sounds)
	//{
	//	Mix_VolumeChunk(chunk.second, volume);
	//}
	Mix_MasterVolume(volume);
	//Mix_Mast
}

void dae::SDLSoundSystem::SDLSoundSystemImpl::ProcessQueue()
{
	while (m_RunQueue) {
		std::unique_lock<std::mutex> lock(m_SoundMutex);
		m_ConditionalVariable.wait(lock, [this] { return !m_SoundQueue.empty() || !m_RunQueue; });

		if (!m_RunQueue) {
			break;
		}

		SoundData sd = m_SoundQueue.front();
		m_SoundQueue.pop();
		lock.unlock();

		switch (sd.type)
		{
		case SoundType::PlayMusic:
		{
			if (m_Music[sd.id])
				Mix_PlayMusic(m_Music[sd.id], sd.loops);
			

			break;
		}
		case SoundType::PlaySound:
		{
			if (m_Sounds[sd.id])
				Mix_PlayChannel(-1, m_Sounds[sd.id], sd.loops);

			break;
		}
		default:
			break;
		}
	}
}

dae::SDLSoundSystem::SDLSoundSystem()
	: m_pSDLSoundSystemImpl{std::make_unique<SDLSoundSystemImpl>()}
{}

dae::SDLSoundSystem::~SDLSoundSystem()
{}

void dae::SDLSoundSystem::Play(const SoundId id, int loops)
{
	m_pSDLSoundSystemImpl->Play(id, loops);
}

void dae::SDLSoundSystem::PlayMusic(const SoundId id, int loops)
{
	m_pSDLSoundSystemImpl->PlayMusic(id, loops);
}

void dae::SDLSoundSystem::PauseMusic()
{
	m_pSDLSoundSystemImpl->PauseMusic();
}

void dae::SDLSoundSystem::AddSound(SoundId soundId, const std::string& fileName)
{
	m_pSDLSoundSystemImpl->AddSound(soundId, fileName);
}

void dae::SDLSoundSystem::AddMusic(SoundId soundId, const std::string& fileName)
{
	m_pSDLSoundSystemImpl->AddMusic(soundId, fileName);
}

void dae::SDLSoundSystem::ChangeMasterVolume(int volume)
{
	m_pSDLSoundSystemImpl->ChangeMasterVolume(volume);
}
