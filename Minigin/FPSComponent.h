#pragma once

#include "BaseComponent.h"
namespace dae
{
	class GameObject;
	class TextComponent;
	class FPSComponent final : public BaseComponent
	{
	public:
		FPSComponent(GameObject& go, TextComponent& tc);

		void Update() override;
		void Render() const override;

		float GetFPS();

	private:
		float m_CurrentFPS{};

		TextComponent* m_pTextComponent{};
	};
}