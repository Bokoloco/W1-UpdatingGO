#include "PlayerCollisionComponent.h"
#include "GameObject.h"
#include "MoveDownLadderComponent.h"
#include "Utils.h"
#include <iostream>
#include "Observer.h"
#include "Subject.h"
#include "../GameManager.h"

dae::PlayerCollisionComponent::PlayerCollisionComponent(GameObject& go)
	: CollisionComponent(go)
{
	m_pMoveDownLadderComponent = GetOwner()->GetComponent<MoveDownLadderComponent>();
	m_pSubject = std::make_unique<Subject>();
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

		if ((xPosOwner <= xPosCollidingObject && xPosOwner >= go.GetWorldPosition().x))
		{
			m_pMoveDownLadderComponent->SetCanMoveDownLadder(true);
			m_pMoveDownLadderComponent->SetXPosOnLadder(go.GetWorldPosition().x + (go.GetBoundingBox()->w / 2));
			m_pMoveDownLadderComponent->SetMoveToHeight(go.GetWorldPosition().y, go.GetWorldPosition().y + go.GetBoundingBox()->h);
		}
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
	if (go.ActorHasTag(dae::make_sdbm_hash("Enemy")) || (GameManager::GetInstance().GetCurrentGameMode() == GameMode::Versus && go.ActorHasTag(dae::make_sdbm_hash("Player2"))))
	{
		float xPosEnemy = go.GetWorldPosition().x + (go.GetBoundingBox()->w / 2);

		if (xPosEnemy >= GetOwner()->GetLocalPosition().x && xPosEnemy <= GetOwner()->GetLocalPosition().x + GetOwner()->GetBoundingBox()->w)
		{

			float yPosEnemy = go.GetLocalPosition().y + 4 * (go.GetBoundingBox()->h / 5);
			float kneeOwner = GetOwner()->GetLocalPosition().y + 4 * (GetOwner()->GetBoundingBox()->h / 5);
			if (yPosEnemy >= kneeOwner && yPosEnemy <= GetOwner()->GetLocalPosition().y + GetOwner()->GetBoundingBox()->h)
			{
				m_pSubject->NotifyObservers(dae::make_sdbm_hash("LowerHealth"), GetOwner());
				m_pMoveDownLadderComponent->m_StopMoving = true;
			}
		}
	}
}

void dae::PlayerCollisionComponent::OnEnter(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("LadderPlatform")))
	{
		m_pMoveDownLadderComponent->SetCanMoveDownLadder(false);
		m_pMoveDownLadderComponent->SetCanMoveHorizontally(true);
	}
	if (go.ActorHasTag(dae::make_sdbm_hash("Ladder")))
	{
		float xPosOwner = GetOwner()->GetWorldPosition().x + (GetOwner()->GetBoundingBox()->w / 2);
		float xPosCollidingObject = go.GetWorldPosition().x + go.GetBoundingBox()->w;

		if ((xPosOwner <= xPosCollidingObject && xPosOwner >= go.GetWorldPosition().x))
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

void dae::PlayerCollisionComponent::AddObserver(Observer& observer)
{
	m_pSubject->AddObserver(observer);
}
