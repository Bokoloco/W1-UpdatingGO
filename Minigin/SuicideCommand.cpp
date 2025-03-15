#include "SuicideCommand.h"
#include "GameObject.h"
#include "HealthComponent.h"

void dae::SuicideCommand::Execute(GameObject& go)
{
	(&go)->GetComponent<dae::HealthComponent>()->DecreaseLives();
}
