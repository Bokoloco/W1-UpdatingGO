#include "PauseMusicCommand.h"
#include "ServiceLocator.h"

dae::PauseMusicCommand::PauseMusicCommand(GameObject& go)

	: Command(go)
{}

void dae::PauseMusicCommand::Execute()
{
	dae::ServiceLocator::GetSoundSystem().PauseMusic();
}

