#pragma once
#include "BaseComponent.h"
#include <vector>

namespace dae
{
	class Subject;
	class Observer;
	class BurgerPartsCollisionComponent;
	class TopBurgerComponent final : public BaseComponent
	{
	public:
		TopBurgerComponent(GameObject& go);
		~TopBurgerComponent() = default;

		void Update() override;
		void Render() const override {};

		void AddObserver(Observer& observer);

		void NotifyObserver(unsigned int id, GameObject* go);

	private:
		bool m_HasHitPlate{};
		std::unique_ptr<Subject> m_pSubject{};

		std::vector<BurgerPartsCollisionComponent*> m_CollisionComponents{};
	};
}