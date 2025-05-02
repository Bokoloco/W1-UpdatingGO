#pragma once
#include <memory>
#include "SoundSystem.h"

namespace dae
{
	class NullSoundSystem final : public SoundSystem
	{
		void Play(const SoundId, int = 0) override {};
		void PlayMusic(const SoundId, int = 0) override {};
		void PauseMusic() override {};
		void AddSound(SoundId, const std::string&) override {};
		void AddMusic(SoundId, const std::string&) override {};
		void ChangeMasterVolume(int) override {};
	};

	class ServiceLocator final
	{
		static std::unique_ptr<SoundSystem> m_ss_instance;
	public:
		static SoundSystem& GetSoundSystem() { return *m_ss_instance.get(); }
		static void RegisterSoundSystem(std::unique_ptr<SoundSystem>&& ss) { m_ss_instance = ss == nullptr ? std::make_unique<NullSoundSystem>() : std::move(ss); }
	};
}