#include "ScoreObserver.h"
#include <iostream>
#include "GameObject.h"
#include <Utils.h>

dae::ScoreObserver::ScoreObserver()
	: m_HashBurgerDropped{ dae::make_sdbm_hash("BurgerDropped") }
	, m_HashMrHotDog{ dae::make_sdbm_hash("MrHotDog") }
{}

void dae::ScoreObserver::OnNotify(unsigned int eventID, GameObject* )
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
}
