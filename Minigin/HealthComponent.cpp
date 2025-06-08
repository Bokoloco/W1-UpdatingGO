#include "HealthComponent.h"

dae::HealthComponent::HealthComponent(GameObject& go)
	: BaseComponent(go)
	, m_Lives{3}
{}

void dae::HealthComponent::Update()
{}

void dae::HealthComponent::Render() const
{}

void dae::HealthComponent::DecreaseLives()
{
	--m_Lives;
	//NotifyObservers(dae::ObserverEvent::LivesDecrease);	
}