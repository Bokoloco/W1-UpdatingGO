#include "SDLSoundSystem.h"
#include <iostream>
#include <vector>
#include <mutex>

namespace dae
{
	class SDLSoundSystem::SDLSoundSystemImpl final
	{
	public:
		SDLSoundSystemImpl() = default;
		~SDLSoundSystemImpl() = default;

		void Play(const SoundId id, int loops = 0);
		void PlayMusic(const SoundId id, int loops = 0);

		void PauseMusic();

		void AddSound(SoundId soundId, const std::string& fileName);
		void AddMusic(SoundId soundId, const std::string& fileName);

		void ChangeMasterVolume(int volume);

	private:
		std::map<SoundId, Mix_Chunk*> m_Sounds{};
		std::map<SoundId, Mix_Music*> m_Music{};

		std::mutex m_SoundEffectMutex;
		std::mutex m_MusicEffectMutex;
	};
}

void dae::SDLSoundSystem::SDLSoundSystemImpl::Play(const SoundId id, int loops)
{
	if (m_Sounds.find(id) != m_Sounds.end())
		std::lock_guard<std::mutex> lg(m_SoundEffectMutex);
		if (m_Sounds[id])
			Mix_PlayChannel(-1, m_Sounds[id], loops);
}

void dae::SDLSoundSystem::SDLSoundSystemImpl::PlayMusic(const SoundId id, int loops)
{
	if (m_Music.find(id) != m_Music.end())
		std::lock_guard<std::mutex> lg(m_MusicEffectMutex);
		if (m_Music[id])
			Mix_PlayMusic(m_Music[id], loops);
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

	Mix_MasterVolume(volume);
}

dae::SDLSoundSystem::SDLSoundSystem()
	: m_pSDLSoundSystemImpl{std::make_unique<SDLSoundSystemImpl>()}
{}

dae::SDLSoundSystem::~SDLSoundSystem()
{}

void dae::SDLSoundSystem::Play(const SoundId id, int loops)
{
	std::jthread(&SDLSoundSystemImpl::Play, m_pSDLSoundSystemImpl.get(), id, loops).join();
	//m_pSDLSoundSystemImpl->Play(id, loops);
}

void dae::SDLSoundSystem::PlayMusic(const SoundId id, int loops)
{
	std::jthread(&SDLSoundSystemImpl::PlayMusic, m_pSDLSoundSystemImpl.get(), id, loops).join();
	//m_pSDLSoundSystemImpl->PlayMusic(id, loops);
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
