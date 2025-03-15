#pragma once

#include "BaseComponent.h"
#include "Subject.h"

namespace dae
{
	enum ScoreAmount
	{
		Small = 10,
		Big = 100
	};

	class GameObject;
	class ScoreComponent : public BaseComponent, public Subject
	{
		ScoreComponent(GameObject& go);

		void Update() override {};
		void Render() const override {};

		void IncreaseScore(ScoreAmount amount);

	private:
		int m_Score;
	};
}
