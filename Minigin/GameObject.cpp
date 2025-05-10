#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"
#include <iostream>
#include "Texture2D.h"

dae::GameObject::GameObject()
{
	//m_SourceRect = new SDL_Rect(16, 16, 16, 16);
}

dae::GameObject::~GameObject()
{
	for (BaseComponent* var : m_Components)
	{
		delete var;
		var = nullptr;
	}

	m_Components.clear();

	delete m_BoundingRect;
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
	m_Components.erase(std::remove_if(m_Components.begin(), m_Components.end(), [](BaseComponent* component) {return component->ShouldGetDeleted(); }), m_Components.end());
}

void dae::GameObject::Render() const
{
	const auto& pos = m_WorldPosition.GetPosition();
	if (m_texture != nullptr) Renderer::GetInstance().RenderTexture(*m_texture, m_SourceRect.get(), pos.x, pos.y, m_BoundingRect->w, m_BoundingRect->h);

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
	m_BoundingRect = new SDL_FRect(m_WorldPosition.GetPosition().x, m_WorldPosition.GetPosition().y, static_cast<float>(m_texture->GetSize().x), static_cast<float>(m_texture->GetSize().y));
}

void dae::GameObject::SetTexture(const std::string& filename, float widthObject, float heightObject)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
	m_BoundingRect = new SDL_FRect(m_WorldPosition.GetPosition().x, m_WorldPosition.GetPosition().y, widthObject, heightObject);
}

void dae::GameObject::SetWorldPosition(float x, float y)
{
	m_WorldPosition.SetPosition(x, y, 0.0f);
}

void dae::GameObject::SetSourceRectTexture(int x, int y, int w, int h)
{
	m_SourceRect = std::make_unique<SDL_Rect>(x, y, w, h);
}

void dae::GameObject::SetScaling(float x, float y, float z)
{
	m_WorldPosition.SetScaling(x, y, z);
	m_BoundingRect->w *= x;
	m_BoundingRect->h *= y;
}

const dae::Transform& dae::GameObject::GetWorldTransform() const
{
	return m_WorldPosition;
}

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
			m_WorldPosition.SetPosition(m_LocalPosition.GetPosition());
		else
			m_WorldPosition.SetPosition(m_pParent->GetWorldPosition() + m_LocalPosition.GetPosition());
	}

	m_PositionIsDirty = false;
}

void dae::GameObject::SetPositionDirty()
{
	m_PositionIsDirty = true;
	SetPositionDirtyChildren();
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

void dae::GameObject::SetCanCollide(bool value)
{
	m_CanCollide = value;
}

bool dae::GameObject::CanCollide()
{
	return m_CanCollide;
}

void dae::GameObject::AddTag(unsigned int tag)
{
	m_Tags.push_back(tag);
}

bool dae::GameObject::ActorHasTag(unsigned int tag)
{
	return std::find(m_Tags.begin(), m_Tags.end(), tag) != m_Tags.end();
}

const SDL_FRect* dae::GameObject::GetBoundingBox()
{
	m_BoundingRect->x = m_WorldPosition.GetPosition().x;
	m_BoundingRect->y = m_WorldPosition.GetPosition().y;
	return m_BoundingRect;
}

void dae::GameObject::AddChild(GameObject* child)
{
	if (child == this || m_pParent == child)
		return;

	// Update position, rotation and scale
	child->SetPositionDirty();

	m_Children.push_back(child);
}

void dae::GameObject::RemoveChild(GameObject* child)
{
	if (child == nullptr || !IsChild(child))
		return;

	// Update position, rotation and scale	
	child->SetLocalPosition(child->GetWorldPosition());

	child->SetShouldBeDeletedFromChildren();
}

bool dae::GameObject::IsChild(GameObject* child)
{
	return std::find(m_Children.begin(), m_Children.end(), child) != m_Children.end();
}

template<class TypeComponent>
inline void dae::GameObject::RemoveComponent()
{
	for (BaseComponent* bc : m_Components)
	{
		if (typeid(TypeComponent).name() == typeid(*bc).name())
		{
			bc->SetFlagForDeletion(true);
		}
	}

	/*m_Components.erase(typeid(TypeComponent).name());*/
}