#include "ScoreCommand.h"
#include "GameObject.h"

dae::ScoreCommand::ScoreCommand(GameObject& go, ScoreAmount amount)
	: m_Amount{amount}
	, Command(go)
{}

void dae::ScoreCommand::Execute()
{
	GetGameObject()->GetComponent<ScoreComponent>()->IncreaseScore(m_Amount);

}