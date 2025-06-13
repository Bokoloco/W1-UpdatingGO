#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::Update()
{
	//for(auto& scene : m_scenes)
	//{
	//	scene->Update();
	//}

	if (!m_Pause)	m_CurrentScene->Update();
}

void dae::SceneManager::LateUpdate()
{
	/*for (auto& scene : m_scenes)
	{
		scene->LateUpdate();
	}*/
	// Thanks to Viktor Vermeire for the logic of updating/switching scene
	if (!m_Pause) m_CurrentScene->LateUpdate();

	m_scenes.erase(std::remove_if(m_scenes.begin(), m_scenes.end(), [&](std::shared_ptr<dae::Scene> scene) { return scene->m_ReadyForDelete; }), m_scenes.end());
}

void dae::SceneManager::Render()
{
	m_CurrentScene->Render();
}

void dae::SceneManager::SwitchScene(unsigned int name)
{
	auto it = std::find_if(m_scenes.begin(), m_scenes.end(), [&](std::shared_ptr<Scene> scene) { return scene->GetName() == name && !scene->m_ReadyForDelete; });
	if (it != m_scenes.end())
	{
		m_CurrentScene = *it;
	}
}

void dae::SceneManager::SetStartScene(unsigned int name)
{
	auto it = std::find_if(m_scenes.begin(), m_scenes.end(), [&](std::shared_ptr<Scene> scene) { return scene->GetName() == name; });
	if (it != m_scenes.end())
	{
		m_CurrentScene = *it;
	}
}

void dae::SceneManager::QueueRemoveScene(Scene* scene)
{
	m_SceneToDelete = scene;
	/*m_scenes.erase(std::remove_if(m_scenes.begin(), m_scenes.end(), [&](std::shared_ptr<dae::Scene> scene) { return scene == scene; }), m_scenes.end());*/
}

dae::Scene* dae::SceneManager::GetCurrentScene()
{
	return m_CurrentScene.get();
}

dae::Scene* dae::SceneManager::GetNextScene()
{
	return m_SceneToDelete;
}

dae::Scene& dae::SceneManager::CreateScene(unsigned int name)
{
	const auto& scene = std::shared_ptr<Scene>(new Scene(name));
	m_scenes.push_back(scene);
	return *scene;
}
