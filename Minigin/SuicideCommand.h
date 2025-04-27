#pragma once
#include "Command.h"

namespace dae
{
	class SuicideCommand : public Command
	{
	public:
		SuicideCommand(GameObject& go);
		~SuicideCommand() = default;

		void Execute() override;
	};
}