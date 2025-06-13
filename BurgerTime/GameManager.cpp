#include "GameManager.h"
#include "Utils.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GameObject.h"

dae::GameManager::~GameManager()
{
}

void dae::GameManager::SetGameMode(GameMode mode)
{
	m_GameMode = mode;
}

void dae::GameManager::SwitchScene(unsigned int sceneName)
{
	if (sceneName == dae::make_sdbm_hash("Level1"))
	{
		SceneManager::GetInstance().SwitchScene(sceneName);
		switch (m_GameMode)
		{
		case dae::GameMode::SinglePlayer:
		{
			SceneManager::GetInstance().GetNextScene()->Add(std::move(m_pPlayer1));
			break;
		}
		case dae::GameMode::Coop:
		{
			SceneManager::GetInstance().GetNextScene()->Add(std::move(m_pPlayer1));
			SceneManager::GetInstance().GetNextScene()->Add(std::move(m_pPlayer2));
			break;
		}
		case dae::GameMode::Versus:
		{
			m_pPlayer2->AddTag(dae::make_sdbm_hash("MrHotDog"));
			m_pPlayer2->SetSourceRectTexture(32, 32, 15, 16);
			SceneManager::GetInstance().GetNextScene()->Add(std::move(m_pPlayer1));
			SceneManager::GetInstance().GetNextScene()->Add(std::move(m_pPlayer2));
			break;
		}
		default:
			break;
		}
	}
}

void dae::GameManager::AddPlayer1(std::unique_ptr<GameObject> player1)
{
	m_pPlayer1 = std::move(player1);
}

void dae::GameManager::AddPlayer2(std::unique_ptr<GameObject> player2)
{
	m_pPlayer2 = std::move(player2);
}

