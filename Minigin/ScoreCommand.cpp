#include "ScoreCommand.h"
#include "GameObject.h"

dae::ScoreCommand::ScoreCommand(ScoreAmount amount)
	: m_Amount{amount}
{}

void dae::ScoreCommand::Execute(GameObject & go)
{
	(&go)->GetComponent<ScoreComponent>()->IncreaseScore(m_Amount);
}

