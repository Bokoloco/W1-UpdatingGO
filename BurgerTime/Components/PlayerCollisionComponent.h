#pragma once
#include "CollisionComponent.h"

namespace dae
{
	class GameObject;
	class MoveDownLadderComponent;
	class PlayerCollisionComponent final : public CollisionComponent
	{
	public:
		PlayerCollisionComponent(GameObject& go);

		void Update() override;
		void Render() const override {};

		void OnColliding(GameObject& go) override;
		//void OnEnter(GameObject& go) override;
		void OnExit(GameObject& go) override;

	private:
		MoveDownLadderComponent* m_pMoveDownLadderComponent{};

	};
}