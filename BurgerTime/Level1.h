#pragma once
#include <memory>
#include "ResourceManager.h"

namespace dae
{
	class Level1
	{
	public:
		Level1(unsigned int sceneName, std::shared_ptr<dae::Font> font);
		~Level1() = default;
	};
}

