#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"
#include <iostream>

dae::GameObject::~GameObject()
{
	for (BaseComponent* var : m_Components)
	{
		delete var;
		var = nullptr;
	}

	m_Components.clear();
}

void dae::GameObject::Update()
{
	if (m_Components.size() != 0)
	{
		for (BaseComponent* var : m_Components)
		{
			var->Update();
		}
	}

	UpdateWorldPosition();
}

void dae::GameObject::LateUpdate()
{
	m_Children.erase(std::remove_if(m_Children.begin(), m_Children.end(), [](GameObject* child) { return child->ShouldBeDeleted(); }), m_Children.end());
}

void dae::GameObject::Render() const
{
	const auto& pos = m_WorldPosition.GetPosition();
	if (m_texture != nullptr) Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);

	if (m_Components.size() != 0)
	{
		for (BaseComponent* var : m_Components)
		{
			var->Render();
		}
	}
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetWorldPosition(float x, float y)
{
	m_WorldPosition.SetPosition(x, y, 0.0f);
}

const dae::Transform& dae::GameObject::GetWorldTransform() const
{
	return m_WorldPosition;
}

//void dae::GameObject::AddComponent(BaseComponent* compPtr)
//{
//	//templetized function + args
//	m_Components.push_back(compPtr);
//	//m_Components.insert(std::make_pair(typeid(*compPtr).name(), compPtr));
//}

dae::GameObject* dae::GameObject::GetParent()
{
	return m_pParent;
}

void dae::GameObject::SetParent(GameObject* parent)
{
	if (IsChild(parent) || parent == this || m_pParent == parent)
		return;

	if (parent == nullptr)
		SetLocalPosition(GetWorldPosition());
	else
		SetPositionDirty();

	if (m_pParent) m_pParent->RemoveChild(this);

	m_pParent = parent;

	if (m_pParent) m_pParent->AddChild(this);
}

int dae::GameObject::GetChildCount()
{
	return static_cast<int>(m_Children.size());
}

dae::GameObject* dae::GameObject::GetChildAt(int index)
{
	return m_Children.at(index);
}

void dae::GameObject::SetLocalPosition(const glm::vec3& pos)
{
	m_LocalPosition.SetPosition(pos);
	SetPositionDirty();
}

const glm::vec3 dae::GameObject::GetWorldPosition()
{
	if (m_PositionIsDirty)
		UpdateWorldPosition();
	return m_WorldPosition.GetPosition();
}

const dae::Transform& dae::GameObject::GetLocalTransform()
{
	// TODO: insert return statement here
	return m_LocalPosition;
}

void dae::GameObject::UpdateWorldPosition()
{
	if (m_PositionIsDirty)
	{
		if (m_pParent == nullptr)
			m_WorldPosition = m_LocalPosition;
		else
			m_WorldPosition.SetPosition(m_pParent->GetWorldPosition() + m_LocalPosition.GetPosition());
	}

	m_PositionIsDirty = false;
}

void dae::GameObject::SetPositionDirty()
{
	m_PositionIsDirty = true;
}

void dae::GameObject::SetPositionDirtyChildren()
{
	if (!m_Children.empty())
	{
		for (GameObject* child : m_Children)
		{
			child->SetPositionDirty();
		}
	}
}

void dae::GameObject::SetShouldBeDeletedFromChildren()
{
	m_ShouldBeDeletedFromChildren = true;
}

bool dae::GameObject::ShouldBeDeleted()
{
	return m_ShouldBeDeletedFromChildren;
}

float dae::GameObject::GetSpeed()
{
	return m_Speed;
}

void dae::GameObject::SetSpeed(float speed)
{
	m_Speed = speed;
}

void dae::GameObject::AddChild(GameObject* child)
{
	if (child == this || m_pParent == child)
		return;

	// Update position, rotation and scale

	m_Children.push_back(child);
}

void dae::GameObject::RemoveChild(GameObject* child)
{
	if (child == nullptr || !IsChild(child))
		return;

	// Update position, rotation and scale
	m_LocalPosition.SetPosition(GetWorldPosition());

	child->SetShouldBeDeletedFromChildren();

	//m_Children.erase(std::find(m_Children.begin(), m_Children.end(), child));
}

bool dae::GameObject::IsChild(GameObject* child)
{
	return std::find(m_Children.begin(), m_Children.end(), child) != m_Children.end();
}
