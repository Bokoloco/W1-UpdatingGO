#include "EndLevelComponent.h"
#include "GameObject.h"

dae::EndLevelComponent::EndLevelComponent(GameObject& go)
	: BaseComponent(go)
{
	m_pEndLevelObserver = std::make_unique<EndLevelObserver>();
}

dae::EndLevelObserver* dae::EndLevelComponent::GetObserver() const
{
	return m_pEndLevelObserver.get();
}
