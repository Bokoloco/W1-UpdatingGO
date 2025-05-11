#include "FoodFallingComponent.h"
#include "GameObject.h"
#include "BurgerCollisionComponent.h"

dae::FoodFallingComponent::FoodFallingComponent(GameObject& go)
	: BaseComponent(go)
{
	for (int i{}; i < GetOwner()->GetChildCount(); ++i)
	{
		if (auto casted = GetOwner()->GetChildAt(i)->GetComponent<BurgerCollisionComponent>())
		{
			m_CollisionComponents.push_back(casted);
		}
	}
}

void dae::FoodFallingComponent::Update()
{
	auto it = std::find_if(m_CollisionComponents.begin(), m_CollisionComponents.end(), [&](BurgerCollisionComponent* comp) {return !comp->HasBeenSteppedOn(); });
	if (it == m_CollisionComponents.end())
	{
		GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, GetOwner()->GetLocalPosition().y + 2.f, 0.f });
	}
}

void dae::FoodFallingComponent::Render() const
{
}