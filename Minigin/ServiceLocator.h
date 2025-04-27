#pragma once
#include <memory>
#include "SoundSystem.h"

class NullSoundSystem final : public SoundSystem
{
	void Play(const SoundId) override {}
	void AddSound(SoundId, const std::string&) override {};
};

class ServiceLocator final
{
	static std::unique_ptr<SoundSystem> m_ss_instance;
public:
	static SoundSystem& GetSoundSystem() { return *m_ss_instance.get(); }
	static void RegisterSoundSystem(std::unique_ptr<SoundSystem>&& ss) { m_ss_instance = ss == nullptr ? std::make_unique<NullSoundSystem>() : std::move(ss); }
};