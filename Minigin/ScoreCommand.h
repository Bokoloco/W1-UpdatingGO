#pragma once
#include "Command.h"
#include "ScoreComponent.h"

namespace dae
{
	class GameObject;
	class ScoreCommand : public Command
	{
	public:
		ScoreCommand(ScoreAmount amount);

		void Execute(GameObject& go) override;

	private:
		ScoreAmount m_Amount;
	};
}
