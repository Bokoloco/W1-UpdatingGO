#include "ScoreDisplayComponent.h"
#include <Observer.h>


dae::ScoreDisplayComponent::ScoreDisplayComponent(GameObject& go)
	: BaseComponent(go)
{
	m_pScoreObserver = std::make_unique<ScoreObserver>();
}

void dae::ScoreDisplayComponent::Update()
{

}

dae::ScoreObserver* dae::ScoreDisplayComponent::GetObserver() const
{
	return m_pScoreObserver.get();
}
