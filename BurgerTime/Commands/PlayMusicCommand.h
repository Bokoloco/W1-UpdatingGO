#pragma once
#include <Command.h>
#include "SoundSystem.h"

namespace dae
{
	class PlayMusicCommand final : public Command
	{
	public:
		PlayMusicCommand(GameObject& go, const SoundId soundId);

		void Execute() override;

	private:
		const SoundId m_SoundId{};
	};
}