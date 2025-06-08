#pragma once

namespace dae
{
	enum class ObserverEvent
	{
		LivesDecrease,
		SmallScoreIncrease,
		BigScoreIncrease,
		GameWon
	};

	class GameObject;
	class Observer
	{
	public:
		virtual ~Observer() {};
		virtual void OnNotify(unsigned int eventID, GameObject* go) = 0;
	};
}