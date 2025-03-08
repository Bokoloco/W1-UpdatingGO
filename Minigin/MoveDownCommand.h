#pragma once
#include "Command.h"

namespace dae
{
	class GameObject;
	class MoveDownCommand : public Command
	{
	public:
		MoveDownCommand();
		~MoveDownCommand() = default;

		void Execute(GameObject& go) override;

	private:
		float m_Speed;
	};
}