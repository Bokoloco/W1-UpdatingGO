#pragma once

#include "Observer.h"

namespace dae
{
	class GameObject;
	class ScoreObserver final : public Observer
	{
	public: 
		ScoreObserver() = default;
		~ScoreObserver() = default;

		void OnNotify(unsigned int eventID, GameObject* go);

	private:
		unsigned int m_HashBurgerDropped{};
		unsigned int m_HashMrHotDog{};
		unsigned int m_HashMrPickle{};
		unsigned int m_HashMrEgg{};
		
	};

}