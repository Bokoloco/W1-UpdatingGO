#include "PlaySoundCommand.h"
#include "ServiceLocator.h"

dae::PlaySoundCommand::PlaySoundCommand(GameObject& go)
	: dae::Command(go)
{
}

void dae::PlaySoundCommand::Execute()
{
	ServiceLocator::GetSoundSystem().Play(0);
}

