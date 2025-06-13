#include "MuteSoundCommand.h"
#include <ServiceLocator.h>

dae::MuteSoundCommand::MuteSoundCommand(GameObject& go, const int maxVolume)
	: Command(go)
	, m_MaxVolume{maxVolume}
{}

void dae::MuteSoundCommand::Execute()
{
	int volume = m_IsMuted ? m_MaxVolume : 0;
	dae::ServiceLocator::GetSoundSystem().ChangeMasterVolume(volume);
	m_IsMuted = !m_IsMuted;
}
