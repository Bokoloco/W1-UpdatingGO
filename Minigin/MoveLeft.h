#pragma once

#include "Command.h"

namespace dae
{
	class GameObject;
	class MoveLeft final : public Command
	{
	public:
		MoveLeft();
		~MoveLeft() = default;

		void Execute(GameObject& go) override;

	private:
		float m_Speed;
	};
}