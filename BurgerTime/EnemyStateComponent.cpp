#include "EnemyStateComponent.h"
#include "EnemyStates.h"
#include <iostream>

dae::EnemyStateComponent::EnemyStateComponent(GameObject& go, GameObject& player)
	: BaseComponent(go)
{
	m_CurrentState = std::make_unique<PlatformState>(GetOwner(), &player);
}

dae::EnemyStateComponent::~EnemyStateComponent()
{
    //delete m_CurrentState;
}

void dae::EnemyStateComponent::Update()
{
    auto newState = m_CurrentState->HandleInput();
    if (newState != nullptr)
    {
        m_CurrentState.reset();
        m_CurrentState = std::move(newState);

        m_CurrentState->OnEnter();
    }

    m_CurrentState->Update();
}
