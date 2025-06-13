#pragma once
#include "Singleton.h"
#include <vector>
#include <memory>

namespace dae
{
	enum class GameMode
	{
		SinglePlayer,
		Coop,
		Versus
	};

	enum class Levels
	{
		Level1,
		Level2,
		Level3
	};

	class GameObject;
	class GameManager final : public Singleton<GameManager>
	{
	public:
		~GameManager() noexcept;

		void SetGameMode(GameMode mode);
		void SwitchScene(unsigned int sceneName);
		void ResetScene();

		void AddPlayer1(std::unique_ptr<GameObject> player1);
		void AddPlayer2(std::unique_ptr<GameObject> player2);

		GameObject* Player1() const;
		GameObject* ScoreObserverObject() const;

		void AddHealthObserver(std::unique_ptr<GameObject> healthObserverObject);
		void AddScoreObserver(std::unique_ptr<GameObject> scoreObserverObject);

		void NextLevel();

	private:
		friend class Singleton<GameManager>;
		GameManager() = default;

		bool m_GetObjectsOut{};
		bool m_ShouldRemoveLevel{};

		unsigned int m_CurrentLevel{};

		GameMode m_GameMode;

		std::unique_ptr<GameObject> m_pPlayer1{};
		std::unique_ptr<GameObject> m_pPlayer2{};

		std::unique_ptr<GameObject> m_ScoreObserverObject{};
		std::unique_ptr<GameObject> m_HealthObserverObject{};
	};
}