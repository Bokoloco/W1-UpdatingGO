#include "HealthObserver.h"
#include "Utils.h"

dae::HealthObserver::HealthObserver()
{
	m_LowerHealth = dae::make_sdbm_hash("LowerHealth");
}

void dae::HealthObserver::OnNotify(unsigned int eventID, GameObject*)
{
	if (eventID == m_LowerHealth)
	{
		--m_Lives;
		m_HasLivesChanged = true;
	}
}

unsigned int dae::HealthObserver::GetLives() const
{
	return m_Lives;
}
