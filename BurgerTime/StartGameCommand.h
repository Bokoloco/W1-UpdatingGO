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
	};

	class StartCoopGameCommand : public Command
	{
	public:
		StartCoopGameCommand(GameObject& go);

		void Execute() override;
	};

	class StartVersusGameCommand : public Command
	{
	public:
		StartVersusGameCommand(GameObject& go);

		void Execute() override;
	};
}