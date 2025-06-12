#pragma once

namespace dae
{
	class GameObject;
	class FSMState
	{
	public:
		FSMState(GameObject& go) : m_GameObject{ &go } {};
		virtual ~FSMState() = default;

		virtual void OnEnter() = 0;
		virtual void Update() = 0;

	protected:
		GameObject* GetOwner() { return m_GameObject; };

	private:
		GameObject* m_GameObject;
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