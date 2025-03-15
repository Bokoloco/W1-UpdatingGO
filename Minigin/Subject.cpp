#include "Subject.h"
#include "Observer.h"

void dae::Subject::AddObserver(Observer& observer)
{
	m_pObservers.push_back((&observer));
}

//void dae::Subject::RemoveObserver(Observer& observer)
//{
//	//m_pObservers.erase();
//}

void dae::Subject::NotifyObservers(dae::ObserverEvent e)
{
	for (Observer* observer : m_pObservers)
	{
		observer->OnNotify(e);
	}
}