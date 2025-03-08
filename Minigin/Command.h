#pragma once

namespace dae
{
	class GameObject;
	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void Execute(GameObject& go) = 0;
	};
}