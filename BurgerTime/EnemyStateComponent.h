#pragma once
#include "BaseComponent.h"

namespace dae
{
	class EnemyState;
	class EnemyStateComponent : public BaseComponent
	{
	public:
		EnemyStateComponent(GameObject& go, GameObject& player);
		~EnemyStateComponent();

		void Update() override;
		void Render() const override {};

	private:
		EnemyState* m_CurrentState{};

	};
}