#include "MoveLeft.h"
#include "GameObject.h"
#include "Minigin.h"
#include <iostream>

void dae::MoveLeft::Execute(GameObject& go)
{
	float xPos = go.GetWorldTransform().GetPosition().x - go.GetSpeed() * dae::Minigin::DELTATIME;
	go.SetWorldPosition(xPos, go.GetWorldTransform().GetPosition().y);
}