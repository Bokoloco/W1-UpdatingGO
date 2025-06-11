#include "FoodFallingComponent.h"
#include "GameObject.h"
#include "BurgerPartsCollisionComponent.h"
#include <Minigin.h>
#include "Renderer.h"


dae::FoodFallingComponent::FoodFallingComponent(GameObject& go, float speed)
	: BaseComponent(go)
	, m_Speed{speed}
{
	for (int i{}; i < GetOwner()->GetChildCount(); ++i)
	{
		if (auto casted = GetOwner()->GetChildAt(i)->GetComponent<BurgerPartsCollisionComponent>())
		{
			m_CollisionComponents.push_back(casted);
		}
	}
}

void dae::FoodFallingComponent::Update()
{
	auto it = std::find_if(m_CollisionComponents.begin(), m_CollisionComponents.end(), [&](BurgerPartsCollisionComponent* comp) {return !comp->HasBeenSteppedOn(); });
	if (it == m_CollisionComponents.end() || m_ShouldFall)
	{
		m_ShouldFall = true;
		GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, GetOwner()->GetLocalPosition().y + m_Speed * dae::Minigin::DELTATIME, 0.f });
	}
}

void dae::FoodFallingComponent::Render() const
{
	//SDL_SetRenderDrawColor(Renderer::GetInstance().GetSDLRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	//SDL_RenderDrawRectF(Renderer::GetInstance().GetSDLRenderer(), GetOwner()->GetBoundingBox());
}

void dae::FoodFallingComponent::ShouldNotFall(bool value)
{
	m_ShouldFall = value;
}

bool dae::FoodFallingComponent::IsFalling()
{
	return m_ShouldFall;
}
