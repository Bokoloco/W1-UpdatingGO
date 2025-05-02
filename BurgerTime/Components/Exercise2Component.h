#pragma once

#include "BaseComponent.h"

#include <vector>

namespace dae
{
	struct transform
	{
		float matrix[16] = {
		  1,0,0,0,
		  0,1,0,0,
		  0,0,1,0,
		  0,0,0,1
		};
	};

	class gameobject
	{
	public:
		dae::transform local;
		int id;
	};

	class gameobjectAlt
	{
	public:
		dae::transform* local;
		int id;
	};

	class Exercise2Component final : public BaseComponent
	{
	public:
		Exercise2Component(GameObject& go);

		void Update() override;
		void Render() const override;

	private:
		int m_AmountOfSamples;
		std::vector<std::vector<long long>> m_TimesGameObject3D{};
		std::vector<std::vector<long long>> m_TimesGameObject3DAlt{};
		std::vector<float> m_AveragesGameObject3D{};
		std::vector<float> m_AveragesGameObject3DAlt{};

		bool m_ShowPlotGameObject3D{};
		bool m_ShowPlotGameObject3DAlt{};

		void CalculateTimeGameObject();
		void CalculateTimeGameObject3DAlt();
		void CalculateAverageGameObject3D();
		void CalculateAverageGameObject3DAlt();
	};
}