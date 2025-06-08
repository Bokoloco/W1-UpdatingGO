#include "BurgerPartsCollisionComponent.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Utils.h"
#include <iostream>

dae::BurgerPartsCollisionComponent::BurgerPartsCollisionComponent(GameObject& go, int idx)
	: CollisionComponent(go)
	, m_idx{idx}
{}

void dae::BurgerPartsCollisionComponent::Update()
{
}

void dae::BurgerPartsCollisionComponent::Render() const
{

}

void dae::BurgerPartsCollisionComponent::OnColliding(GameObject& go)
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
	if (go.ActorHasTag(dae::make_sdbm_hash("Food")))
	{
		if (!go.GetComponent<BurgerPartsCollisionComponent>()->HasHitPlate())
		{
			if (go.GetWorldPosition().y < GetOwner()->GetWorldPosition().y)
			{
				m_HasBeenSteppedOn = true;
				GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, 8.f, 0.f });
			}
			if (go.GetWorldPosition().y > GetOwner()->GetWorldPosition().y)
			{
				m_HasBeenSteppedOn = false;
			}
		}
		else
		{
			m_HasBeenSteppedOn = false;
			m_HasHitPlate = true;
			//GetOwner()->GetParent()->SetLocalPosition({ GetOwner()->GetParent()->GetLocalPosition().x, GetOwner()->GetParent()->GetLocalPosition().y + 1.f, 0.f });
		}
	}
	//if (go.ActorHasTag(dae::make_sdbm_hash("Plate")))
	//{
	//	m_HasBeenSteppedOn = false;
	//}
	//if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")) /*|| go.ActorHasTag(dae::make_sdbm_hash("Ladder"))*/)
	//{
	//	m_HasBeenSteppedOn = false;
	//	if (m_idx == 3 && go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform"))) go.SetCanCollide(false);
	//	GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, 0.f, 0.f });
	//}
}

void dae::BurgerPartsCollisionComponent::OnEnter(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")) /*|| go.ActorHasTag(dae::make_sdbm_hash("Ladder"))*/)
	{
		m_HasBeenSteppedOn = false;

		//if (m_idx == 3) go.SetCanCollide(false);
		GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, 0.f, 0.f });
		//GetOwner()->GetParent()->SetLocalPosition({ GetOwner()->GetParent()->GetLocalPosition().x, GetOwner()->GetParent()->GetLocalPosition().y + 1.f, 0.f });
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("Plate")))
	{
		m_HasBeenSteppedOn = false;
		m_HasHitPlate = true;
		GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, 0.f, 0.f });
	}
}

void dae::BurgerPartsCollisionComponent::OnExit(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")))
	{

		GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, 0.f, 0.f });
	}
}

bool dae::BurgerPartsCollisionComponent::HasBeenSteppedOn() const
{
	return m_HasBeenSteppedOn && !m_HasHitPlate;
}

bool dae::BurgerPartsCollisionComponent::HasHitPlate() const
{
	return m_HasHitPlate;
}
