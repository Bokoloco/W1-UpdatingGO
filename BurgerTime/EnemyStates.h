#pragma once
#include <memory>

namespace dae
{
	class GameObject;
	class EnemyState
	{
	public:
		EnemyState(GameObject* owner, GameObject* player) : m_pOwner{ owner }, m_pPlayer{ player } {};
		virtual ~EnemyState() = default;

		virtual EnemyState* HandleInput() = 0;
		virtual void OnEnter() = 0;
		virtual void Update() = 0;

	protected:
		GameObject* GetOwner() const { return m_pOwner; };
		GameObject* GetPlayer() const { return m_pPlayer; };

	private:
		GameObject* m_pOwner;
		GameObject* m_pPlayer;
	};

	class MoveDownLadderComponent;
	class PlatformState;
	class LadderState final : public EnemyState
	{
	public:
		LadderState(GameObject* owner, GameObject* player);
		~LadderState() = default;

		EnemyState* HandleInput() override;
		void OnEnter() override;
		void Update() override;

	private:
		float m_YDirection{};
		float m_CoolDown{250.f};
		MoveDownLadderComponent* m_pMoveDownLadderComponent{};
	};

	class PlatformState final : public EnemyState
	{
	public:
		PlatformState(GameObject* owner, GameObject* player);
		~PlatformState() = default;

		EnemyState* HandleInput() override;
		void OnEnter() override;
		void Update() override;

	private:
		MoveDownLadderComponent* m_pMoveDownLadderComponent{};
	};
}