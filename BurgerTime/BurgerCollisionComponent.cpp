#include "BurgerCollisionComponent.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Utils.h"

dae::BurgerCollisionComponent::BurgerCollisionComponent(GameObject& go)
	: CollisionComponent(go)
{}

void dae::BurgerCollisionComponent::Update()
{
}

void dae::BurgerCollisionComponent::Render() const
{

}

void dae::BurgerCollisionComponent::OnColliding(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("Player")))
	{
		float xPosCollidingPlayer = go.GetWorldPosition().x + (go.GetBoundingBox()->w / 2);
		float xPosOwner = GetOwner()->GetWorldPosition().x + GetOwner()->GetBoundingBox()->w;
		if (xPosCollidingPlayer <= xPosOwner && xPosCollidingPlayer >= GetOwner()->GetWorldPosition().x && !m_HasBeenSteppedOn)
		{
			m_HasBeenSteppedOn = true;
			GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, GetOwner()->GetLocalPosition().y + 3.f, 0.f });
		}
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")))
	{
		m_HasBeenSteppedOn = false;
		go.SetCanCollide(false);
		//GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, 0.f, 0.f });
	}
}

bool dae::BurgerCollisionComponent::HasBeenSteppedOn() const
{
	return m_HasBeenSteppedOn;
}
