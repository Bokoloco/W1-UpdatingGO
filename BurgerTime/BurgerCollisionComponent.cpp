#include "BurgerCollisionComponent.h"
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
		//go.SetCanCollide(false);
		std::cout << "in Enter" << std::endl;

		m_pSubject->NotifyObservers(dae::make_sdbm_hash("BurgerDropped"), GetOwner());
		m_pFoodFallingComponent->ShouldNotFall(false);
		//GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, GetOwner()->GetLocalPosition().y + 2.f, 0.f });
	}
}

void dae::BurgerCollisionComponent::OnExit(GameObject& go)
{
	std::cout << "in exit" << std::endl;

	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")))
	{
		m_pFoodFallingComponent->ShouldNotFall(true);
		//go.SetCanCollide(true);
	}
}

void dae::BurgerCollisionComponent::AddObserver(Observer& observer)
{
	m_pSubject->AddObserver(observer);
}
