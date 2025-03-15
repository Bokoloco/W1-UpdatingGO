#pragma once
#include "Singleton.h"
#include <memory>
#include "ControllerInput.h"

//class ControllerInput;
namespace dae
{
	class Command;
	class GameObject;
	class InputManager final : public Singleton<InputManager>
	{
	public:
		void AddPlayer1(GameObject& go);
		void AddPlayer2(GameObject& go);

		void BeginPlay();

		bool ProcessInput();

	private:
		GameObject* m_pPlayer1;
		GameObject* m_pPlayer2;

		std::unique_ptr<ControllerInput> m_pControllerInput;

		std::unique_ptr<Command> m_MoveLeftCommand;
		std::unique_ptr<Command> m_MoveRightCommand;
		std::unique_ptr<Command> m_MoveDownCommand;
		std::unique_ptr<Command> m_MoveUpCommand;
		std::unique_ptr<Command> m_SuicideCommand;
	};
}