#include "DecreaseLivesCommand.h"
#include "Utils.h"

dae::DecreaseLivesCommand::DecreaseLivesCommand(GameObject& go)
	: Command(go)
{
	m_pSubject = std::make_unique<Subject>();
}

void dae::DecreaseLivesCommand::Execute()
{
	m_pSubject->NotifyObservers(dae::make_sdbm_hash("LowerHealth"), GetGameObject());
}

void dae::DecreaseLivesCommand::AddObserver(Observer& observer)
{
	m_pSubject->AddObserver(observer);
}
