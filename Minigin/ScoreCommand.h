#pragma once
#include "Command.h"
#include "ScoreComponent.h"

namespace dae
{
	class GameObject;
	class ScoreCommand : public Command
	{
	public:
		ScoreCommand(GameObject& go, ScoreAmount amount);

		void Execute() override;

	private:
		ScoreAmount m_Amount;
	};
}
