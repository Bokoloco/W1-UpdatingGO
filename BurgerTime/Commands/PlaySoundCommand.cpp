#include "PlaySoundCommand.h"
#include "ServiceLocator.h"

dae::PlaySoundCommand::PlaySoundCommand(GameObject& go, const SoundId soundId)
	: Command(go)
	, m_SoundId{soundId}
{}

void dae::PlaySoundCommand::Execute()
{
	ServiceLocator::GetSoundSystem().Play(m_SoundId);
}
