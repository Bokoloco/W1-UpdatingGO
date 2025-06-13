#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::Update()
{
	//for(auto& scene : m_scenes)
	//{
	//	scene->Update();
	//}
	m_CurrentScene->Update();
}

void dae::SceneManager::LateUpdate()
{
	/*for (auto& scene : m_scenes)
	{
		scene->LateUpdate();
	}*/
	// Thanks to Viktor Vermeire for the logic of updating/switching scene
	m_CurrentScene->LateUpdate();
	if (m_NextScene != nullptr)
	{
		m_CurrentScene = m_NextScene;
		m_NextScene = nullptr;
	}
}

void dae::SceneManager::Render()
{
	m_CurrentScene->Render();
}

void dae::SceneManager::SwitchScene(unsigned int name)
{
	auto it = std::find_if(m_scenes.begin(), m_scenes.end(), [&](std::shared_ptr<Scene> scene) { return scene->GetName() == name; });
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

dae::Scene* dae::SceneManager::GetCurrentScene()
{
	return m_CurrentScene.get();
}

dae::Scene* dae::SceneManager::GetNextScene()
{
	return m_NextScene.get();
}

dae::Scene& dae::SceneManager::CreateScene(unsigned int name)
{
	const auto& scene = std::shared_ptr<Scene>(new Scene(name));
	m_scenes.push_back(scene);
	return *scene;
}
