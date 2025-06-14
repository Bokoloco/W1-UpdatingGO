#pragma once
#include "BaseComponent.h"
#include <memory>

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
		std::unique_ptr<EnemyState> m_CurrentState{};

	};
}