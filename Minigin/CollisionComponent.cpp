#include "CollisionComponent.h"
#include <iostream>
#include "GameObject.h"

dae::CollisionComponent::CollisionComponent(GameObject& go)
	: BaseComponent(go)
{
}

void dae::CollisionComponent::Update()
{

}

void dae::CollisionComponent::Render() const
{

}

void dae::CollisionComponent::OnEnter(GameObject& go)
{
	std::cout << "Overlapping!!!!" << std::endl;
}
