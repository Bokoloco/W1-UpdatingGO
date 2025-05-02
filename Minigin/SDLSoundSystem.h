#pragma once
#include "SDL_mixer.h"
#include "SoundSystem.h"
#include <string>
#include <map>
#include <memory>

namespace dae
{
	class SDLSoundSystem final : public SoundSystem
	{
	private:
		class SDLSoundSystemImpl;
		std::unique_ptr<SDLSoundSystemImpl> m_pSDLSoundSystemImpl;

	public:
		SDLSoundSystem();
		~SDLSoundSystem();

		void Play(const SoundId id, int loops = 0) override;
		void PlayMusic(const SoundId id, int loops = 0) override;

		void PauseMusic() override;

		void AddSound(SoundId soundId, const std::string& fileName) override;
		void AddMusic(SoundId soundId, const std::string& fileName) override;

		void ChangeMasterVolume(int volume) override;
	};
}