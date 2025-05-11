#pragma once
#include <memory>
#include <vector>
#include <unordered_map>
#include "Transform.h"
#include <typeinfo>
#include <string>
#include <SDL.h>

namespace dae
{
	class Texture2D;
	class BaseComponent;
	// todo: this should become final.
	class GameObject final
	{
	public:
		GameObject();
		~GameObject();

		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void Update();
		void LateUpdate();
		void Render() const;

		void SetTexture(const std::string& filename);
		void SetTexture(const std::string& filename, float widthObject, float heightObject);
		void SetWorldPosition(float x, float y);

		void SetSourceRectTexture(int x, int y, int w, int h);
		SDL_Rect* GetSourceRect();

		void SetScaling(float x, float y, float z);

		const Transform& GetWorldTransform() const;

		template<class TypeComponent, typename... Args>
		void AddComponent(Args&&... args);

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
		const Transform& GetLocalTransform();

		void UpdateWorldPosition();

		void SetPositionDirty();
		void SetPositionDirtyChildren();
		void SetShouldBeDeletedFromChildren();
		bool ShouldBeDeleted();

		float GetSpeed();
		void SetSpeed(float speed);

		void SetCanCollide(bool value);
		bool CanCollide();

		void AddTag(unsigned int tag);
		bool ActorHasTag(unsigned int tag);

		const SDL_FRect* GetBoundingBox();

		Texture2D* GetTexture();
		void SetShouldRender(bool value);

	private:
		Transform m_LocalPosition{};
		Transform m_WorldPosition{};
		SDL_FRect* m_BoundingRect{};
		std::unique_ptr<SDL_Rect> m_SourceRect{};

		float m_Speed{0.1f};

		bool m_PositionIsDirty{};
		bool m_ShouldBeDeletedFromChildren{};
		bool m_CanCollide{};
		bool m_ShouldRender{true};

		std::vector<BaseComponent*> m_Components{};
		std::shared_ptr<Texture2D> m_texture{};

		GameObject* m_pParent{};
		std::vector<GameObject*> m_Children{};
		std::vector<unsigned int> m_Tags{};

		void AddChild(GameObject* go);
		void RemoveChild(GameObject* child);
		bool IsChild(GameObject* child);
	};

	template<class TypeComponent, typename... Args>
	inline void GameObject::AddComponent(Args&&... args)
	{
		m_Components.emplace_back(new TypeComponent(*this, std::forward<Args>(args)...));
	}

	template<class TypeComponent>
	inline TypeComponent* GameObject::GetComponent()
	{
		for (BaseComponent* bc : m_Components)
		{
			//if (Component<TypeComponent>:: == typeid(*bc).name() || dynamic_cast<TypeComponent*>(bc))
			//{
			//	return dynamic_cast<TypeComponent*>(bc);
			//}
			if (auto casted = dynamic_cast<TypeComponent*>(bc))
			{
				return casted;
			}
		}

		return nullptr;
	}

	template<class TypeComponent>
	inline bool GameObject::ContainsComponent()
	{
		for (BaseComponent* bc : m_Components)
		{
			if (dynamic_cast<TypeComponent*>(bc))
			{
				return true;
			}
		}

		return false;
	}
}
