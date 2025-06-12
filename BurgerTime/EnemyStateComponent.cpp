#include "EnemyStateComponent.h"
#include "EnemyStates.h"
#include <iostream>

dae::EnemyStateComponent::EnemyStateComponent(GameObject& go, GameObject& player)
	: BaseComponent(go)
{
	m_CurrentState = new PlatformState(GetOwner(), &player);
}

dae::EnemyStateComponent::~EnemyStateComponent()
{
    delete m_CurrentState;
}

void dae::EnemyStateComponent::Update()
{
    auto newState = m_CurrentState->HandleInput();
    if (newState != nullptr)
    {
        delete m_CurrentState;
        m_CurrentState = newState;

        //std::cout << "Switching states" << std::endl;

        // Call the enter action on the new state.
        m_CurrentState->OnEnter();
    }

    m_CurrentState->Update();
}
