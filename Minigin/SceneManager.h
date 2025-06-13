#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Singleton.h"

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(unsigned int name);

		void Update();
		void LateUpdate();
		void Render();

		void SwitchScene(unsigned int name);
		void SetStartScene(unsigned int name);

		void QueueRemoveScene(Scene* scene);

		//void SetCurrentScene()
		Scene* GetCurrentScene();
		Scene* GetNextScene();

		bool m_Pause{};

	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_scenes;

		std::shared_ptr<Scene> m_CurrentScene{};
		Scene* m_SceneToDelete{};
	};
}
