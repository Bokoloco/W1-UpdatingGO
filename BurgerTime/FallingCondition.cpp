#include "FallingCondition.h"
#include "GameObject.h"
#include "BurgerPartsCollisionComponent.h"

dae::FallingCondition::FallingCondition(GameObject& go, bool toFallTransition)
	: FSMCondition(go)
	, m_ToFallTransition{toFallTransition}
{
	for (int i{}; i < GetOwner()->GetChildCount(); ++i)
	{
		if (auto casted = GetOwner()->GetChildAt(i)->GetComponent<BurgerPartsCollisionComponent>())
		{
			m_CollisionComponents.push_back(casted);
		}
	}
}

bool dae::FallingCondition::Evaluate() const
{
	auto it = std::find_if(m_CollisionComponents.begin(), m_CollisionComponents.end(), [&](BurgerPartsCollisionComponent* comp) {return !comp->HasBeenSteppedOn(); });

	if (m_ToFallTransition)
		return it == m_CollisionComponents.end();

	return it != m_CollisionComponents.end();
}