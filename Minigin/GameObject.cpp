#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update()
{
	if (m_Components.size() != 0)
	{
		for (std::pair<std::string, BaseComponent*> var : m_Components)
		{
			var.second->Update();
		}
	}
}

void dae::GameObject::Render() const
{
	const auto& pos = m_transform.GetPosition();
	if (m_texture != nullptr) Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);

	if (m_Components.size() != 0)
	{
		for (std::pair<std::string, BaseComponent*> var : m_Components)
		{
			var.second->Render(*this);
		}
	}
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

const dae::Transform& dae::GameObject::GetTransform() const
{
	return m_transform;
}

void dae::GameObject::AddComponent(BaseComponent* compPtr)
{
	m_Components.insert(std::make_pair(typeid(*compPtr).name(), compPtr));
}


