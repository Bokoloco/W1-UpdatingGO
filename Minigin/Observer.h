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
		Observer() = default;
		virtual ~Observer() {};
		Observer(const Observer& other) = delete;
		Observer(Observer&& other) = delete;
		Observer& operator=(const Observer& other) = default;
		Observer& operator=(Observer&& other) = default;

		virtual void OnNotify(unsigned int eventID, GameObject* go) = 0;
	};
}