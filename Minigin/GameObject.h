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
	class GameObject  final
	{
	public:
		//virtual void Update();
		virtual void Update();
		virtual void Render() const;

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

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::unordered_map<std::string, BaseComponent*> m_Components;
		std::shared_ptr<Texture2D> m_texture{};
	};

	template<class TypeComponent>
	inline TypeComponent* GameObject::GetComponent()
	{
		auto test = m_Components.find(typeid(TypeComponent).name());
		if (test != m_Components.end())
			return dynamic_cast<TypeComponent*>(test->second);

		return nullptr;
	}

	template<class TypeComponent>
	inline void GameObject::RemoveComponent()
	{
		m_Components.erase(typeid(TypeComponent).name());
	}

	template<class TypeComponent>
	inline bool GameObject::ContainsComponent()
	{
		return m_Components.contains(typeid(TypeComponent).name());
	}
}
