#include "MoveUpCommand.h"
#include "GameObject.h"
#include "Minigin.h"

void dae::MoveUpCommand::Execute(GameObject& go)
{
	float yPos = go.GetWorldTransform().GetPosition().y - go.GetSpeed() * dae::Minigin::DELTATIME;
	go.SetWorldPosition(go.GetWorldTransform().GetPosition().x, yPos);
}
