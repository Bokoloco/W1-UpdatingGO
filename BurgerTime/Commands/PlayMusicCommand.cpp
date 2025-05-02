#include "PlayMusicCommand.h"
#include "ServiceLocator.h"

dae::PlayMusicCommand::PlayMusicCommand(GameObject& go, const SoundId soundId)
	: Command(go)
	, m_SoundId {soundId}
{}

void dae::PlayMusicCommand::Execute()
{
	dae::ServiceLocator::GetSoundSystem().PlayMusic(m_SoundId);
}
