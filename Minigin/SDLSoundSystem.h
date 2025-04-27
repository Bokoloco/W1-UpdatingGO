#pragma once
#include "SDL_mixer.h"
#include "SoundSystem.h"
#include <string>
#include <map>
#include <memory>

class SDLSoundSystem final : public SoundSystem
{
private:
	class SDLSoundSystemImpl;
	std::unique_ptr<SDLSoundSystemImpl> m_pSDLSoundSystemImpl;

public:
	SDLSoundSystem();
	~SDLSoundSystem();

	void Play(const SoundId id) override;
	void AddSound(SoundId soundId, const std::string& fileName) override;
};

