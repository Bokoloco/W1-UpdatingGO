#pragma once
#include "glm.hpp"
namespace dae
{
	class Level2 final
	{
	public:
		Level2();
		~Level2() = default;

		const glm::vec3 m_Player1StartPos{ 222.f, 368.f , 0.f };
	};
}

