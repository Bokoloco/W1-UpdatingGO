#include "Exercise1Component.h"
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_sdl2.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <array>
#include <imgui_plot.h>

dae::Exercise1Component::Exercise1Component(GameObject& go)
	: BaseComponent(go)
	, m_AmountOfSamples{1}
{}

void dae::Exercise1Component::Update()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Exercise 1");

	ImGui::InputInt("# samples", &m_AmountOfSamples);

	if (ImGui::Button("Thrash the cache")) 
	{
		std::cout << "Thrash the cache" << std::endl;
		m_Times.clear();
		m_Averages.clear();

		CalculateMiliseconds();

		m_ShowPlot = true;
	}

	if (m_ShowPlot)
	{
		ImGui::PlotConfig conf;
		conf.values.ys = m_Averages.data();
		conf.values.count = static_cast<int>(m_Averages.size());
		conf.scale.min = 0.f;
		conf.scale.max = 500000.f;
		conf.tooltip.show = true;
		conf.tooltip.format = "x=%.2f, y=%.2f";
		conf.grid_x.show = true;
		conf.grid_y.show = true;
		conf.frame_size = ImVec2(200, 100);
		conf.line_thickness = 2.f;

		ImGui::Plot("Exercise 1", conf);
	}

	ImGui::End();
}

void dae::Exercise1Component::Render() const
{
	// ImGui::ShowDemoWindow();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void dae::Exercise1Component::CalculateMiliseconds()
{
	for (int sampleIdx{}; sampleIdx < m_AmountOfSamples; ++sampleIdx)
	{
		m_Times.push_back({});
		std::vector<int> arr(static_cast<int>(std::pow(2, 26)));
		auto start = std::chrono::high_resolution_clock::now();

		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{
			for (int i = 0; i < arr.size(); i += stepsize)
			{
				arr[i] *= 2;
			}

			const auto end = std::chrono::high_resolution_clock::now();
			const auto total = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			start = end;

			m_Times.at(sampleIdx).push_back(total);

			//std::cout << stepsize << "; " << total << std::endl;
		}
	}

	CalculateAverage();
}

void dae::Exercise1Component::CalculateAverage()
{
	for (int innerIdx{}; innerIdx < 11; ++innerIdx)
	{
		long long sum{};
		for (int outerIdx{}; outerIdx < m_Times.size(); ++outerIdx)
		{
			sum += m_Times.at(outerIdx).at(innerIdx);
		}

		m_Averages.push_back(static_cast<float>(static_cast<int>(sum) / m_AmountOfSamples));
	}
}


