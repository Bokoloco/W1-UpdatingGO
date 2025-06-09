#pragma once
#include "BaseComponent.h"
#include "glm.hpp"
#include <vector>

namespace dae
{
	class GameObject;
	class MoveDownLadderComponent : public BaseComponent
	{
	public:
		MoveDownLadderComponent(GameObject& go, float speed);

		void Update() override;
		void Render() const override {};

		void SetCanMoveDownLadder(bool value);
		void SetCanMoveHorizontally(bool value);
		void SetMoveToHeight(float minHeight, float maxHeight);
		void RemoveLadderFromList(float minheight, float maxheight);

		bool CanMoveOnLadder();
		float GetMinHeight() const;

		void SetDirection(const glm::vec3& direction);

	private:
		bool m_CanMoveDownLadder{};
		bool m_CanMoveHorizontally{true};

		float m_MaxHeight{};
		float m_MinHeight{};
		float m_Speed{};

		glm::vec3 m_Direction{};

		std::vector<float> m_MinHeights{};
		std::vector<float> m_MaxHeights{};
	};
}