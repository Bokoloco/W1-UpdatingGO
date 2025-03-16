#pragma once

#include "BaseComponent.h"
#include "Subject.h"

namespace dae
{
	enum class ScoreAmount
	{
		Small = 10,
		Big = 100
	};

	class GameObject;
	class ScoreComponent : public BaseComponent, public Subject
	{
	public:
		ScoreComponent(GameObject& go);

		void Update() override {};
		void Render() const override {};

		void IncreaseScore(ScoreAmount amount);

	private:
		int m_Score;
	};
}
