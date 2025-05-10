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

		void OnEnter(GameObject& go);

	private:
		
	};
}