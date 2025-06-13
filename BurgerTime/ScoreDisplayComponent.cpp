#include "ScoreDisplayComponent.h"
#include <Observer.h>
#include "GameObject.h"
#include "Components/TextComponent.h"
#include "Minigin.h"
#include <iostream>

dae::ScoreDisplayComponent::ScoreDisplayComponent(GameObject& go)
	: BaseComponent(go)
{
	m_pScoreObserver = std::make_unique<ScoreObserver>();
	m_pTextComponent = GetOwner()->GetComponent<dae::TextComponent>();
}

void dae::ScoreDisplayComponent::Update()
{
	if (m_pScoreObserver->m_HasScoreChanged)
	{
		m_Score = m_pScoreObserver->GetScore();
		m_pScoreObserver->m_HasScoreChanged = false;

		std::ostringstream oss;
		oss << std::fixed << std::setprecision(1) << (m_Score);

		m_pTextComponent->SetText(oss.str());
	}
}

void dae::ScoreDisplayComponent::Render() const
{

}

dae::ScoreObserver* dae::ScoreDisplayComponent::GetObserver() const
{
	return m_pScoreObserver.get();
}
