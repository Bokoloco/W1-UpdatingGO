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
	GameManager::GetInstance().SetGameMode(GameMode::SinglePlayer);
	GameManager::GetInstance().SwitchScene(dae::make_sdbm_hash("Level1"));
}
