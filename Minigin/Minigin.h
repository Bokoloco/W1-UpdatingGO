#pragma once
#include <string>
#include <functional>
#include <chrono>

namespace dae
{
	class Minigin
	{
	public:
		explicit Minigin(const std::string& dataPath);
		~Minigin();
		void Run(const std::function<void()>& load);

		Minigin(const Minigin& other) = delete;
		Minigin(Minigin&& other) = delete;
		Minigin& operator=(const Minigin& other) = delete;
		Minigin& operator=(Minigin&& other) = delete;

		static long long DELTATIME;

	private:
		std::chrono::high_resolution_clock::time_point m_CurrentTime{};

		void UpdateDeltaTime();
	};
}