#include "Scene.h"
#include "GameObject.h"

#include <algorithm>
#include "FPSComponent.h"
#include "TextComponent.h"
#include "Minigin.h"

using namespace dae;

unsigned int Scene::m_idCounter = 0;

Scene::Scene(const std::string& name) : m_name(name) {}

Scene::~Scene() = default;

void Scene::Add(std::shared_ptr<GameObject> object)
{
	m_objects.emplace_back(std::move(object));
}

void Scene::Remove(std::shared_ptr<GameObject> object)
{
	m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
}

void Scene::RemoveAll()
{
	m_objects.clear();
}

void Scene::Update()
{
	for(auto& object : m_objects)
	{
		if (object->ContainsComponent<FPSComponent>())
		{
			object->Update();
			float currentFPS{ object->GetComponent<FPSComponent>()->GetFPS() };
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(1) << (currentFPS);
			object->GetComponent<TextComponent>()->SetText(oss.str() + " FPS");
		}
		else
		{
			object->Update();
		}
	}
}

void Scene::Render() const
{
	for (const auto& object : m_objects)
	{
		object->Render();
	}
}

