#include "MoveDownCommand.h"
#include "GameObject.h"
#include "Minigin.h"

void dae::MoveDownCommand::Execute(GameObject& go)
{
	float yPos = go.GetWorldTransform().GetPosition().y + go.GetSpeed() * dae::Minigin::DELTATIME;
	go.SetWorldPosition(go.GetWorldTransform().GetPosition().x, yPos);
}
