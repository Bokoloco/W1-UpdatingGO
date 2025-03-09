#include <SDL.h>
#include "InputManager.h"
#include <iostream>
//#include <backends/imgui_impl_sdl2.h>
#include "Command.h"
#include "MoveLeft.h"
#include "MoveDownCommand.h"
#include "MoveUpCommand.h"
#include "MoveRightCommand.h"
#include "ControllerInput.h"


void dae::InputManager::AddPlayer1(GameObject & go)
{
	m_pPlayer1 = &go;
}

void dae::InputManager::AddPlayer2(GameObject& go)
{
	m_pPlayer2 = &go;
}

void dae::InputManager::BeginPlay()
{
	m_pControllerInput = std::make_unique<ControllerInput>();
	m_MoveLeftCommand = std::make_unique<dae::MoveLeft>();
	m_MoveDownCommand = std::make_unique<dae::MoveDownCommand>();
	m_MoveUpCommand = std::make_unique<dae::MoveUpCommand>();
	m_MoveRightCommand = std::make_unique<dae::MoveRightCommand>();
}

bool dae::InputManager::ProcessInput()
{
	m_pControllerInput.get()->Update();
	if (m_pControllerInput->CheckButtonPressed(1)) m_MoveUpCommand->Execute(*m_pPlayer2);
	if (m_pControllerInput->CheckButtonPressed(2)) m_MoveDownCommand->Execute(*m_pPlayer2);
	if (m_pControllerInput->CheckButtonPressed(4)) m_MoveLeftCommand->Execute(*m_pPlayer2);
	if (m_pControllerInput->CheckButtonPressed(8)) m_MoveRightCommand->Execute(*m_pPlayer2);

	//const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type)
		{
		case SDL_QUIT:
		{
			return false;
			break;
		}
		case SDL_KEYDOWN:
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w:
				m_MoveUpCommand->Execute(*m_pPlayer1);
				break;
			case SDLK_a:
				m_MoveLeftCommand->Execute(*m_pPlayer1);
				break;
			case SDLK_s:
				m_MoveDownCommand->Execute(*m_pPlayer1);
				break;
			case SDLK_d:
				m_MoveRightCommand->Execute(*m_pPlayer1);
				break;
			default:
				break;
			}
		}
		default:
			break;
		}
		// etc...

		//ImGui_ImplSDL2_ProcessEvent(&e);
	}

	return true;
}
