#include "CollisionComponent.h"
#include <iostream>
#include "GameObject.h"
#include "SoundSystem.h"

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
	if (go.ActorHasTag(dae::make_sdbm_hash("Ladder")))
		std::cout << "Overlapping!!!!" << std::endl;
}
