#include "FPSComponent.h"
#include "Minigin.h"
#include <iostream>
#include "TextComponent.h"

dae::FPSComponent::FPSComponent(GameObject& go, TextComponent& tc)
	: BaseComponent(go)
	, m_pTextComponent{&tc}
{}

void dae::FPSComponent::Update()
{
	m_CurrentFPS = static_cast<float>(1000) / dae::Minigin::DELTATIME;

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << (m_CurrentFPS);

	m_pTextComponent->SetText(oss.str() + " FPS");
}

void dae::FPSComponent::Render() const
{}

float dae::FPSComponent::GetFPS()
{
	return m_CurrentFPS;
}