#pragma once
#include "Command.h"

namespace dae
{
	class GameObject;
	class MoveRightCommand : public Command
	{
	public:
		MoveRightCommand() = default;
		~MoveRightCommand() = default;

		void Execute(GameObject& go) override;
	};
}