#include "BurgerPartsCollisionComponent.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Utils.h"
#include <iostream>
#include <ServiceLocator.h>
#include "GameManager.h"

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
		if (GameManager::GetInstance().GetCurrentGameMode() == GameMode::Versus && go.ActorHasTag(dae::make_sdbm_hash("Player2"))) return;
		float xPosCollidingPlayer = go.GetWorldPosition().x + (go.GetBoundingBox()->w / 2);
		float xPosOwner = GetOwner()->GetWorldPosition().x + GetOwner()->GetBoundingBox()->w;
		if (xPosCollidingPlayer <= xPosOwner && xPosCollidingPlayer >= GetOwner()->GetWorldPosition().x && !m_HasBeenSteppedOn && go.GetWorldPosition().y < GetOwner()->GetWorldPosition().y)
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
		}
	}
}

void dae::BurgerPartsCollisionComponent::OnEnter(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")))
	{
		m_HasBeenSteppedOn = false;

		GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, 0.f, 0.f });
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("Plate")))
	{
		m_HasBeenSteppedOn = false;
		m_HasHitPlate = true;
		GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, 0.f, 0.f });
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("Food")))
	{
		if (go.GetComponent<BurgerPartsCollisionComponent>()->HasHitPlate())
		{
			m_HasBeenSteppedOn = false;
			m_HasHitPlate = true;
			GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, 0.f, 0.f });
		}
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("Player")))
	{
		dae::ServiceLocator::GetSoundSystem().Play(dae::make_sdbm_hash("BurgerStep"));
	}
}

void dae::BurgerPartsCollisionComponent::OnExit(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")))
	{
		m_HasBeenSteppedOn = false;

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
