#include "Exercise2Component.h"
#include <chrono>
#include <backends/imgui_impl_sdl2.h>
#include <imgui_plot.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui.h>
#include <iostream>

dae::Exercise2Component::Exercise2Component(GameObject& go)
	: BaseComponent(go)
	, m_AmountOfSamples{1}
{}

void dae::Exercise2Component::Update()
{
	/*ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();*/

	ImGui::Begin("Exercise 2");

	ImGui::InputInt("# samples", &m_AmountOfSamples);

	if (ImGui::Button("Thrash the cache with GameObject3D"))
	{
		m_TimesGameObject3D.clear();
		m_AveragesGameObject3D.clear();

		CalculateTimeGameObject();

		m_ShowPlotGameObject3D = true;
	}

	if (m_ShowPlotGameObject3D)
	{
		ImGui::PlotConfig conf;
		conf.values.ys = m_AveragesGameObject3D.data();
		conf.values.count = static_cast<int>(m_AveragesGameObject3D.size());
		conf.scale.min = 0.f;
		conf.scale.max = m_AveragesGameObject3D.at(0);
		conf.tooltip.show = true;
		conf.tooltip.format = "x=%.2f, y=%.2f";
		conf.grid_x.show = true;
		conf.grid_y.show = true;
		conf.frame_size = ImVec2(200, 100);
		conf.line_thickness = 2.f;

		ImGui::Plot("Exercise 2", conf);
	}

	if (ImGui::Button("Thrash the cache with GameObject3DAlt"))
	{
		m_TimesGameObject3DAlt.clear();
		m_AveragesGameObject3DAlt.clear();

		CalculateTimeGameObject3DAlt();

		m_ShowPlotGameObject3DAlt = true;
	}

	if (m_ShowPlotGameObject3DAlt)
	{
		ImGui::PlotConfig conf;
		conf.values.ys = m_AveragesGameObject3DAlt.data();
		conf.values.count = static_cast<int>(m_AveragesGameObject3DAlt.size());
		conf.scale.min = 0.f;
		conf.scale.max = m_AveragesGameObject3DAlt.at(0);
		conf.tooltip.show = true;
		conf.tooltip.format = "x=%.2f, y=%.2f";
		conf.grid_x.show = true;
		conf.grid_y.show = true;
		conf.frame_size = ImVec2(200, 100);
		conf.line_thickness = 2.f;

		ImGui::Plot("Exercise 2 Alt", conf);
	}

	ImGui::End();
}

void dae::Exercise2Component::Render() const
{
	// ImGui::ShowDemoWindow();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void dae::Exercise2Component::CalculateTimeGameObject()
{
	for (int sampleIdx{}; sampleIdx < m_AmountOfSamples; ++sampleIdx)
	{
		m_TimesGameObject3D.push_back({});
		std::vector<gameobject> arr(static_cast<int>(std::pow(2, 26)));

		auto start = std::chrono::high_resolution_clock::now();

		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{
			for (int i = 0; i < arr.size(); i += stepsize)
			{
				arr[i].id *= 2;
			}

			const auto end = std::chrono::high_resolution_clock::now();
			const auto total = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			start = end;

			m_TimesGameObject3D.at(sampleIdx).push_back(total);
		}
	}

	CalculateAverageGameObject3D();
}

void dae::Exercise2Component::CalculateTimeGameObject3DAlt()
{
	for (int sampleIdx{}; sampleIdx < m_AmountOfSamples; ++sampleIdx)
	{
		m_TimesGameObject3DAlt.push_back({});
		std::vector<gameobjectAlt> arr(static_cast<int>(std::pow(2, 26)));

		auto start = std::chrono::high_resolution_clock::now();

		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{
			for (int i = 0; i < arr.size(); i += stepsize)
			{
				arr[i].id *= 2;
			}

			const auto end = std::chrono::high_resolution_clock::now();
			const auto total = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			start = end;

			m_TimesGameObject3DAlt.at(sampleIdx).push_back(total);

			//std::cout << stepsize << "; " << total << std::endl;
		}
	}

	CalculateAverageGameObject3DAlt();
}

void dae::Exercise2Component::CalculateAverageGameObject3D()
{
	for (int innerIdx{}; innerIdx < 11; ++innerIdx)
	{
		long long sum{};
		for (int outerIdx{}; outerIdx < m_TimesGameObject3D.size(); ++outerIdx)
		{
			sum += m_TimesGameObject3D.at(outerIdx).at(innerIdx);
		}

		m_AveragesGameObject3D.push_back(static_cast<float>(static_cast<int>(sum) / m_AmountOfSamples));
	}
}

void dae::Exercise2Component::CalculateAverageGameObject3DAlt()
{
	for (int innerIdx{}; innerIdx < 11; ++innerIdx)
	{
		long long sum{};
		for (int outerIdx{}; outerIdx < m_TimesGameObject3DAlt.size(); ++outerIdx)
		{
			sum += m_TimesGameObject3DAlt.at(outerIdx).at(innerIdx);
		}

		m_AveragesGameObject3DAlt.push_back(static_cast<float>(static_cast<int>(sum) / m_AmountOfSamples));
	}
}
