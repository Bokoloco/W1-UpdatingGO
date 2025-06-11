#pragma once
#include "Command.h"

namespace dae
{

	class MuteSoundCommand : public Command
	{
	public:
		MuteSoundCommand(GameObject& go, const int maxVolume);

		void Execute() override;

	private:
		bool m_IsMuted{};

		const int m_MaxVolume{};
	};
}

