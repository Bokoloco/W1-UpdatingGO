#pragma once

#include "BaseComponent.h"
namespace dae
{
	class GameObject;
	class FPSComponent final : public BaseComponent
	{
	public:
		void Update() override;
		void Render(const GameObject& go) const override;

		float GetFPS();

	private:
		float m_CurrentFPS{};
	};
}