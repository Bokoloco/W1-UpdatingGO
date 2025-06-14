#pragma once

#include <vector>
#include "Observer.h"

namespace dae
{
	class Subject final
	{
	public:
		Subject() = default;
		~Subject() = default;

		Subject(const Subject& other) = delete;
		Subject(Subject&& other) = delete;
		Subject& operator=(const Subject& other) = default;
		Subject& operator=(Subject&& other) = default;

		void AddObserver(Observer& observer);
		//void RemoveObserver(Observer& observer);
		void NotifyObservers(unsigned int eventId, GameObject* go);

	protected:

	private:
		std::vector<Observer*> m_pObservers;
	};
}
