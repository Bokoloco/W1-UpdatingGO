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

		bool ShouldGetDeleted() const { return m_FlagForDeletion; }

	protected:
		GameObject* GetOwner() const { return m_pGameObject; };

		void SetFlagForDeletion(bool flag) { m_FlagForDeletion = flag; }

	private:
		GameObject* m_pGameObject;

		bool m_FlagForDeletion;
	};
}