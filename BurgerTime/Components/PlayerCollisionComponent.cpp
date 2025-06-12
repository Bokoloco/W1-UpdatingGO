#include "PlayerCollisionComponent.h"
#include "GameObject.h"
#include "MoveDownLadderComponent.h"
#include "Utils.h"
#include <iostream>

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
	if (go.ActorHasTag(dae::make_sdbm_hash("Ladder")) /*&& !m_pMoveDownLadderComponent->CanMoveOnLadder()*/)
	{
		float xPosOwner = GetOwner()->GetWorldPosition().x + (GetOwner()->GetBoundingBox()->w / 2);
		float xPosCollidingObject = go.GetWorldPosition().x + go.GetBoundingBox()->w;

		/*float yPosOwner = GetOwner()->GetWorldPosition().y + (GetOwner()->GetBoundingBox()->h / 2);
		float yPosOwnerBottom = GetOwner()->GetWorldPosition().y + (GetOwner()->GetBoundingBox()->h);
		float yPosCollidingObjectBottom = go.GetWorldPosition().y + go.GetBoundingBox()->h;*/

		if ((xPosOwner <= xPosCollidingObject && xPosOwner >= go.GetWorldPosition().x) /*&& (yPosOwner <= go.GetWorldPosition().y || yPosOwnerBottom > yPosCollidingObjectBottom)*/)
		{
			//std::cout << "In colliding laddr" << std::endl;

			m_pMoveDownLadderComponent->SetCanMoveDownLadder(true);
			m_pMoveDownLadderComponent->SetXPosOnLadder(go.GetWorldPosition().x + (go.GetBoundingBox()->w / 2));
			m_pMoveDownLadderComponent->SetMoveToHeight(go.GetWorldPosition().y, go.GetWorldPosition().y + go.GetBoundingBox()->h);
		}
		/*else
			m_pMoveDownLadderComponent->SetCanMoveDownLadder(false);*/
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("LadderPlatform")))
	{
		float yPosOwnerBottom = GetOwner()->GetWorldPosition().y + (GetOwner()->GetBoundingBox()->h);
		float yPosCollidingObjectBottom = go.GetWorldPosition().y + go.GetBoundingBox()->h;

		if (yPosOwnerBottom >= go.GetWorldPosition().y && yPosOwnerBottom <= yPosCollidingObjectBottom)
		{
			m_pMoveDownLadderComponent->SetYPosOnPltform(go.GetWorldPosition().y + 1.f);
			m_pMoveDownLadderComponent->SetCanMoveHorizontally(true);
		}
		else
			m_pMoveDownLadderComponent->SetCanMoveHorizontally(false);
	}
}

void dae::PlayerCollisionComponent::OnEnter(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("LadderPlatform")))
	{
		m_pMoveDownLadderComponent->SetCanMoveDownLadder(false);
		m_pMoveDownLadderComponent->SetCanMoveHorizontally(true);
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("Ladder")) /*&& !m_pMoveDownLadderComponent->CanMoveOnLadder()*/)
	{
		float xPosOwner = GetOwner()->GetWorldPosition().x + (GetOwner()->GetBoundingBox()->w / 2);
		float xPosCollidingObject = go.GetWorldPosition().x + go.GetBoundingBox()->w;

		/*float yPosOwner = GetOwner()->GetWorldPosition().y + (GetOwner()->GetBoundingBox()->h / 2);
		float yPosOwnerBottom = GetOwner()->GetWorldPosition().y + (GetOwner()->GetBoundingBox()->h);
		float yPosCollidingObjectBottom = go.GetWorldPosition().y + go.GetBoundingBox()->h;*/

		if ((xPosOwner <= xPosCollidingObject && xPosOwner >= go.GetWorldPosition().x) /*&& (yPosOwner <= go.GetWorldPosition().y || yPosOwnerBottom > yPosCollidingObjectBottom)*/)
		{

			m_pMoveDownLadderComponent->SetCanMoveDownLadder(true);
			m_pMoveDownLadderComponent->SetMoveToHeight(go.GetWorldPosition().y, go.GetWorldPosition().y + go.GetBoundingBox()->h/* +5.f*/);
		}
	}
}

void dae::PlayerCollisionComponent::OnExit(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("Ladder")))
	{
		m_pMoveDownLadderComponent->SetCanMoveDownLadder(false);
		m_pMoveDownLadderComponent->RemoveLadderFromList(go.GetWorldPosition().y, go.GetWorldPosition().y + go.GetBoundingBox()->h);
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("LadderPlatform")))
	{
		if (m_pMoveDownLadderComponent->CanMoveOnLadder())	m_pMoveDownLadderComponent->SetCanMoveHorizontally(false);
	}
}