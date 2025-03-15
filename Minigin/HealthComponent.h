#pragma once

#include "BaseComponent.h"
#include "Subject.h"

namespace dae
{
	class GameObject;
	class HealthComponent : public BaseComponent, public Subject
	{
	public:
		HealthComponent(GameObject& go);

		void Update() override;
		void Render() const override;

		void DecreaseLives();
	private:
		int m_Lives;
	};
}