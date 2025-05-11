#include "FallingState.h"
#include "GameObject.h"
#include "Minigin.h"

dae::FallingState::FallingState(float speed)
	: m_Speed {speed}
{}

void dae::FallingState::Update(GameObject* go)
{
	go->SetLocalPosition({ go->GetLocalPosition().x, go->GetLocalPosition().y + m_Speed * dae::Minigin::DELTATIME, 0.f });
}