#pragma once
#include <glm.hpp>


namespace dae
{
	class GameObject;
	class Scene;
	class Level3 final
	{
	public:
		Level3();
		~Level3() = default;

		Level3(const Level3&) = delete;
		Level3& operator=(const Level3&) = delete;

		Level3(Level3&&) noexcept = default;
		Level3& operator=(Level3&&) noexcept = default;

		const glm::vec3 m_Player1StartPos{ 222.f, 273.f , 0.f };

		void MakeBurgerParts(int xOffset, int yOffset, GameObject* parent, Scene& scene);
	};
}