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
		void NotifyObservers(unsigned int eventId, GameObject* go);

	protected:

	private:
		std::vector<Observer*> m_pObservers;
	};
}
