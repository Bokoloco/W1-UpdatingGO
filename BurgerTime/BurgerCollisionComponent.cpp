#include "BurgerCollisionComponent.h"
#include "BurgerPartsCollisionComponent.h"
#include "Subject.h"
#include "Observer.h"
#include "GameObject.h"
#include <Utils.h>
#include <iostream>
#include "FoodFallingComponent.h"
#include <ServiceLocator.h>
#include "EnemyComponent.h"
#include "./Components/MoveDownLadderComponent.h"

dae::BurgerCollisionComponent::BurgerCollisionComponent(GameObject& go)
	: CollisionComponent(go)
{
	m_pSubject = std::make_unique<Subject>();
	m_pFoodFallingComponent = GetOwner()->GetComponent<dae::FoodFallingComponent>();
}

void dae::BurgerCollisionComponent::OnColliding(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("Enemy")))
	{
		if (m_pFoodFallingComponent->IsFalling())
		{
			go.SetLocalPosition({ go.GetLocalPosition().x, GetOwner()->GetLocalPosition().y + (GetOwner()->GetBoundingBox()->h / 2) - go.GetBoundingBox()->h, 0.f });
		}
	}
}

void dae::BurgerCollisionComponent::OnEnter(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")))
	{
		if (!m_JustSpawned)
		{
			if (m_AmountOfEnemiesOnBurger == 0)
			{
				m_pFoodFallingComponent->ShouldNotFall(false);

				if (m_AmountOfEnemiesOnBurgerForScore != 0)
				{
					m_pSubject->NotifyObservers(dae::make_sdbm_hash("EnemiesOnBurger"), GetOwner());
					m_AmountOfEnemiesOnBurgerForScore = 0;
				}
				else m_pSubject->NotifyObservers(dae::make_sdbm_hash("BurgerDropped"), GetOwner());

				GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, go.GetLocalPosition().y - (GetOwner()->GetBoundingBox()->h / 2), 0.f });
			}
			else
			{
				--m_AmountOfEnemiesOnBurger;
			}

			dae::ServiceLocator::GetSoundSystem().Play(dae::make_sdbm_hash("BurgerLand"));
		}
		else
			m_JustSpawned = false;
	}

	if (go.ActorHasTag(dae::make_sdbm_hash("Food")))
	{
		if (go.GetComponent<BurgerPartsCollisionComponent>()->HasHitPlate() && go.GetWorldPosition().y > GetOwner()->GetWorldPosition().y && m_pFoodFallingComponent->IsFalling())
		{
			m_pFoodFallingComponent->ShouldNotFall(false);

			if (m_AmountOfEnemiesOnBurgerForScore != 0)
			{
				m_pSubject->NotifyObservers(dae::make_sdbm_hash("EnemiesOnBurger"), GetOwner());
				m_AmountOfEnemiesOnBurgerForScore = 0;
			}
			else m_pSubject->NotifyObservers(dae::make_sdbm_hash("BurgerDropped"), GetOwner());

			dae::ServiceLocator::GetSoundSystem().Play(dae::make_sdbm_hash("BurgerLand"));
		}
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("FoodParent")))
	{
		if (go.GetWorldPosition().y > GetOwner()->GetWorldPosition().y && m_pFoodFallingComponent->IsFalling())
		{
			go.GetComponent<dae::BurgerCollisionComponent>()->ResetAmountOfEnemiesOnBurger();
		}
	}

	if (go.ActorHasTag(dae::make_sdbm_hash("Plate")))
	{
		m_pFoodFallingComponent->ShouldNotFall(false);
		m_pSubject->NotifyObservers(dae::make_sdbm_hash("BurgerDropped"), GetOwner());
		dae::ServiceLocator::GetSoundSystem().Play(dae::make_sdbm_hash("BurgerLand"));
		GetOwner()->SetLocalPosition({ GetOwner()->GetLocalPosition().x, GetOwner()->GetLocalPosition().y + 6.f, 0.f });
	}

	if (go.ActorHasTag(dae::make_sdbm_hash("MrHotDog")) && go.GetWorldPosition().y >= GetOwner()->GetWorldPosition().y)
	{
		if (!m_pFoodFallingComponent->IsFalling()) return;
		m_pSubject->NotifyObservers(dae::make_sdbm_hash("MrHotDog"), GetOwner());
		go.GetComponent<dae::EnemyComponent>()->ShouldReset = true;
		go.GetComponent<dae::MoveDownLadderComponent>()->ResetComponent();
	}

	if (go.ActorHasTag(dae::make_sdbm_hash("MrEgg")) && go.GetWorldPosition().y >= GetOwner()->GetWorldPosition().y)
	{
		if (!m_pFoodFallingComponent->IsFalling()) return;
		m_pSubject->NotifyObservers(dae::make_sdbm_hash("MrEgg"), GetOwner());
		go.GetComponent<dae::EnemyComponent>()->ShouldReset = true;
		go.GetComponent<dae::MoveDownLadderComponent>()->ResetComponent();
	}

	if (go.ActorHasTag(dae::make_sdbm_hash("MrPickle")) && go.GetWorldPosition().y >= GetOwner()->GetWorldPosition().y)
	{
		if (!m_pFoodFallingComponent->IsFalling()) return;
		m_pSubject->NotifyObservers(dae::make_sdbm_hash("MrPickle"), GetOwner());
		go.GetComponent<dae::EnemyComponent>()->ShouldReset = true;
		go.GetComponent<dae::MoveDownLadderComponent>()->ResetComponent();
	}

	if (go.ActorHasTag(dae::make_sdbm_hash("Enemy")) && !m_pFoodFallingComponent->IsFalling())
	{
		++m_AmountOfEnemiesOnBurger;
		++m_AmountOfEnemiesOnBurgerForScore;
		std::cout << "Amount on burgers: " << m_AmountOfEnemiesOnBurger << std::endl;
	}
}

void dae::BurgerCollisionComponent::OnExit(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("BurgerPlatform")) || go.ActorHasTag(dae::make_sdbm_hash("Plate")))
	{
		m_pFoodFallingComponent->ShouldNotFall(true);
	}

	if (go.ActorHasTag(dae::make_sdbm_hash("Enemy")) && !m_pFoodFallingComponent->IsFalling())
	{
		--m_AmountOfEnemiesOnBurger;
		--m_AmountOfEnemiesOnBurgerForScore;
		go.SetLocalPosition({ go.GetLocalPosition().x, GetOwner()->GetLocalPosition().y + (GetOwner()->GetBoundingBox()->h / 2) - go.GetBoundingBox()->h, 0.f });
	}
}

void dae::BurgerCollisionComponent::AddObserver(Observer& observer)
{
	m_pSubject->AddObserver(observer);
}

int dae::BurgerCollisionComponent::GetAmountOfEnemiesOnBurger() const
{
	return m_AmountOfEnemiesOnBurgerForScore;
}

void dae::BurgerCollisionComponent::ResetAmountOfEnemiesOnBurger()
{
	m_AmountOfEnemiesOnBurger = 0;
	m_AmountOfEnemiesOnBurgerForScore = 0;
}
