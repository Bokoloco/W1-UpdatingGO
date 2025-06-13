#include "HealthObserver.h"
#include "Utils.h"
#include "SceneManager.h"

dae::HealthObserver::HealthObserver()
{
	m_LowerHealth = dae::make_sdbm_hash("LowerHealth");
}

void dae::HealthObserver::OnNotify(unsigned int eventID, GameObject*)
{
	if (eventID == m_LowerHealth)
	{
		if (m_Lives > 0) --m_Lives;
		m_HasLivesChanged = true;
		//dae::SceneManager::GetInstance().m_Pause = true;
	}
}

unsigned int dae::HealthObserver::GetLives() const
{
	return m_Lives;
}
