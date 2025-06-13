#include "EndLevelObserver.h"
#include "GameObject.h"
#include "Utils.h"
#include "GameManager.h"
#include <iostream>

dae::EndLevelObserver::EndLevelObserver()
{
	m_HashBurgerHitPlate = make_sdbm_hash("BurgerHitPlate");
}

void dae::EndLevelObserver::OnNotify(unsigned int eventID, GameObject*)
{
	if (eventID == m_HashBurgerHitPlate)
	{
		++m_AmountBurgersHitPlate;
		std::cout << "BurgerHitPlate: " << m_AmountBurgersHitPlate << std::endl;
		if (m_AmountBurgersHitPlate >= 1)
		{
			GameManager::GetInstance().SwitchScene(make_sdbm_hash("MainMenu"));
		}
	}
}

