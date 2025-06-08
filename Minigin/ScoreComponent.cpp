#include "ScoreComponent.h"
#include "GameObject.h"

dae::ScoreComponent::ScoreComponent(GameObject& go)
	: BaseComponent(go)
	, m_Score{0}
{ }

void dae::ScoreComponent::IncreaseScore(dae::ScoreAmount)
{
	/*m_Score += static_cast<int>(amount);

	switch (amount)
	{
	case dae::ScoreAmount::Small:
		NotifyObservers(ObserverEvent::SmallScoreIncrease);
		break;
	case dae::ScoreAmount::Big:
		NotifyObservers(ObserverEvent::BigScoreIncrease);
		break;
	default:
		break;
	}

	if (m_Score >= 500)
		NotifyObservers(ObserverEvent::GameWon);*/
}
