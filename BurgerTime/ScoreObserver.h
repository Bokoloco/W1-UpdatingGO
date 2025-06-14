#pragma once

#include "Observer.h"

namespace dae
{
	class GameObject;
	class ScoreObserver final : public Observer
	{
	public: 
		ScoreObserver();
		~ScoreObserver() = default;

		void OnNotify(unsigned int eventID, GameObject* go);

		unsigned int GetScore() const;
		bool m_HasScoreChanged{ true };

	private:
		unsigned int m_HashBurgerDropped{};
		unsigned int m_HashMrHotDog{};
		unsigned int m_HashMrPickle{};
		unsigned int m_HashMrEgg{};
		unsigned int m_HashEnemiesOnBurger{};


		unsigned int m_Score{};
		
	};

}