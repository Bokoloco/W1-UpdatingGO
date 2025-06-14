#include "StartGameCommand.h"
#include "GameManager.h"
#include "Utils.h"
#include "GameObject.h"

dae::StartSingleGameCommand::StartSingleGameCommand(GameObject& go)
	: Command(go)
{
}

void dae::StartSingleGameCommand::Execute()
{
	if (GameManager::GetInstance().InMainMenu)
	{
		GameManager::GetInstance().SetGameMode(GameMode::SinglePlayer);
		GameManager::GetInstance().SwitchScene(dae::make_sdbm_hash("Level1"));
	}
}

dae::StartCoopGameCommand::StartCoopGameCommand(GameObject& go)
	: Command(go)
{
}

void dae::StartCoopGameCommand::Execute()
{
	if (GameManager::GetInstance().InMainMenu)
	{
		GameManager::GetInstance().SetGameMode(GameMode::Coop);
		GameManager::GetInstance().SwitchScene(dae::make_sdbm_hash("Level1"));
	}
}

dae::StartVersusGameCommand::StartVersusGameCommand(GameObject& go)
	: Command(go)
{
}

void dae::StartVersusGameCommand::Execute()
{
	if (GameManager::GetInstance().InMainMenu)
	{
		GameManager::GetInstance().SetGameMode(GameMode::Versus);
		GameManager::GetInstance().SwitchScene(dae::make_sdbm_hash("Level1"));
	}
}

dae::MainMenuCommand::MainMenuCommand(GameObject& go)
	: Command(go)
{
}

void dae::MainMenuCommand::Execute()
{
	GameManager::GetInstance().SwitchScene(dae::make_sdbm_hash("MainMenu"));
}
