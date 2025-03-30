#pragma once
#include "BaseComponent.h"
#include "Observer.h"

namespace dae
{
	class GameObject;
	class TextComponent;
	class PlayerScoreInfo : public BaseComponent, public Observer
	{
	public:
		PlayerScoreInfo(GameObject& go);

		void Update() override {};
		void Render() const override {};

		void OnNotify(ObserverEvent e) override;

	private:
		TextComponent* m_pTextComponent;

		int m_Score;
	};
}