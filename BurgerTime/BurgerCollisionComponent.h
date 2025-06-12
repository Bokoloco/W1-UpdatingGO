#pragma once

#include "CollisionComponent.h"
#include <memory>

namespace dae
{
	class Subject;
	class Observer;
	class FoodFallingComponent;
	class BurgerCollisionComponent final : public CollisionComponent
	{
	public:
		BurgerCollisionComponent(GameObject& go);
		~BurgerCollisionComponent() = default;

		void Update() override {};
		void Render() const override {};

		void OnColliding(GameObject& go) override;
		void OnEnter(GameObject& go) override;
		void OnExit(GameObject& go) override;

		void AddObserver(Observer& observer);

		int GetAmountOfEnemiesOnBurger() const;

	private:
		bool m_JustSpawned{ true };
		int m_AmountOfEnemiesOnBurger{};
		int m_AmountOfEnemiesOnBurgerForScore{};

		std::unique_ptr<Subject> m_pSubject{};
		
		FoodFallingComponent* m_pFoodFallingComponent{};  
	};
}