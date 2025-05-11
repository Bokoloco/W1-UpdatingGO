#pragma once

namespace dae
{
	class GameObject;
	class FSMState
	{
	public:
		FSMState() = default;
		virtual ~FSMState() = default;

		virtual void OnEnter(GameObject* go) = 0;
		virtual void Update(GameObject* go) = 0;
	};

	class FSMCondition
	{
	public:
		FSMCondition(GameObject& go) : m_GameObject{ &go } {};
		virtual ~FSMCondition() = default;
		virtual bool Evaluate() const = 0;

	protected:
		GameObject* GetOwner() { return m_GameObject;  };

	private:
		GameObject* m_GameObject;
	};
}