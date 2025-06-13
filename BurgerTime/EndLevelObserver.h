#pragma once
#include "Observer.h"

namespace dae
{
	class GameObject;
	class EndLevelObserver final : public Observer
	{
	public:
		EndLevelObserver();
		~EndLevelObserver() = default;

		void OnNotify(unsigned int eventID, GameObject* go);

	private:
		unsigned int m_HashBurgerHitPlate{};

		unsigned int m_AmountBurgersHitPlate{};

	};

}