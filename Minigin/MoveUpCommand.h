#pragma once
#include "Command.h"

namespace dae
{
	class GameObject;
	class MoveUpCommand : public Command
	{
	public:
		MoveUpCommand() = default;
		~MoveUpCommand() = default;

		void Execute(GameObject& go) override;
	};
}