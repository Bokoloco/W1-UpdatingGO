#pragma once
#include "Command.h"
#include "SoundSystem.h"

namespace dae
{
	class GameObject;
	class PlaySoundCommand : public Command
	{
	public:
		PlaySoundCommand(GameObject& go, const SoundId soundId);

		void Execute() override;

	private:
		const SoundId m_SoundId{};
	};
}
