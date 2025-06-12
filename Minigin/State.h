#pragma once

namespace dae
{
	class GameObject;
	class State
	{
	public:
		State() = default;
		virtual ~State() = default;

		virtual State* HandleInput() = 0;
		virtual void OnEnter(GameObject* go) { m_GameObject = go; };
		virtual void Update(GameObject* go) = 0;

	protected:
		GameObject* GetOwner() const { return m_GameObject; };

	private:
		GameObject* m_GameObject;
	};
}