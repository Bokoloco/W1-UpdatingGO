#include "EnemyComponent.h"
#include "GameObject.h"

dae::EnemyComponent::EnemyComponent(GameObject& go, glm::vec3 position)
	: BaseComponent(go)
	, m_POSITION{position}
{}

void dae::EnemyComponent::Update()
{
	if (ShouldReset)
	{
		GetOwner()->SetLocalPosition(m_POSITION);
		ShouldReset = false;
	}
}

