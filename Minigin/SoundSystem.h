#pragma once
#include <string>

namespace dae
{
	using SoundId = unsigned int;
	class SoundSystem
	{
	public:
		virtual ~SoundSystem() = default;

		virtual void AddSound(SoundId soundId, const std::string& fileName) = 0;
		virtual void AddMusic(SoundId soundId, const std::string& fileName) = 0;

		virtual void ChangeMasterVolume(int volume) = 0;

		virtual void Play(const SoundId id, int loops = 0) = 0;
		virtual void PlayMusic(const SoundId id, int loops = 0) = 0;

		virtual void PauseMusic() = 0;
		
	};
}