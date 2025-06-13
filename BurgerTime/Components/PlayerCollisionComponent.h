#pragma once
#include "CollisionComponent.h"

namespace dae
{
	class GameObject;
	class MoveDownLadderComponent;
	class Subject;
	class Observer;
	class PlayerCollisionComponent final : public CollisionComponent
	{
	public:
		PlayerCollisionComponent(GameObject& go);

		void Update() override;
		void Render() const override {};

		void OnColliding(GameObject& go) override;
		void OnEnter(GameObject& go) override;
		void OnExit(GameObject& go) override;

		void AddObserver(Observer& observer);

	private:
		MoveDownLadderComponent* m_pMoveDownLadderComponent{};
		std::unique_ptr<Subject> m_pSubject{};

		const float m_Offset{10.f};

	};
}