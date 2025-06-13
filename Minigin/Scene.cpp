#include "Scene.h"
#include "GameObject.h"

#include <algorithm>
#include "Minigin.h"
#include "CollisionComponent.h"

using namespace dae;

unsigned int Scene::m_idCounter = 0;

Scene::Scene(unsigned int name) : m_name(name) {}

Scene::~Scene()
{
	//for (auto& var : m_objects)
	//{
	//	delete var;
	//	var = nullptr;
	//}

	RemoveAll();
}

void Scene::Add(std::unique_ptr<GameObject> object)
{
	m_objects.emplace_back(std::move(object));
}

//void Scene::Remove(GameObject* object)
//{
//	m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
//}

void Scene::RemoveAll()
{
	m_objects.clear();
}

void Scene::Update()
{

	for(auto& object : m_objects)
	{
		if (!object) continue;
		object->Update();
	}

	CheckCollision();
}

void dae::Scene::LateUpdate()
{
	m_objects.erase(std::remove_if(m_objects.begin(), m_objects.end(), [](auto& go) { return go == nullptr; }), m_objects.end());
	m_objects.erase(std::remove_if(m_objects.begin(), m_objects.end(), [](auto& go) { return go->m_ReadyForDelete; }), m_objects.end());
}

void Scene::Render() const
{
	for (const auto& object : m_objects)
	{
		if (!object) continue;

		object->Render();
	}
}

void dae::Scene::CheckCollision()
{
	for (auto& gameObj1 : m_objects)
	{
		if (gameObj1 == nullptr) continue;
		if (!gameObj1->CanCollide()) continue;
		if (gameObj1->ContainsComponent<dae::CollisionComponent>())
		{
			for (auto& gameObj2 : m_objects)
			{
				if (gameObj2 == nullptr) continue;

				if (gameObj1 == gameObj2 || !gameObj2->CanCollide()) continue;
				if (gameObj1->IsChild(gameObj2.get()) || gameObj1->GetParent() == gameObj2.get()) continue;

				dae::CollisionComponent* collisionComponent1 = gameObj1->GetComponent<dae::CollisionComponent>();
				if (SDL_HasIntersectionF(gameObj1->GetBoundingBox(), gameObj2->GetBoundingBox()))
				{
					if (m_CurrentCollisions.find(collisionComponent1) == m_CurrentCollisions.end())
					{
						collisionComponent1->OnEnter(*gameObj2);
						m_CurrentCollisions.emplace(collisionComponent1, gameObj2.get());
					}
					else
					{
						bool alreadyColliding = false;
						auto range = m_CurrentCollisions.equal_range(collisionComponent1);
						for (auto it = range.first; it != range.second; ++it) {
							if (it->second == gameObj2.get()) {
								alreadyColliding = true;
								break;
							}
						}
						if (!alreadyColliding) {
							collisionComponent1->OnEnter(*gameObj2);
							m_CurrentCollisions.emplace(collisionComponent1, gameObj2.get());
						}

						collisionComponent1->OnColliding(*gameObj2);
					}
				}

				if (!SDL_HasIntersectionF(gameObj1->GetBoundingBox(), gameObj2->GetBoundingBox()) && m_CurrentCollisions.find(collisionComponent1) != m_CurrentCollisions.end())
				{
					auto range = m_CurrentCollisions.equal_range(collisionComponent1);
					for (auto it = range.first; it != range.second; ++it) 
					{
						if (it->second == gameObj2.get())
						{
							collisionComponent1->OnExit(*gameObj2);
							m_CurrentCollisions.erase(it);
							break;
						}
					}
				}
			}
		}
	}
}

unsigned int dae::Scene::GetName() const
{
	return m_name;
}

std::unique_ptr<GameObject> dae::Scene::GetObjectsWithTag(unsigned int tag)
{
	for (auto& object : m_objects)
	{
		if (object == nullptr) continue;
		if (object->ActorHasTag(tag))
			return std::move(object);
	}
	return nullptr;
}
