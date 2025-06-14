#pragma once
#include <memory>
#include "ResourceManager.h"
#include "glm.hpp"

namespace dae
{
	class GameObject;
	class Scene;
	class Level1
	{
	public:
		Level1();
		~Level1() = default;

		Level1(const Level1&) = delete;
		Level1& operator=(const Level1&) = delete;

		Level1(Level1&&) noexcept = default;
		Level1& operator=(Level1&&) noexcept = default;

		void MakeBurgerParts(int xOffset, int yOffset, GameObject* parent, Scene& scene);

		const glm::vec3 m_Player1StartPos{ 222.f, 335.f , 0.f };
	};
}

