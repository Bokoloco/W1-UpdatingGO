#include "SuicideCommand.h"
#include "GameObject.h"
#include "HealthComponent.h"

dae::SuicideCommand::SuicideCommand(GameObject& go)
	: Command(go)
{
}

void dae::SuicideCommand::Execute()
{
	GetGameObject()->GetComponent<dae::HealthComponent>()->DecreaseLives();
}
