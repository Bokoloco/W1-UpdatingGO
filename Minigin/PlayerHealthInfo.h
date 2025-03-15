#pragma once

#include "BaseComponent.h"
#include "Observer.h"

namespace dae
{
	class GameObject;
	class TextComponent;
	class PlayerHealthInfo : public BaseComponent, public Observer
	{
	public:
		PlayerHealthInfo(GameObject& go);

		void Update() override {};
		void Render() const override {};

		void OnNotify(ObserverEvent e) override;

	private:
		TextComponent* m_pTextComponent;

		int m_Lives;
	};
}