#include "MoveLeft.h"
#include "GameObject.h"
#include "Minigin.h"
#include <iostream>

dae::MoveLeft::MoveLeft()
	: m_Speed{.1f}
{}

void dae::MoveLeft::Execute(GameObject& go)
{
	float xPos = go.GetWorldTransform().GetPosition().x - m_Speed * dae::Minigin::DELTATIME;
	go.SetWorldPosition(xPos, go.GetWorldTransform().GetPosition().y);
}