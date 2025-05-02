#pragma once
#include <Command.h>

namespace dae
{
	class PauseMusicCommand : public Command
	{
	public:
		PauseMusicCommand(GameObject& go);

		void Execute() override;
	};
}