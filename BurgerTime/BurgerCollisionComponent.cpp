#include "BurgerCollisionComponent.h"
#include "BurgerPartsCollisionComponent.h"
#include "Subject.h"
#include "Observer.h"
#include "GameObject.h"
#include <Utils.h>
#include <iostream>
#include "FoodFallingComponent.h"

dae::BurgerCollisionComponent::BurgerCollisionComponent(GameObject& go)
	: CollisionComponent(go)
{
	m_pSubject = std::make_unique<Subject>();
	m_pFoodFallingComponent = GetOwner()->GetComponent<dae::FoodFallingComponent>();
}

void dae::BurgerCollisionComponent::OnColliding(GameObject& go)
{

	if (go.ActorHasTag(dae::make_sdbm_hash("Player")))
	{
	}
}

void dae::BurgerCollisionComponent::OnEnter(GameObject& go)
{

	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")))
	{
		if (!m_JustSpawned)
		{
			m_pSubject->NotifyObservers(dae::make_sdbm_hash("BurgerDropped"), GetOwner());
			m_pFoodFallingComponent->ShouldNotFall(false);
		}
		else
			m_JustSpawned = false;
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("Food")))
	{
		if (go.GetComponent<BurgerPartsCollisionComponent>()->HasHitPlate())
			m_pSubject->NotifyObservers(dae::make_sdbm_hash("BurgerDropped"), GetOwner());

	}
	if (go.ActorHasTag(dae::make_sdbm_hash("Plate")))
	{
		m_pFoodFallingComponent->ShouldNotFall(false);
		m_pSubject->NotifyObservers(dae::make_sdbm_hash("BurgerDropped"), GetOwner());
		GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, GetOwner()->GetLocalPosition().y + 5.f, 0.f });
	}
}

void dae::BurgerCollisionComponent::OnExit(GameObject& go)
{
	std::cout << "in exit" << std::endl;

	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")) || go.ActorHasTag(dae::make_sdbm_hash("Plate")))
	{
		m_pFoodFallingComponent->ShouldNotFall(true);
	}
}

void dae::BurgerCollisionComponent::AddObserver(Observer& observer)
{
	m_pSubject->AddObserver(observer);
}
