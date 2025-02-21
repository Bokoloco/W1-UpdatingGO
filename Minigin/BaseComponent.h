#pragma once

#include <memory>

namespace dae
{
	class GameObject;
	class BaseComponent
	{
	public:
		BaseComponent(GameObject& go);

		virtual void Update() = 0;
		virtual void Render() const = 0;

		virtual ~BaseComponent() {};

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

	protected:
		GameObject* GetOwner() const { return m_pGameObject; };

	private:
		GameObject* m_pGameObject;
	};
}