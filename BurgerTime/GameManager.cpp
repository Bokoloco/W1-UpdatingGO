#include "GameManager.h"
#include "Utils.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GameObject.h"
#include "Level1.h"
#include "Level2.h"
#include "ResourceManager.h"

dae::GameManager::~GameManager()
{
}

void dae::GameManager::SetGameMode(GameMode mode)
{
	m_GameMode = mode;
}

void dae::GameManager::SwitchScene(unsigned int sceneName)
{
	if (sceneName == dae::make_sdbm_hash("MainMenu"))
	{
		m_pPlayer1 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player1"));
		if (m_GameMode != GameMode::SinglePlayer) m_pPlayer2 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player2"));

		SceneManager::GetInstance().SwitchScene(sceneName);
	}
	else
	{
		SceneManager::GetInstance().SwitchScene(sceneName);
		switch (m_GameMode)
		{
		case dae::GameMode::SinglePlayer:
		{
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer1));
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_HealthObserverObject));
			break;
		}
		case dae::GameMode::Coop:
		{
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer1));
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer2));
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_HealthObserverObject));
			break;
		}
		case dae::GameMode::Versus:
		{
			m_pPlayer2->AddTag(dae::make_sdbm_hash("MrHotDog"));
			m_pPlayer2->SetSourceRectTexture(32, 32, 15, 16);
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer1));
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer2));
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_HealthObserverObject));
			break;
		}
		default:
			break;
		}
	}
}

void dae::GameManager::ResetScene()
{
	m_pPlayer1 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player1"));
	if (m_GameMode != GameMode::SinglePlayer) m_pPlayer2 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player2"));

	m_HealthObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("HealthObComponent"));

	auto curScene = SceneManager::GetInstance().GetCurrentScene();
	curScene->m_ReadyForDelete = true;

	auto level1 = std::make_unique<dae::Level1>(make_sdbm_hash("Level1"));

	SwitchScene(make_sdbm_hash("Level1"));

	SceneManager::GetInstance().QueueRemoveScene(curScene);
}

void dae::GameManager::AddPlayer1(std::unique_ptr<GameObject> player1)
{
	m_pPlayer1 = std::move(player1);
}

void dae::GameManager::AddPlayer2(std::unique_ptr<GameObject> player2)
{
	m_pPlayer2 = std::move(player2);
}

dae::GameObject* dae::GameManager::Player1()
{
	return m_pPlayer1.get();
}

void dae::GameManager::AddHealthObserver(std::unique_ptr<GameObject> healthObserverObject)
{
	m_HealthObserverObject = std::move(healthObserverObject);
}

void dae::GameManager::NextLevel()
{
	m_pPlayer1 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player1"));
	if (m_GameMode != GameMode::SinglePlayer) m_pPlayer2 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player2"));

	m_HealthObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("HealthObComponent"));

	auto curScene = SceneManager::GetInstance().GetCurrentScene();
	curScene->m_ReadyForDelete = true;

	auto level = std::make_unique<dae::Level2>();

	SwitchScene(make_sdbm_hash("Level2"));

	SceneManager::GetInstance().QueueRemoveScene(curScene);
}

