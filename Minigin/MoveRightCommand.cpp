#include "MoveRightCommand.h"
#include "GameObject.h"
#include "Minigin.h"

void dae::MoveRightCommand::Execute(GameObject& go)
{
	float xPos = go.GetWorldTransform().GetPosition().x + go.GetSpeed() * dae::Minigin::DELTATIME;
	go.SetWorldPosition(xPos, go.GetWorldTransform().GetPosition().y);
}
