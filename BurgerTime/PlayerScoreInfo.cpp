#include "PlayerScoreInfo.h"
#include "GameObject.h"
#include "./Components/TextComponent.h"

dae::PlayerScoreInfo::PlayerScoreInfo(GameObject& go)
	: BaseComponent(go)
	, m_Score{}
{
	m_pTextComponent = GetOwner()->GetComponent<dae::TextComponent>();
	m_pTextComponent->SetText("Score: " + std::to_string(m_Score));
}

void dae::PlayerScoreInfo::OnNotify(ObserverEvent e)
{
	switch (e)
	{
	case dae::ObserverEvent::SmallScoreIncrease:
		m_Score += 10;
		break;
	case dae::ObserverEvent::BigScoreIncrease:
		m_Score += 100;
		break;
	default:
		break;
	}
	m_pTextComponent->SetText("Score: " + std::to_string(m_Score));
}
