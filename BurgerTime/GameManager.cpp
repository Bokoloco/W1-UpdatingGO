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
			SceneManager::GetInstance().GetNextScene()->Add(std::move(m_pPlayer1));
			break;
		case dae::GameMode::Coop:
			break;
		case dae::GameMode::Versus:
			break;
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

