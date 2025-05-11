#pragma once
#include "BaseComponent.h"
#include <vector>

namespace dae
{
	class GameObject;
	class BurgerCollisionComponent;
	class FoodFallingComponent : public BaseComponent
	{
	public:
		FoodFallingComponent(GameObject& go);

		void Update() override;
		void Render() const override;

	private:
		std::vector< BurgerCollisionComponent*> m_CollisionComponents{};
	};
}