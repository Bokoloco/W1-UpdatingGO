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

	protected:
		void NotifyObservers(ObserverEvent e);

	private:
		std::vector<Observer*> m_pObservers;
	};
}
