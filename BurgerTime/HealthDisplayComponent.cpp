#include "HealthDisplayComponent.h"
#include "GameObject.h"
#include "Renderer.h"
#include "HealthObserver.h"
#include "Minigin.h"
#include "GameManager.h"
#include <iostream>
#include "ServiceLocator.h"
#include "Utils.h"

dae::HealthDisplayComponent::HealthDisplayComponent(GameObject& go)
	: BaseComponent(go)
{
	m_pHealthObserver = std::make_unique<HealthObserver>();
}

void dae::HealthDisplayComponent::Update()
{
	if (m_pHealthObserver->m_HasLivesChanged)
	{
		if (m_AmountOfLives != 0)
		{
			m_ChangeCooldown = true;
			m_pHealthObserver->m_CanChangeLives = false;
		}
		m_AmountOfLives = m_pHealthObserver->GetLives();
		m_pHealthObserver->m_HasLivesChanged = false;
	}

	if (m_ChangeCooldown)
	{
		m_CoolDownBeforeReset -= dae::Minigin::DELTATIME;
		if (m_CoolDownBeforeReset <= 0.f)
		{
			m_ChangeCooldown = false;
			m_pHealthObserver->m_CanChangeLives = true;
			m_CoolDownBeforeReset = m_COOLDOWN;
			dae::GameManager::GetInstance().ResetScene();
			dae::ServiceLocator::GetSoundSystem().PlayMusic(dae::make_sdbm_hash("MainMusic"), -1);
		}
	}
}

void dae::HealthDisplayComponent::Render() const
{
	int offset = static_cast<int>(GetOwner()->GetBoundingBox()->h);

	for (unsigned int i{}; i < m_AmountOfLives; ++i)
	{
		if (GetOwner()->GetTexture() != nullptr) 
			Renderer::GetInstance().RenderTexture(*GetOwner()->GetTexture(), GetOwner()->GetSourceRect(), GetOwner()->GetWorldPosition().x, GetOwner()->GetWorldPosition().y - (offset * i), GetOwner()->GetBoundingBox()->w, GetOwner()->GetBoundingBox()->h);
	}
}

dae::HealthObserver* dae::HealthDisplayComponent::GetObserver() const
{
	return m_pHealthObserver.get();
}
