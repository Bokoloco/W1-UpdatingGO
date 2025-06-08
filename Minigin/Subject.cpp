#include "Subject.h"
#include "Observer.h"
#include "GameObject.h"

void dae::Subject::AddObserver(Observer& observer)
{
	m_pObservers.push_back((&observer));
}

//void dae::Subject::RemoveObserver(Observer& observer)
//{
//	//m_pObservers.erase();
//}

void dae::Subject::NotifyObservers(unsigned int eventId, GameObject* go)
{
	for (Observer* observer : m_pObservers)
	{
		observer->OnNotify(eventId, go);
	}
}