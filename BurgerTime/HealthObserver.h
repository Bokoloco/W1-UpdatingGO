#pragma once
#include "Observer.h"

namespace dae
{
	class GameObject;
	class HealthObserver final : public Observer
	{
	public:
		HealthObserver() ;
		~HealthObserver() = default;

		void OnNotify(unsigned int eventID, GameObject* go);

		unsigned int GetLives() const;

		bool m_HasLivesChanged{true};

	private:
		unsigned int m_LowerHealth{};

		unsigned int m_Lives{3};
	};
}


