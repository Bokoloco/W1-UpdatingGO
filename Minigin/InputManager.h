#pragma once
#include "Singleton.h"
#include <memory>

namespace dae
{
	class Command;
	class GameObject;
	class InputManager final : public Singleton<InputManager>
	{
	public:
		void AddPlayer1(GameObject& go);

		void BeginPlay();

		bool ProcessInput();

	private:
		GameObject* m_pPlayer1;

		std::unique_ptr<Command> m_MoveLeftCommand;
		std::unique_ptr<Command> m_MoveDownCommand;
	};
}