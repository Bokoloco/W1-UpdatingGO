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

	class Observer
	{
	public:
		virtual ~Observer() {};
		virtual void OnNotify(ObserverEvent e) = 0;
	};
}