#pragma once

#include "Command.h"

namespace dae
{
	class GameObject;
	class MoveLeft final : public Command
	{
	public:
		MoveLeft() = default;
		~MoveLeft() = default;

		void Execute(GameObject& go) override;
	};
}