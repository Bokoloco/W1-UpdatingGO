#include "Scene.h"
#include "GameObject.h"

#include <algorithm>
#include "FPSComponent.h"
#include "TextComponent.h"
#include "Minigin.h"

using namespace dae;

unsigned int Scene::m_idCounter = 0;

Scene::Scene(const std::string& name) : m_name(name) {}

Scene::~Scene()
{
	for (GameObject* var : m_objects)
	{
		delete var;
		var = nullptr;
	}

	RemoveAll();
}

void Scene::Add(GameObject* object)
{
	m_objects.emplace_back(std::move(object));
}

void Scene::Remove(GameObject* object)
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
		object->Update();
	}
}

void dae::Scene::LateUpdate()
{

}

void Scene::Render() const
{
	for (const auto& object : m_objects)
	{
		object->Render();
	}
}

