#pragma once
#include "FSMStateAndCondition.h"

namespace dae
{
	class IdleState : public FSMState
	{
	public:
		IdleState() = default;
		~IdleState() = default;

		void OnEnter(GameObject* go) override;
		void Update(GameObject*) override {};
	};
}