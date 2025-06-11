#pragma once
#include "BaseComponent.h"
#include <vector>

namespace dae
{
	class GameObject;
	class BurgerPartsCollisionComponent;
	class FoodFallingComponent : public BaseComponent
	{
	public:
		FoodFallingComponent(GameObject& go, float speed);

		void Update() override;
		void Render() const override;

		void ShouldNotFall(bool value);
		bool IsFalling();

	private:
		std::vector<BurgerPartsCollisionComponent*> m_CollisionComponents{};

		float m_Speed{};
		bool m_ShouldFall{};
	};
}