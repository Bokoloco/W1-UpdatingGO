#include "Transform.h"

void dae::Transform::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void dae::Transform::SetPosition(const glm::vec3 pos)
{
	SetPosition(pos.x, pos.y, pos.z);
}

void dae::Transform::SetScaling(float x, float y, float z)
{
	m_Scaling.x = x;
	m_Scaling.y = y;
	m_Scaling.z = z;
}

void dae::Transform::SetScaling(const glm::vec3 scale)
{
	SetScaling(scale.x, scale.y, scale.z);
}