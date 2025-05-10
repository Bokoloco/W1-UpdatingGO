#pragma once
#include <glm.hpp>

namespace dae
{
	class Transform final
	{
	public:
		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z);
		void SetPosition(const glm::vec3 pos);

		const glm::vec3& GetScaling() const { return m_Scaling; };
		void SetScaling(float x, float y, float z);
		void SetScaling(const glm::vec3 scale);

	private:
		glm::vec3 m_Position{};
		glm::vec3 m_Rotation{};
		glm::vec3 m_Scaling{ 1.f, 1.f, 1.f };
	};
}
