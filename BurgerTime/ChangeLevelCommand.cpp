#include "ChangeLevelCommand.h"
#include "GameObject.h"
#include "GameManager.h"

dae::ChangeLevelCommand::ChangeLevelCommand(GameObject& go)
	: Command(go)
{
}

void dae::ChangeLevelCommand::Execute()
{
	GameManager::GetInstance().NextLevel();
}
