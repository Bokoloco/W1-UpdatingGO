#include "HealthDisplayComponent.h"
#include "GameObject.h"
#include "Renderer.h"
#include "HealthObserver.h"

dae::HealthDisplayComponent::HealthDisplayComponent(GameObject& go)
	: BaseComponent(go)
{
	m_pHealthObserver = std::make_unique<HealthObserver>();
}

void dae::HealthDisplayComponent::Update()
{
	if (m_pHealthObserver->m_HasLivesChanged) m_AmountOfLives = m_pHealthObserver->GetLives();
}

void dae::HealthDisplayComponent::Render() const
{
	int offset = static_cast<int>(GetOwner()->GetBoundingBox()->h);

	for (unsigned int i{}; i < m_AmountOfLives; ++i)
	{
		if (GetOwner()->GetTexture() != nullptr) Renderer::GetInstance().RenderTexture(*GetOwner()->GetTexture(), GetOwner()->GetSourceRect(), GetOwner()->GetWorldPosition().x, GetOwner()->GetWorldPosition().y - (offset * i), GetOwner()->GetBoundingBox()->w, GetOwner()->GetBoundingBox()->h);
	}
}

dae::HealthObserver* dae::HealthDisplayComponent::GetObserver() const
{
	return m_pHealthObserver.get();
}
