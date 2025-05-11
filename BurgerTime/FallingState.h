#pragma once
#include "FSMStateAndCondition.h"

namespace dae
{
	class GameObject;
	class FallingState : public FSMState
	{
	public:
		FallingState(float speed);
		~FallingState() = default;

		void OnEnter(GameObject*) override {};
		void Update(GameObject* go) override;

	private:
		float m_Speed{};
	};
}