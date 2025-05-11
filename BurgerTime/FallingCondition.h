#pragma once
#include "FSMStateAndCondition.h"
#include <vector>

namespace dae
{
	class BurgerCollisionComponent;
	class GameObject;
	class FallingCondition : public FSMCondition
	{
	public:
		FallingCondition(GameObject& go, bool toFallTransition);
		~FallingCondition() = default;

		bool Evaluate() const override;

	private:
		std::vector<BurgerCollisionComponent*> m_CollisionComponents;

		bool m_ToFallTransition{};
	};
}