#include "ScoreObserver.h"
#include <iostream>
#include "GameObject.h"
#include <Utils.h>

dae::ScoreObserver::ScoreObserver()
	: m_HashBurgerDropped{ dae::make_sdbm_hash("BurgerDropped") }
{}

void dae::ScoreObserver::OnNotify(unsigned int eventID, GameObject* )
{
	if (eventID == m_HashBurgerDropped)
	{
		std::cout << "+ 50" << std::endl;
	}
}
