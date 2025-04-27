#pragma once
#include <SDL.h>
#include <wtypes.h>

namespace dae
{
	class GameObject;
	class Command
	{
	public:
		Command(GameObject& go) : m_pGameObject{ &go } {}

		virtual ~Command() = default;

		Command(const Command& other) = default;
		Command& operator=(const Command& other) = default;
		Command(Command&& other) = default;
		Command& operator=(Command&& other) = default;

		virtual void Execute() = 0;

	protected:
		GameObject* GetGameObject() { return m_pGameObject; }

	private:
		GameObject* m_pGameObject;

		bool m_UsesController{};
	};
}