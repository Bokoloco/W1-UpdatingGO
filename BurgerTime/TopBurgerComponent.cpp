#include "TopBurgerComponent.h"
#include "Subject.h"
#include "GameObject.h"
#include "BurgerPartsCollisionComponent.h"
#include "Utils.h"
#include "Observer.h"
#include <iostream>

dae::TopBurgerComponent::TopBurgerComponent(GameObject& go)
	: BaseComponent(go)
{
	for (int i{}; i < GetOwner()->GetChildCount(); ++i)
	{
		if (auto casted = GetOwner()->GetChildAt(i)->GetComponent<BurgerPartsCollisionComponent>())
		{
			m_CollisionComponents.push_back(casted);
		}
	}
	m_pSubject = std::make_unique<dae::Subject>();
}

void dae::TopBurgerComponent::Update()
{
	auto it = std::find_if(m_CollisionComponents.begin(), m_CollisionComponents.end(), [&](BurgerPartsCollisionComponent* comp) {return !comp->HasHitPlate(); });
	if (it == m_CollisionComponents.end() && !m_HasHitPlate)
	{
		std::cout << "In if" << std::endl;
		m_pSubject->NotifyObservers(make_sdbm_hash("BurgerHitPlate"), GetOwner());
		m_HasHitPlate = true;
	}
}

void dae::TopBurgerComponent::AddObserver(Observer& observer)
{
	m_pSubject->AddObserver(observer);
}

void dae::TopBurgerComponent::NotifyObserver(unsigned int id, GameObject* go)
{
	m_pSubject->NotifyObservers(id, go);
}

