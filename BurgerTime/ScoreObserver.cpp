#include "ScoreObserver.h"
#include <iostream>
#include "GameObject.h"
#include <Utils.h>
#include "BurgerCollisionComponent.h"

dae::ScoreObserver::ScoreObserver()
	: m_HashBurgerDropped{ dae::make_sdbm_hash("BurgerDropped") }
	, m_HashMrHotDog{ dae::make_sdbm_hash("MrHotDog") }
	, m_HashEnemiesOnBurger{ dae::make_sdbm_hash("EnemiesOnBurger") }
{}

void dae::ScoreObserver::OnNotify(unsigned int eventID, GameObject* go)
{
	if (eventID == m_HashBurgerDropped)
	{
		m_Score += 50;
		std::cout << "Score: " << m_Score << std::endl;
	}
	if (eventID == m_HashMrHotDog)
	{
		m_Score += 100;
		std::cout << "Score after dog: " << m_Score << std::endl;
	}
	if (eventID == m_HashEnemiesOnBurger)
	{
		m_Score += 250 * static_cast<int>(std::pow(2, go->GetComponent<dae::BurgerCollisionComponent>()->GetAmountOfEnemiesOnBurger()));
		std::cout << "Score when enemies: " << m_Score << std::endl;
	}

}
