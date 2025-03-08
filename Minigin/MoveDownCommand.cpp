#include "MoveDownCommand.h"
#include "GameObject.h"
#include "Minigin.h"

dae::MoveDownCommand::MoveDownCommand()
	: m_Speed{ .1f }
{}

void dae::MoveDownCommand::Execute(GameObject& go)
{
	float yPos = go.GetWorldTransform().GetPosition().y + m_Speed * dae::Minigin::DELTATIME;
	go.SetWorldPosition(go.GetWorldTransform().GetPosition().x, yPos);
}
