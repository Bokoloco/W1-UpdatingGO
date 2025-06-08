#pragma once

#include <vector>
#include "Observer.h"

namespace dae
{
	class Subject
	{
	public:
		void AddObserver(Observer& observer);
		//void RemoveObserver(Observer& observer);

		friend class BurgerCollisionComponent;

	protected:
		void NotifyObservers(unsigned int eventId, GameObject* go);

	private:
		std::vector<Observer*> m_pObservers;
	};
}
