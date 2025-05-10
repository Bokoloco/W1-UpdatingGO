#include "MoveOnLadderCommand.h"
#include "./Components/MoveDownLadderComponent.h"
#include "GameObject.h"
#include <Minigin.h>

dae::MoveOnLadderCommand::MoveOnLadderCommand(GameObject& go, float direction)
	: Command(go)
	, m_Direction{0.f, direction, 0.f}
{
	m_pMoveDownLadderComponent = GetGameObject()->GetComponent<MoveDownLadderComponent>();
}

void dae::MoveOnLadderCommand::Execute()
{
	if (m_pMoveDownLadderComponent->CanMoveOnLadder())
	{
		glm::vec3 newPos = GetGameObject()->GetWorldPosition() + GetGameObject()->GetSpeed() * dae::Minigin::DELTATIME * m_Direction;
		if (newPos.y >= m_pMoveDownLadderComponent->GetMinHeight())
			GetGameObject()->SetLocalPosition(newPos);
	}
}
