#pragma once
#include <string>

using SoundId = unsigned short;

class SoundSystem
{
public:
	virtual ~SoundSystem() = default;

	virtual void AddSound(SoundId soundId, const std::string& fileName) = 0;
	virtual void Play(const SoundId id) = 0;
};