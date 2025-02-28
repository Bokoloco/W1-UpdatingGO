#include "RotateComponent.h"
#include "GameObject.h"
#include "Minigin.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

dae::RotateComponent::RotateComponent(GameObject& go, float rotateSpeed)
	: BaseComponent(go)
	, m_RotateSpeed(rotateSpeed)
{
	m_pLocalTransform = &(GetOwner()->GetLocalTransform());
}

void dae::RotateComponent::Update()
{
	// Use matrix rotation to change position
	glm::vec4 rotation = glm::rotate(glm::mat4(1.f), glm::radians(m_RotateSpeed * dae::Minigin::DELTATIME), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::vec4(m_pLocalTransform->GetPosition(), 1.f);
	GetOwner()->SetLocalPosition({ rotation.x, rotation.y, 0.f });
}

void dae::RotateComponent::Render() const
{}
