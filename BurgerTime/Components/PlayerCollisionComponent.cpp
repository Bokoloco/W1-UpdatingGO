#include "PlayerCollisionComponent.h"
#include "GameObject.h"
#include "MoveDownLadderComponent.h"
#include "Utils.h"

dae::PlayerCollisionComponent::PlayerCollisionComponent(GameObject& go)
	: CollisionComponent(go)
{
	m_pMoveDownLadderComponent = GetOwner()->GetComponent<MoveDownLadderComponent>();
}

void dae::PlayerCollisionComponent::Update()
{

}

void dae::PlayerCollisionComponent::OnEnter(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("Ladder")))
	{
		m_pMoveDownLadderComponent->SetCanMoveDownLadder(true);
		m_pMoveDownLadderComponent->SetMoveToHeight(go.GetWorldPosition().y + go.GetBoundingBox()->h);
	}
}

void dae::PlayerCollisionComponent::OnExit(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("Ladder")))
		m_pMoveDownLadderComponent->SetCanMoveDownLadder(false);
}