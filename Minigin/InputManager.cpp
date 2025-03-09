#include <SDL.h>
#include "InputManager.h"
#include <iostream>
//#include <backends/imgui_impl_sdl2.h>
#include "Command.h"
#include "MoveLeft.h"
#include "MoveDownCommand.h"
#include "MoveUpCommand.h"
#include "MoveRightCommand.h"


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
	m_pControllerInput = std::make_unique<dae::ControllerInput>();
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
		if (e.type == SDL_QUIT) 
		{
			return false;
		}
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.scancode == SDL_SCANCODE_W) m_MoveUpCommand->Execute(*m_pPlayer1);
			if (e.key.keysym.scancode == SDL_SCANCODE_A) m_MoveLeftCommand->Execute(*m_pPlayer1);
			if (e.key.keysym.scancode == SDL_SCANCODE_S) m_MoveDownCommand->Execute(*m_pPlayer1);
			if (e.key.keysym.scancode == SDL_SCANCODE_D) m_MoveRightCommand->Execute(*m_pPlayer1);
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		// etc...

		//ImGui_ImplSDL2_ProcessEvent(&e);
	}

	return true;
}
