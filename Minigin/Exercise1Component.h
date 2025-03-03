#pragma once

#include "BaseComponent.h"

#include <vector>

namespace dae
{
	class Exercise1Component final : public BaseComponent
	{
	public:
		Exercise1Component(GameObject& go);

		void Update() override;
		void Render() const override;

	private:
		int m_AmountOfSamples;
		std::vector<std::vector<long long>> m_Times{};
		std::vector<float> m_Averages{};

		bool m_ShowPlot{};

		void CalculateMiliseconds();
		void CalculateAverage();
	};
}


