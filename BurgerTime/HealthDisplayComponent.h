#pragma once
#include "BaseComponent.h"
#include <TextObject.h>
#include <memory>
#include "HealthObserver.h"

namespace dae
{
	class GameObject;
	class HealthDisplayComponent final : public BaseComponent
	{
	public:
		HealthDisplayComponent(GameObject& go);

		void Update() override;
		void Render() const override;

		HealthObserver* GetObserver() const;

	private:
		std::unique_ptr<HealthObserver> m_pHealthObserver{};
		unsigned int m_AmountOfLives{  };

		bool m_ChangeCooldown{};

		float m_CoolDownBeforeReset{ 1100.f };
		const float m_COOLDOWN{ 1100.f };

	};
}