#include "HealthObserver.h"
#include "Utils.h"
#include "SceneManager.h"
#include <ServiceLocator.h>

dae::HealthObserver::HealthObserver()
{
	m_LowerHealth = dae::make_sdbm_hash("LowerHealth");
}

void dae::HealthObserver::OnNotify(unsigned int eventID, GameObject*)
{
	if (eventID == m_LowerHealth && m_CanChangeLives)
	{
		if (m_Lives > 0) --m_Lives;
		m_HasLivesChanged = true;
		dae::ServiceLocator::GetSoundSystem().PlayMusic(dae::make_sdbm_hash("Death"), 0);
		//dae::SceneManager::GetInstance().m_Pause = true;
	}
}

unsigned int dae::HealthObserver::GetLives() const
{
	return m_Lives;
}
