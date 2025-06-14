#include <SDL.h>
#include "InputManager.h"
#include <iostream>
//#include <backends/imgui_impl_sdl2.h>
//#include "Command.h"
#include "ControllerInput.h"


void dae::InputManager::AddPlayer1(GameObject & go)
{
	m_pPlayer1 = &go;
}

void dae::InputManager::AddPlayer2(GameObject& go)
{
	m_pPlayer2 = &go;
}

void dae::InputManager::AddController()
{
	m_pControllerInputs.push_back(std::make_unique<ControllerInput>(static_cast<DWORD>(m_pControllerInputs.size())));
}

void dae::InputManager::BindInputKeyboard(SDL_Scancode scancode, SDL_EventType eventType, std::unique_ptr<Command> command)
{
	m_CommandsKeyboard.emplace(KeyboardBinding{ scancode, eventType }, std::move(command));
}

void dae::InputManager::BindInputController(DWORD controllerIndex, unsigned int button, bool isPressed, std::unique_ptr<Command> command)
{
	m_CommandsControllers.emplace(ControllerButtonBinding{controllerIndex, button, isPressed}, std::move(command));
}

void dae::InputManager::BeginPlay()
{
}

bool dae::InputManager::ProcessInput()
{
	for (int i{}; i < m_pControllerInputs.size(); ++i)
	{
		m_pControllerInputs[i]->Update();

		for (auto& binding : m_CommandsControllers)
		{
			if (static_cast<DWORD>(i) == binding.first.controllerIndex)
			{
				if (binding.first.isPressed)
					if (m_pControllerInputs[i]->CheckButtonPressed(binding.first.button))
						binding.second->Execute();
				else
					if (m_pControllerInputs[i]->CheckButtonReleased(binding.first.button))
						binding.second->Execute();
			}
		}
	}
	/*m_pControllerInput.get()->Update();
	if (m_pControllerInput->CheckButtonPressed(1)) m_MoveUpCommand->Execute(*m_pPlayer2);
	if (m_pControllerInput->CheckButtonPressed(2)) m_MoveDownCommand->Execute(*m_pPlayer2);
	if (m_pControllerInput->CheckButtonPressed(4)) m_MoveLeftCommand->Execute(*m_pPlayer2);
	if (m_pControllerInput->CheckButtonPressed(8)) m_MoveRightCommand->Execute(*m_pPlayer2);
	if (m_pControllerInput->CheckButtonReleased(XINPUT_GAMEPAD_X)) m_SuicideCommand->Execute(*m_pPlayer2);
	if (m_pControllerInput->CheckButtonReleased(XINPUT_GAMEPAD_A)) m_ScoreSmallCommand->Execute(*m_pPlayer2);
	if (m_pControllerInput->CheckButtonReleased(XINPUT_GAMEPAD_B)) m_ScoreBigCommand->Execute(*m_pPlayer2);*/

	//const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	//	case SDL_KEYDOWN:
	//	{
	//		for (auto& binding : m_CommandsKeyboard)
	//		{
	//			if (binding.first == e.key.keysym.sym)
	//				binding.second->Execute();
	//		}
	//		break;
	//	}
	//	default:
	//		break;
	//	}
	//	// etc...

	//	//ImGui_ImplSDL2_ProcessEvent(&e);
	//}
	auto inputs = SDL_GetKeyboardState(nullptr);
	
	for (auto& binding : m_CommandsKeyboard)
	{
		if (binding.first.eventType != SDL_KEYDOWN) continue;
		if (inputs[binding.first.scancode])
		{
			binding.second->Execute();
		}
	}

	if (inputs[SDL_SCANCODE_ESCAPE])
		return false;

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type)
		{
		case SDL_KEYUP:
		{
			for (auto& binding : m_CommandsKeyboard)
			{
				if (e.key.keysym.scancode == binding.first.scancode)
				{
					binding.second->Execute();
				}
			}
			break;
		}
			case SDL_QUIT:
			{
				return false;
				break;
			}
		}
	}


	return true;
}
