#pragma once

#include "BaseComponent.h"

namespace dae
{
	class Transform;
	class GameObject;
	class RotateComponent : public BaseComponent
	{
	public:
		RotateComponent(GameObject& go, float rotateSpeed);

		void Update() override;
		void Render() const override;

	private:
		const Transform* m_pLocalTransform{};

		const float m_RotateSpeed{.1f};
	};
}

