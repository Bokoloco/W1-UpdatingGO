#include "MoveComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "Minigin.h"

dae::MoveComponent::MoveComponent(GameObject& go)
	: BaseComponent(go)
	, m_Speed{0.01f}
{
	m_pTransform = &(GetOwner()->GetWorldTransform());
}

void dae::MoveComponent::Update()
{
	float xPos = m_pTransform->GetPosition().x + m_Speed * dae::Minigin::DELTATIME;
	GetOwner()->SetWorldPosition(xPos, m_pTransform->GetPosition().y);

	if (GetOwner()->GetChildCount() != 0)
	{
		GetOwner()->SetPositionDirtyChildren();
	}
}

void dae::MoveComponent::Render() const
{}