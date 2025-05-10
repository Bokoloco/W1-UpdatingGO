#include "MoveDownLadderComponent.h"
#include <iostream>
#include <glm.hpp>
#include "GameObject.h"
#include <Minigin.h>

dae::MoveDownLadderComponent::MoveDownLadderComponent(GameObject& go)
	: BaseComponent(go)
{}

void dae::MoveDownLadderComponent::SetCanMoveDownLadder(bool value)
{
	m_CanMoveDownLadder = value;
}

void dae::MoveDownLadderComponent::SetMoveToHeight(float value)
{
	m_MaxHeight = value;
	m_MinHeight = GetOwner()->GetWorldPosition().y;
}

bool dae::MoveDownLadderComponent::CanMoveOnLadder()
{
	return m_CanMoveDownLadder && GetOwner()->GetWorldPosition().y < m_MaxHeight && GetOwner()->GetWorldPosition().y >= m_MinHeight;
}

float dae::MoveDownLadderComponent::GetMinHeight() const
{
	return m_MinHeight;
}
