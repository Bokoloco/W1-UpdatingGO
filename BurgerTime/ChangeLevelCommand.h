#pragma once
#include <Command.h>

namespace dae
{
	class GameObject;
	class ChangeLevelCommand : public Command
	{
	public:
	public:
		ChangeLevelCommand(GameObject& go);

		void Execute() override;
	};
}