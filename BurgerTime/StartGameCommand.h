#pragma once
#include "Command.h"

namespace dae
{
	class GameObject;
	class StartSingleGameCommand : public Command
	{
	public:
		StartSingleGameCommand(GameObject& go);

		void Execute() override;

	private:
	};
}