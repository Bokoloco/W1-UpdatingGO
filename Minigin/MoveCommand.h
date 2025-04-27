#pragma once
#include "Command.h"
#include <glm.hpp>

namespace dae
{
	class GameObject;
	class MoveCommand : public Command
	{
	public:
		MoveCommand(GameObject& go, glm::vec3 direction);


		void Execute() override;

	private:
		glm::vec3 m_Direction;
	};
}

