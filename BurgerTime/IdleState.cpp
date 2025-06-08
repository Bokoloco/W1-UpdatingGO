#include "IdleState.h"
#include "GameObject.h"

void dae::IdleState::OnEnter(GameObject* go)
{
	go->SetLocalPosition({ go->GetLocalPosition().x, go->GetLocalPosition().y + 5.f, 0.f });
}