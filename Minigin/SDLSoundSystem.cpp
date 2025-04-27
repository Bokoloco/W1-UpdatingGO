#include "SDLSoundSystem.h"
#include <iostream>

class SDLSoundSystem::SDLSoundSystemImpl final
{
public:
	SDLSoundSystemImpl() = default;
	~SDLSoundSystemImpl() = default;

	void Play(const SoundId id);
	void AddSound(SoundId soundId, const std::string& fileName);

private:
	std::map<SoundId, Mix_Chunk*> m_Sounds{};

};

void SDLSoundSystem::SDLSoundSystemImpl::Play(const SoundId id)
{
	if (m_Sounds.find(id) != m_Sounds.end())
	{
		Mix_PlayChannel(-1, m_Sounds[id], 0);
	}
}

void SDLSoundSystem::SDLSoundSystemImpl::AddSound(SoundId soundId, const std::string& fileName)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cerr << "SDL_mixer could not initialize! " << Mix_GetError() << std::endl;
	}

	auto test = Mix_LoadWAV(fileName.c_str());
	m_Sounds.emplace(soundId, test);
}

SDLSoundSystem::SDLSoundSystem()
	: m_pSDLSoundSystemImpl{std::make_unique<SDLSoundSystemImpl>()}
{
}

SDLSoundSystem::~SDLSoundSystem()
{
	//delete m_pSDLSoundSystemImpl;
}

void SDLSoundSystem::Play(const SoundId id)
{
	m_pSDLSoundSystemImpl->Play(id);
}

void SDLSoundSystem::AddSound(SoundId soundId, const std::string& fileName)
{
	m_pSDLSoundSystemImpl->AddSound(soundId, fileName);
}