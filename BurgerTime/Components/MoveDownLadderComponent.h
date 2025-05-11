#pragma once
#include "BaseComponent.h"

namespace dae
{
	class GameObject;
	class MoveDownLadderComponent : public BaseComponent
	{
	public:
		MoveDownLadderComponent(GameObject& go);

		void Update() override {};
		void Render() const override {};

		void SetCanMoveDownLadder(bool value);
		void SetMoveToHeight(float value);

		bool CanMoveOnLadder();
		float GetMinHeight() const;

	private:
		bool m_CanMoveDownLadder{};
		float m_MaxHeight{};
		float m_MinHeight{};
	};
}