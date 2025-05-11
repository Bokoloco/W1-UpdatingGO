#pragma once
#include "CollisionComponent.h"
#include <vector>
#include <SDL_rect.h>
#include <map>

namespace dae
{
	class Texture2D;
	class GameObject;
	class BurgerCollisionComponent : public CollisionComponent
	{
	public:
		BurgerCollisionComponent(GameObject& go);

		void Update() override;
		void Render() const override;

		void OnColliding(GameObject& go) override;
		void OnEnter(GameObject&) override {};
		void OnExit(GameObject&) override {};

		bool HasBeenSteppedOn() const;

	private:
		//Texture2D* m_Texture{};

		//std::vector<std::pair<bool, std::unique_ptr<SDL_Rect>>> m_Pieces{};

		//int m_WidthPiece{};
		bool m_HasBeenSteppedOn{};
	};
}