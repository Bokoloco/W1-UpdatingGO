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

void dae::PlayerCollisionComponent::OnColliding(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("Ladder")) && !m_pMoveDownLadderComponent->CanMoveOnLadder())
	{
		float xPosOwner = GetOwner()->GetWorldPosition().x + (GetOwner()->GetBoundingBox()->w / 2);
		float xPosCollidingObject = go.GetWorldPosition().x + go.GetBoundingBox()->w;

		if (xPosOwner <= xPosCollidingObject && xPosOwner >= go.GetWorldPosition().x)
		{
			m_pMoveDownLadderComponent->SetCanMoveDownLadder(true);
			m_pMoveDownLadderComponent->SetMoveToHeight(go.GetWorldPosition().y + go.GetBoundingBox()->h - GetOwner()->GetBoundingBox()->h);
		}
		else
			m_pMoveDownLadderComponent->SetCanMoveDownLadder(false);
	}
}

//void dae::PlayerCollisionComponent::OnEnter(GameObject& go)
//{
//}

void dae::PlayerCollisionComponent::OnExit(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("Ladder")))
		m_pMoveDownLadderComponent->SetCanMoveDownLadder(false);
}