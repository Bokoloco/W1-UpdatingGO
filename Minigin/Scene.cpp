#include "Scene.h"
#include "GameObject.h"

#include <algorithm>
#include "Minigin.h"
#include "CollisionComponent.h"

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

	CheckCollision();
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

void dae::Scene::CheckCollision()
{
	for (GameObject* gameObj1 : m_objects)
	{
		if (!gameObj1->CanCollide()) continue;
		if (gameObj1->ContainsComponent<dae::CollisionComponent>())
		{
			for (GameObject* gameObj2 : m_objects)
			{
				if (gameObj1 == gameObj2 || !gameObj2->CanCollide()) continue;

				dae::CollisionComponent* collisionComponent1 = gameObj1->GetComponent<dae::CollisionComponent>();
				//dae::CollisionComponent* collisionComponent2 = gameObj2->GetComponent<dae::CollisionComponent>();
				if (SDL_HasIntersectionF(gameObj1->GetBoundingBox(), gameObj2->GetBoundingBox()))
				{
					if (m_CurrentCollisions.find(collisionComponent1) == m_CurrentCollisions.end() /*&& m_CurrentCollisions.find(collisionComponent1) == m_CurrentCollisions.end()*/)
					{
						collisionComponent1->OnEnter(*gameObj2);
						//collisionComponent2->OnEnter(*gameObj1);
						m_CurrentCollisions.emplace(collisionComponent1, gameObj2);
						//m_CurrentCollisions.emplace(collisionComponent2, gameObj1);
					}
					else
					{
						collisionComponent1->OnColliding(*gameObj2);
						//collisionComponent2->OnColliding(*gameObj1);
					}
				}

				if (!SDL_HasIntersectionF(gameObj1->GetBoundingBox(), gameObj2->GetBoundingBox()) && m_CurrentCollisions.find(collisionComponent1) != m_CurrentCollisions.end())
				{
					if (/*gameObj1 == m_CurrentCollisions.find(collisionComponent2)->second &&*/ gameObj2 == m_CurrentCollisions.find(collisionComponent1)->second)
					{
						collisionComponent1->OnExit(*gameObj2);
						//collisionComponent2->OnExit(*gameObj1);
						m_CurrentCollisions.erase(collisionComponent1);
						//m_CurrentCollisions.erase(collisionComponent2);
					}
				}
			}
		}
	}
}