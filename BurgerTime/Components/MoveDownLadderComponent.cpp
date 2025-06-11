#include "MoveDownLadderComponent.h"
#include <iostream>
#include <glm.hpp>
#include "GameObject.h"
#include <Minigin.h>
#include <algorithm>

dae::MoveDownLadderComponent::MoveDownLadderComponent(GameObject& go, float speed)
	: BaseComponent(go)
	, m_Speed{speed}
{}

void dae::MoveDownLadderComponent::Update()
{
	if (m_CanMoveDownLadder && m_Direction.y != 0.f)
	{
		glm::vec3 newPos = GetOwner()->GetLocalPosition() + m_Speed * dae::Minigin::DELTATIME * m_Direction;
		newPos.x = m_XPosOnLadder;

		if (m_MinHeights.size() == 2)
		{
			if ((newPos.y + GetOwner()->GetBoundingBox()->h > m_MinHeights.at(0) && newPos.y + GetOwner()->GetBoundingBox()->h < m_MaxHeights.at(0)) ||
				(newPos.y + GetOwner()->GetBoundingBox()->h > m_MinHeights.at(1) && newPos.y + GetOwner()->GetBoundingBox()->h < m_MaxHeights.at(1)))
			{
				GetOwner()->SetLocalPosition(newPos);
			}
		}
		else
		{
			if (newPos.y + GetOwner()->GetBoundingBox()->h > m_MinHeights.at(0) && newPos.y + GetOwner()->GetBoundingBox()->h < m_MaxHeights.at(0))
			{
				GetOwner()->SetLocalPosition(newPos);
			}
		}

	}
	
	if (m_CanMoveHorizontally && m_Direction.x != 0.f)
	{
		glm::vec3 newPos = GetOwner()->GetLocalPosition() + m_Speed * dae::Minigin::DELTATIME * m_Direction;

		if (newPos.x < 30.f || newPos.x + GetOwner()->GetBoundingBox()->w > 446.f) return;

		if (m_YPosOnPlatform != 0.f) newPos.y = m_YPosOnPlatform;
		GetOwner()->SetLocalPosition(newPos);
	}

	m_Direction = glm::vec3{ 0.f, 0.f, 0.f };
}

void dae::MoveDownLadderComponent::SetCanMoveDownLadder(bool value)
{
	m_CanMoveDownLadder = value;
}

void dae::MoveDownLadderComponent::SetCanMoveHorizontally(bool value)
{
	m_CanMoveHorizontally = value;
}

void dae::MoveDownLadderComponent::SetMoveToHeight(float minHeight, float maxHeight)
{
	m_MaxHeight = maxHeight;
	m_MinHeight = minHeight;

	if (std::find(m_MinHeights.begin(), m_MinHeights.end(), minHeight) == m_MinHeights.end()) m_MinHeights.push_back(minHeight);
	if (std::find(m_MaxHeights.begin(), m_MaxHeights.end(), maxHeight) == m_MaxHeights.end()) m_MaxHeights.push_back(maxHeight);
	std::sort(m_MinHeights.begin(), m_MinHeights.end());
	std::sort(m_MaxHeights.begin(), m_MaxHeights.end());
}

void dae::MoveDownLadderComponent::RemoveLadderFromList(float minheight, float maxheight)
{
	if (auto it = std::find(m_MinHeights.begin(), m_MinHeights.end(), minheight); it != m_MinHeights.end())
	{
		m_MinHeights.erase(it);
	}
	if (auto it = std::find(m_MaxHeights.begin(), m_MaxHeights.end(), maxheight); it != m_MaxHeights.end())
	{
		m_MaxHeights.erase(it);
	}
}

bool dae::MoveDownLadderComponent::CanMoveOnLadder()
{
	return m_CanMoveDownLadder /*&& (GetOwner()->GetWorldPosition().y + GetOwner()->GetBoundingBox()->h < m_MaxHeight && GetOwner()->GetWorldPosition().y >= m_MinHeight)*/;
}

float dae::MoveDownLadderComponent::GetMinHeight() const
{
	return m_MinHeight;
}

void dae::MoveDownLadderComponent::SetXPosOnLadder(float xpos)
{
	m_XPosOnLadder = xpos - (GetOwner()->GetBoundingBox()->w / 2);
}

void dae::MoveDownLadderComponent::SetYPosOnPltform(float yPos)
{
	m_YPosOnPlatform = yPos - GetOwner()->GetBoundingBox()->h;
}

void dae::MoveDownLadderComponent::SetDirection(const glm::vec3& direction)
{
	m_Direction = direction;
}
