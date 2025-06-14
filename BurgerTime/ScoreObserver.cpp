#include "ScoreObserver.h"
#include <iostream>
#include "GameObject.h"
#include <Utils.h>
#include "BurgerCollisionComponent.h"

dae::ScoreObserver::ScoreObserver()
	: m_HashBurgerDropped{ dae::make_sdbm_hash("BurgerDropped") }
	, m_HashMrHotDog{ dae::make_sdbm_hash("MrHotDog") }
	, m_HashMrEgg{ dae::make_sdbm_hash("MrEgg") }
	, m_HashMrPickle{ dae::make_sdbm_hash("MrPickle") }
	, m_HashEnemiesOnBurger{ dae::make_sdbm_hash("EnemiesOnBurger") }
{}

void dae::ScoreObserver::OnNotify(unsigned int eventID, GameObject* go)
{
	if (eventID == m_HashBurgerDropped)
	{
		m_Score += 50;
	}
	if (eventID == m_HashMrHotDog)
	{
		m_Score += 100;
	}
	if (eventID == m_HashMrPickle)
	{
		m_Score += 200;
	}
	if (eventID == m_HashMrEgg)
	{
		m_Score += 300;
	}
	if (eventID == m_HashEnemiesOnBurger)
	{
		m_Score += 250 * static_cast<int>(std::pow(2, go->GetComponent<dae::BurgerCollisionComponent>()->GetAmountOfEnemiesOnBurger()));
	}
	m_HasScoreChanged = true;
}

unsigned int dae::ScoreObserver::GetScore() const
{
	return m_Score;
}
