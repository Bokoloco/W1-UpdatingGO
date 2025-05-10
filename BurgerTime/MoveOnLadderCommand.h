#pragma once
#include "Command.h"
#include "glm.hpp"

namespace dae
{
	class MoveDownLadderComponent;
	class GameObject;
	class MoveOnLadderCommand : public Command
	{
	public:
		MoveOnLadderCommand(GameObject& go, float direction);

		void Execute() override;

	private:
		MoveDownLadderComponent* m_pMoveDownLadderComponent{};

		glm::vec3 m_Direction{};
	};
}