#include "ScoreComponent.h"
#include "GameObject.h"

dae::ScoreComponent::ScoreComponent(GameObject& go)
	: BaseComponent(go)
	, m_Score{0}
{ }

void dae::ScoreComponent::IncreaseScore(dae::ScoreAmount amount)
{
	m_Score += static_cast<int>(amount);
}
