#pragma once
#include "glm.hpp"
namespace dae
{
	class GameObject;
	class Scene;
	class Level2 final
	{
	public:
		Level2();
		~Level2() = default;

		Level2(const Level2&) = delete;
		Level2& operator=(const Level2&) = delete;
		
		Level2(Level2&&) noexcept = default;
		Level2& operator=(Level2&&) noexcept = default;

		const glm::vec3 m_Player1StartPos{ 222.f, 368.f , 0.f };

		void MakeBurgerParts(int xOffset, int yOffset, GameObject* parent, Scene& scene);
	};
}

