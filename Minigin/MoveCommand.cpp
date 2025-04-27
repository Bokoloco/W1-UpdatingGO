#include "MoveCommand.h"
#include "GameObject.h"
#include "Minigin.h"

dae::MoveCommand::MoveCommand(GameObject& go, glm::vec3 direction)
	: Command(go)
	, m_Direction {direction}
{}

void dae::MoveCommand::Execute()
{
	glm::vec3 newPos = GetGameObject()->GetWorldPosition() + GetGameObject()->GetSpeed() * dae::Minigin::DELTATIME * m_Direction;
	GetGameObject()->SetLocalPosition(newPos);
}