#include "BurgerCollisionComponent.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Utils.h"

dae::BurgerCollisionComponent::BurgerCollisionComponent(GameObject& go)
	: CollisionComponent(go)
{
	m_Texture = GetOwner()->GetTexture();
	auto bounds = GetOwner()->GetBoundingBox();
	m_WidthPiece = static_cast<int>(bounds->w / 4.f);

	m_Pieces.emplace_back(false, std::make_unique<SDL_Rect>(static_cast<int>(GetOwner()->GetWorldPosition().x), static_cast<int>(GetOwner()->GetWorldPosition().y), m_WidthPiece, static_cast<int>(bounds->h)));
	m_Pieces.emplace_back(false, std::make_unique<SDL_Rect>(static_cast<int>(GetOwner()->GetWorldPosition().x + m_WidthPiece), static_cast<int>(GetOwner()->GetWorldPosition().y), m_WidthPiece, static_cast<int>(bounds->h)));
	m_Pieces.emplace_back(false, std::make_unique<SDL_Rect>(static_cast<int>(GetOwner()->GetWorldPosition().x + (2 * m_WidthPiece)), static_cast<int>(GetOwner()->GetWorldPosition().y), m_WidthPiece, static_cast<int>(bounds->h)));
	m_Pieces.emplace_back(false, std::make_unique<SDL_Rect>(static_cast<int>(GetOwner()->GetWorldPosition().x + (3 * m_WidthPiece)), static_cast<int>(GetOwner()->GetWorldPosition().y), m_WidthPiece, static_cast<int>(bounds->h)));
}

void dae::BurgerCollisionComponent::Update()
{
	auto it = std::find_if(m_Pieces.begin(), m_Pieces.end(), [&](auto const& elem) {return !elem.first;});
	if (it == m_Pieces.end())
	{

	}
}

void dae::BurgerCollisionComponent::Render() const
{
	for (int i{}; i < m_Pieces.size(); ++i)
	{
		SDL_Rect sourceRect{ GetOwner()->GetSourceRect()->x + (i * (m_WidthPiece / 2)), GetOwner()->GetSourceRect()->y, m_WidthPiece / 2, GetOwner()->GetSourceRect()->h };
		Renderer::GetInstance().RenderTexture(*m_Texture, &sourceRect, static_cast<float>(m_Pieces[i].second->x), static_cast<float>(m_Pieces[i].second->y), static_cast<float>(m_Pieces[i].second->w), static_cast<float>(m_Pieces[i].second->h));
	}
}

void dae::BurgerCollisionComponent::OnColliding(GameObject& go)
{
	if (go.ActorHasTag(dae::make_sdbm_hash("Player")))
	{
		int xPosCollidingPlayer = static_cast<int>(go.GetWorldPosition().x + (go.GetBoundingBox()->w / 2));

		for (int i{}; i < m_Pieces.size(); ++i)
		{
			int xPosOwner = m_Pieces[i].second->x + m_Pieces[i].second->w;
			if (xPosCollidingPlayer <= xPosOwner && xPosCollidingPlayer >= m_Pieces[i].second->x && !m_Pieces[i].first)
			{
				m_Pieces[i].first = true;
				m_Pieces[i].second->y += 3;
			}
		}
	}
}