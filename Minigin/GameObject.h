#pragma once
#include <memory>
#include <vector>
#include <unordered_map>
#include "Transform.h"
#include <typeinfo>
#include <string>

namespace dae
{
	class Texture2D;
	class BaseComponent;
	// todo: this should become final.
	class GameObject final
	{
	public:
		GameObject() = default;
		~GameObject();

		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void Update();
		void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		const Transform& GetTransform() const;

		void AddComponent(BaseComponent* compPtr);

		template<class TypeComponent>
		TypeComponent* GetComponent();

		template<class TypeComponent>
		void RemoveComponent();

		template<class TypeComponent>
		bool ContainsComponent();

		GameObject* GetParent();
		void SetParent(GameObject* parent);

		int GetChildCount();
		GameObject* GetChildAt(int index);

		void SetLocalPosition(const glm::vec3& pos);

		const glm::vec3 GetWorldPosition();

		void UpdateWorldPosition();

		void SetPositionDirty();
		void SetPositionDirtyChildren();

	private:
		Transform m_LocalPosition{};
		Transform m_WorldPosition{};

		bool m_PositionIsDirty{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		//std::unordered_map<std::string, BaseComponent*> m_Components;

		std::vector<BaseComponent*> m_Components{};
		std::shared_ptr<Texture2D> m_texture{};

		GameObject* m_pParent{};
		std::vector<GameObject*> m_Children{};

		void AddChild(GameObject* go);
		void RemoveChild(GameObject* child);
		bool IsChild(GameObject* child);
	};

	template<class TypeComponent>
	inline TypeComponent* GameObject::GetComponent()
	{
		for (BaseComponent* bc : m_Components)
		{
			if (typeid(TypeComponent).name() == typeid(*bc).name())
			{
				return dynamic_cast<TypeComponent*>(bc);
			}
		}

		return nullptr;
	}

	template<class TypeComponent>
	inline void GameObject::RemoveComponent()
	{
		for (BaseComponent* bc : m_Components)
		{
			if (typeid(TypeComponent).name() == typeid(*bc).name())
			{
				delete bc;
				bc = nullptr;
			}
		}

		m_Components.erase(typeid(TypeComponent).name());
	}

	template<class TypeComponent>
	inline bool GameObject::ContainsComponent()
	{
		return true;
	}
}
