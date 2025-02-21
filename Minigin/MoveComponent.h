#pragma once

#include "BaseComponent.h"

namespace dae
{
	class Transform;
	class GameObject;
	class MoveComponent : public BaseComponent
	{
	public:
		MoveComponent(GameObject& go);

		void Update() override;
		void Render() const override;

	private:
		const Transform* m_pTransform;

		float m_Speed;
	};
}

