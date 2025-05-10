#pragma once
#include "BaseComponent.h"

namespace dae
{
	class GameObject;
	class CollisionComponent : public BaseComponent
	{
	public:
		CollisionComponent(GameObject& go);

		void Update() override;
		void Render() const override;

		virtual void OnColliding(GameObject&) {};
		virtual void OnEnter(GameObject&) {};
		virtual void OnExit(GameObject&) {};

	private:
	};
}