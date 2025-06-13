#pragma once
#include "BaseComponent.h"
#include "ScoreObserver.h"

namespace dae
{
	class Observer;
	class TextComponent;
	class ScoreDisplayComponent final : public BaseComponent
	{
	public:
		ScoreDisplayComponent(GameObject& go);
		~ScoreDisplayComponent() = default;
		
		void Update() override;
		void Render() const override;

		ScoreObserver* GetObserver() const;

	private:
		unsigned int m_Score{};

		std::unique_ptr<ScoreObserver> m_pScoreObserver{};
		TextComponent* m_pTextComponent{};

	};
}