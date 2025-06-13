#pragma once
#include <memory>
#include "ResourceManager.h"

namespace dae
{
	class GameObject;
	class Scene;
	class Level1
	{
	public:
		Level1(unsigned int sceneName);
		~Level1() = default;

		void MakeBurgerParts(int xOffset, int yOffset, GameObject* parent, Scene& scene);
	};
}

