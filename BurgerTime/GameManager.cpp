#include "GameManager.h"
#include "Utils.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GameObject.h"
#include "Level1.h"
#include "Level2.h"
#include "ResourceManager.h"
#include "Level3.h"
#include "./Components/MoveDownLadderComponent.h"

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
		m_HealthObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("HealthObComponent"));
		m_ScoreObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("ScoreObComponent"));

		SceneManager::GetInstance().SwitchScene(sceneName);

		InMainMenu = true;
	}
	else if (sceneName == dae::make_sdbm_hash("EndScreen"))
	{
		m_pPlayer1 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player1"));
		if (m_GameMode != GameMode::SinglePlayer) m_pPlayer2 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player2"));
		m_HealthObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("HealthObComponent"));
		m_ScoreObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("ScoreObComponent"));

		SceneManager::GetInstance().SwitchScene(sceneName);

		m_ScoreObserverObject->SetLocalPosition({ 200.f, 100.f, 0.f });
		SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_ScoreObserverObject));

		InMainMenu = true;
	}
	else
	{
		SceneManager::GetInstance().SwitchScene(sceneName);
		switch (m_GameMode)
		{
		case dae::GameMode::SinglePlayer:
		{
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer1));
			break;
		}
		case dae::GameMode::Coop:
		{
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer1));
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer2));

			break;
		}
		case dae::GameMode::Versus:
		{
			m_pPlayer2->AddTag(dae::make_sdbm_hash("MrHotDog"));
			m_pPlayer2->SetSourceRectTexture(32, 32, 15, 16);
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer1));
			SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_pPlayer2));
			break;
		}
		default:
			break;
		}

		SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_HealthObserverObject));
		SceneManager::GetInstance().GetCurrentScene()->Add(std::move(m_ScoreObserverObject));

		InMainMenu = false;
	}
}

void dae::GameManager::ResetScene()
{
	m_pPlayer1 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player1"));
	m_pPlayer1->GetComponent<dae::MoveDownLadderComponent>()->ResetComponent();
	if (m_GameMode != GameMode::SinglePlayer)
	{
		m_pPlayer2 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player2"));
		m_pPlayer2->GetComponent<dae::MoveDownLadderComponent>()->ResetComponent();
	}

	m_HealthObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("HealthObComponent"));
	m_ScoreObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("ScoreObComponent"));

	auto curScene = SceneManager::GetInstance().GetCurrentScene();
	curScene->m_ReadyForDelete = true;

	if (m_CurrentLevel == 0)
	{
		auto level = std::make_unique<dae::Level1>();
		m_pPlayer1->SetLocalPosition(level->m_Player1StartPos);
		SwitchScene(make_sdbm_hash("Level1"));
	}
	else if (m_CurrentLevel == 1)
	{
		auto level = std::make_unique<dae::Level2>();
		m_pPlayer1->SetLocalPosition(level->m_Player1StartPos);
		SwitchScene(make_sdbm_hash("Level2"));
	}
	else if (m_CurrentLevel == 2)
	{
		auto level = std::make_unique<dae::Level3>();
		m_pPlayer1->SetLocalPosition(level->m_Player1StartPos);
		SwitchScene(make_sdbm_hash("Level3"));
	}

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

dae::GameObject* dae::GameManager::Player1() const
{
	return m_pPlayer1.get();
}

dae::GameObject* dae::GameManager::ScoreObserverObject() const
{
	return m_ScoreObserverObject.get();
}

void dae::GameManager::AddHealthObserver(std::unique_ptr<GameObject> healthObserverObject)
{
	m_HealthObserverObject = std::move(healthObserverObject);
}

void dae::GameManager::AddScoreObserver(std::unique_ptr<GameObject> scoreObserverObject)
{
	m_ScoreObserverObject = std::move(scoreObserverObject);
}

void dae::GameManager::NextLevel()
{
	m_pPlayer1 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player1"));
	m_pPlayer1->GetComponent<dae::MoveDownLadderComponent>()->ResetComponent();

	if (m_GameMode != GameMode::SinglePlayer)
	{
		m_pPlayer2 = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("Player2"));
		m_pPlayer2->GetComponent<dae::MoveDownLadderComponent>()->ResetComponent();
	}

	m_HealthObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("HealthObComponent"));
	m_ScoreObserverObject = SceneManager::GetInstance().GetCurrentScene()->GetObjectsWithTag(make_sdbm_hash("ScoreObComponent"));

	++m_CurrentLevel;
	m_CurrentLevel %= 3;

	auto curScene = SceneManager::GetInstance().GetCurrentScene();
	curScene->m_ReadyForDelete = true;

	if (m_CurrentLevel == 0)
	{
		auto level = std::make_unique<dae::Level1>();
		m_pPlayer1->SetLocalPosition(level->m_Player1StartPos);
		SwitchScene(make_sdbm_hash("Level1"));
	}
	else if (m_CurrentLevel == 1)
	{
		auto level = std::make_unique<dae::Level2>();
		m_pPlayer1->SetLocalPosition(level->m_Player1StartPos);
		SwitchScene(make_sdbm_hash("Level2"));
	}
	else if (m_CurrentLevel == 2)
	{
		auto level = std::make_unique<dae::Level3>();
		m_pPlayer1->SetLocalPosition(level->m_Player1StartPos);
		SwitchScene(make_sdbm_hash("Level3"));
	}

	SceneManager::GetInstance().QueueRemoveScene(curScene);
}