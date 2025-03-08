#include <SDL.h>
#include "InputManager.h"
#include <iostream>
#include <backends/imgui_impl_sdl2.h>
#include "Command.h"
#include "MoveLeft.h"
#include "MoveDownCommand.h"

void dae::InputManager::AddPlayer1(GameObject & go)
{
	m_pPlayer1 = &go;
}

void dae::InputManager::BeginPlay()
{
	m_MoveLeftCommand = std::make_unique<dae::MoveLeft>();
	m_MoveDownCommand = std::make_unique<dae::MoveDownCommand>();
}

bool dae::InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) 
		{
			return false;
		}
		if (e.type == SDL_KEYDOWN) 
		{
			if (e.key.keysym.scancode == SDL_SCANCODE_A) m_MoveLeftCommand.get()->Execute(*m_pPlayer1);
			if (e.key.keysym.scancode == SDL_SCANCODE_S) m_MoveDownCommand.get()->Execute(*m_pPlayer1);
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		// etc...

		//ImGui_ImplSDL2_ProcessEvent(&e);
	}

	return true;
}
