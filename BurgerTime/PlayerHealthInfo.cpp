#include "PlayerHealthInfo.h"
#include "TextComponent.h"
#include "GameObject.h"

#include <string>


dae::PlayerHealthInfo::PlayerHealthInfo(GameObject& go)
	: BaseComponent(go)
	, m_Lives{3}
{
	m_pTextComponent = GetOwner()->GetComponent<TextComponent>();
	
	m_pTextComponent->SetText("#Lives: " + std::to_string(m_Lives));
}

void dae::PlayerHealthInfo::OnNotify(dae::ObserverEvent e)
{
	if (e == dae::ObserverEvent::LivesDecrease)
	{
		m_pTextComponent->SetText("#Lives: " + std::to_string(--m_Lives));
	}
}