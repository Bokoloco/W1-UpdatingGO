#include "EnemyStates.h"
#include "GameObject.h"
#include "Components/MoveDownLadderComponent.h"
#include <iostream>

dae::LadderState::LadderState(GameObject* owner, GameObject* player)
	: EnemyState(owner, player)
{
	m_pMoveDownLadderComponent = GetOwner()->GetComponent<dae::MoveDownLadderComponent>();
}

dae::EnemyState* dae::LadderState::HandleInput()
{
	glm::vec3 direction = GetPlayer()->GetLocalPosition() - GetOwner()->GetLocalPosition();
	//direction = glm::normalize(direction);
	float x = std::abs(direction.x);
	float y = std::abs(direction.y);
	//float ceiledX = std::ceilf(x);

	if (m_pMoveDownLadderComponent->m_CanMoveHorizontally && x > 0.f && x > y)
		return new PlatformState(GetOwner(), GetPlayer());
	return nullptr;
}

void dae::LadderState::OnEnter()
{
	
}

void dae::LadderState::Update()
{
	glm::vec3 direction = GetPlayer()->GetLocalPosition() - GetOwner()->GetLocalPosition();
	//std::cout << "Y direction before normalize: " << direction.y << std::endl;
	direction = glm::normalize(direction);
	std::cout << "Y direction: " << direction.y << std::endl;

	if (direction.y > 0.0f) direction.y = 1.0f;
	else if (direction.y < 0.0f) direction.y = -1.0f;

	direction.x = 0.f;

	m_pMoveDownLadderComponent->SetDirection(direction);
}

dae::PlatformState::PlatformState(GameObject* owner, GameObject* player)
	: EnemyState(owner, player)
{
	m_pMoveDownLadderComponent = GetOwner()->GetComponent<dae::MoveDownLadderComponent>();
}

dae::EnemyState* dae::PlatformState::HandleInput()
{
	glm::vec3 direction = GetPlayer()->GetLocalPosition() - GetOwner()->GetLocalPosition();
	//direction = glm::normalize(direction);
	float x = std::abs(direction.x);
	float y = std::abs(direction.y);
	//float ceiledy = std::ceilf(y);

	if (m_pMoveDownLadderComponent->CanMoveOnLadder() && y > 0.f && x < y)
		return new LadderState(GetOwner(), GetPlayer());
	return nullptr;
}

void dae::PlatformState::OnEnter()
{
}

void dae::PlatformState::Update()
{
	glm::vec3 direction = GetPlayer()->GetLocalPosition() - GetOwner()->GetLocalPosition();
	//std::cout << "X direction before normalize: " << direction.x << std::endl;

	direction = glm::normalize(direction);

	std::cout << "X direction: " << direction.x << std::endl;

	if (direction.x > 0.0f) direction.x = 1.0f;
	else if (direction.x < 0.0f) direction.x = -1.0f;
	direction.y = 0.f;

	m_pMoveDownLadderComponent->SetDirection(direction);
}
