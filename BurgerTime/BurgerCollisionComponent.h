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
		BurgerCollisionComponent(GameObject& go, int idx);

		void Update() override;
		void Render() const override;

		void OnColliding(GameObject& go) override;
		void OnEnter(GameObject& go) override;
		void OnExit(GameObject& go) override;

		bool HasBeenSteppedOn() const;
		bool HasHitPlate() const;

	private:
		//Texture2D* m_Texture{};

		//std::vector<std::pair<bool, std::unique_ptr<SDL_Rect>>> m_Pieces{};

		//int m_WidthPiece{};
		bool m_HasBeenSteppedOn{};
		bool m_HasHitPlate{};

		int m_idx{};
	};
}