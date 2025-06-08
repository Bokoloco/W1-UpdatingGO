#pragma once
#include "BaseComponent.h"
#include "ScoreObserver.h"

namespace dae
{
	class Observer;
	class ScoreDisplayComponent final : public BaseComponent
	{
	public:
		ScoreDisplayComponent(GameObject& go);
		~ScoreDisplayComponent() = default;
		
		void Update() override;
		void Render() const override {};

		ScoreObserver* GetObserver() const;

	private:
		std::unique_ptr<ScoreObserver> m_pScoreObserver{};

	};
}