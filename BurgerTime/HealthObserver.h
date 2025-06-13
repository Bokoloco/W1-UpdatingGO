#pragma once
#include "Observer.h"

namespace dae
{
	class GameObject;
	class HealthObserver final : public Observer
	{
	public:
		friend class HealthDisplayComponent;
		HealthObserver() ;
		~HealthObserver() = default;

		void OnNotify(unsigned int eventID, GameObject* go);

		unsigned int GetLives() const;

	protected:
		bool m_HasLivesChanged{true};
		bool m_CanChangeLives{true};

	private:
		unsigned int m_LowerHealth{};

		unsigned int m_Lives{ 4 };
	};
}


