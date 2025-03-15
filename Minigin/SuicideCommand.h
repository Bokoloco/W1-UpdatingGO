#pragma once
#include "Command.h"

namespace dae
{
	class SuicideCommand : public Command
	{
	public:
		SuicideCommand() = default;
		~SuicideCommand() = default;

		void Execute(GameObject& go) override;
	};
}