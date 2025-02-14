#include "FPSComponent.h"
#include "Minigin.h"
#include <iostream>

void dae::FPSComponent::Update()
{
	std::cout << dae::Minigin::DELTATIME << std::endl;
	m_CurrentFPS = static_cast<float>(1000) / dae::Minigin::DELTATIME;
}

void dae::FPSComponent::Render([[maybe_unused]] const GameObject& go) const
{}

float dae::FPSComponent::GetFPS()
{
	return m_CurrentFPS;
}
