#include "CollisionComponent.h"
#include <iostream>
#include "GameObject.h"

dae::CollisionComponent::CollisionComponent(GameObject& go)
	: BaseComponent(go)
{
}

dae::CollisionComponent::~CollisionComponent()
{
}

void dae::CollisionComponent::Update()
{

}

void dae::CollisionComponent::Render() const
{

}