#pragma once
#include "BaseComponent.h"
#include "glm.hpp"

namespace dae
{
	class EnemyComponent final : public BaseComponent
	{
	public:
		EnemyComponent(GameObject& go, glm::vec3 position);
		~EnemyComponent() = default;

		void Update() override;
		void Render() const override {};

		bool ShouldReset{};
	private:
		const glm::vec3 m_POSITION;
	};
}