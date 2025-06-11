#pragma once
#include "Command.h"
#include <memory>
#include "Subject.h"

namespace dae
{
	class Observer;
	class DecreaseLivesCommand final : public Command
	{
	public:
		DecreaseLivesCommand(GameObject& go);

		void Execute() override;

		void AddObserver(Observer& observer);

	private:
		std::unique_ptr<Subject> m_pSubject{};
	};
}


