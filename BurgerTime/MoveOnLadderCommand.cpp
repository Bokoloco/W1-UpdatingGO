#include "MoveOnLadderCommand.h"
#include "./Components/MoveDownLadderComponent.h"
#include "GameObject.h"
#include <Minigin.h>

dae::MoveOnLadderCommand::MoveOnLadderCommand(GameObject& go, glm::vec3 direction)
	: Command(go)
	, m_Direction{direction}
{
	m_pMoveDownLadderComponent = GetGameObject()->GetComponent<MoveDownLadderComponent>();
}

void dae::MoveOnLadderCommand::Execute()
{
	m_pMoveDownLadderComponent->SetDirection(m_Direction);
}