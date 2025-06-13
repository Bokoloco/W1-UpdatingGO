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

	class GameObject;
	class GameManager final : public Singleton<GameManager>
	{
	public:
		~GameManager() noexcept;

		void SetGameMode(GameMode mode);
		void SwitchScene(unsigned int sceneName);

		void AddPlayer1(std::unique_ptr<GameObject> player1);
		void AddPlayer2(std::unique_ptr<GameObject> player2);

	private:
		friend class Singleton<GameManager>;
		GameManager() = default;

		GameMode m_GameMode;

		std::unique_ptr<GameObject> m_pPlayer1{};
		std::unique_ptr<GameObject> m_pPlayer2{};

		std::unique_ptr<GameObject> m_ScoreObserverObject{};
		std::unique_ptr<GameObject> m_HealthObserverObject{};
	};
}