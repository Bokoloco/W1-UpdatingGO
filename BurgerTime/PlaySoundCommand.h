#pragma once
#include "Command.h"

namespace dae
{
	class GameObject;
	class PlaySoundCommand : public Command
	{
	public:
		PlaySoundCommand(GameObject& go);

		void Execute() override;

	private:

	};
}
