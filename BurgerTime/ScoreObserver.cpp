#include "ScoreObserver.h"
#include <iostream>
#include "GameObject.h"

void dae::ScoreObserver::OnNotify(unsigned int eventID, GameObject* )
{
	if (eventID == m_HashBurgerDropped)
	{
		std::cout << "+ 50" << std::endl;
	}
}
