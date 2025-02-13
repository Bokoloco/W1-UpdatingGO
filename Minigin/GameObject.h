#pragma once
#include <memory>
#include <vector>
#include <unordered_map>
#include "Transform.h"
#include <typeinfo>

namespace dae
{
	class Texture2D;
	class BaseComponent;
	// todo: this should become final.
	class GameObject 
	{
	public:
		virtual void Update();
		virtual void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		const Transform& GetTransform() const;

		void AddComponent(BaseComponent* compPtr);

		template<class TypeComponent>
		TypeComponent* GetComponent();

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
		std::string erm{ typeid(TypeComponent).name() };
		auto test = m_Components.find(typeid(TypeComponent).name());
		if (test != m_Components.end())
			return dynamic_cast<TypeComponent*>(test->second);

		return nullptr;
	}
}
