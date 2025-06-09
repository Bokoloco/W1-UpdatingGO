#pragma once
#include "Singleton.h"
//#include <memory>
#include "ControllerInput.h"
#include <vector>
#include <map>
#include "Command.h"
//class ControllerInput;
namespace dae
{
	struct KeyboardBinding
	{
		SDL_Scancode scancode;
		SDL_EventType eventType;

		bool operator<(const KeyboardBinding& other) const {
			return scancode < other.scancode;
		}
	};

	struct ControllerButtonBinding
	{
		DWORD controllerIndex;
		unsigned int button;
		bool isPressed;

		bool operator<(const ControllerButtonBinding& other) const {
			/*if (button != other.button)*/
				return button < other.button;
			//return isPressed < other.isPressed;
		}
	};

	//class Command;
	class GameObject;
	class InputManager final : public Singleton<InputManager>
	{
	public:
		void AddPlayer1(GameObject& go);
		void AddPlayer2(GameObject& go);

		void AddController();

		void BindInputKeyboard(SDL_Scancode scancode, SDL_EventType eventType, std::unique_ptr<Command>);
		void BindInputController(DWORD controllerIndex, unsigned int button, bool isPressed, std::unique_ptr<Command> command);

		void BeginPlay();

		bool ProcessInput();

	private:
		GameObject* m_pPlayer1{};
		GameObject* m_pPlayer2{};

		std::vector<std::unique_ptr<ControllerInput>> m_pControllerInputs;

		std::map<ControllerButtonBinding, std::unique_ptr<Command>> m_CommandsControllers;
		std::map<KeyboardBinding, std::unique_ptr<Command>> m_CommandsKeyboard;
	};
}