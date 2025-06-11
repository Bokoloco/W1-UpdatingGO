#include "MuteSoundCommand.h"
#include <ServiceLocator.h>

dae::MuteSoundCommand::MuteSoundCommand(GameObject& go, const int maxVolume)
	: Command(go)
	, m_MaxVolume{maxVolume}
{}

void dae::MuteSoundCommand::Execute()
{
	int volume = m_IsMuted ? 0 : m_MaxVolume;
	dae::ServiceLocator::GetSoundSystem().ChangeMasterVolume(volume);
	m_IsMuted = !m_IsMuted;
}
