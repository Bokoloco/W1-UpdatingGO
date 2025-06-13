#pragma once
#include "SceneManager.h"
#include <set>
#include <map>
#include "GameObject.h"

namespace dae
{
	class CollisionComponent;
	//class GameObject;
	class Scene final
	{
		friend Scene& SceneManager::CreateScene(unsigned int name);
	public:
		void Add(std::unique_ptr<GameObject> object);
		//void Remove(GameObject* object);
		void RemoveAll();

		void Update();
		void LateUpdate();
		void Render() const;

		void CheckCollision();
		unsigned int GetName() const;

		std::unique_ptr<GameObject> GetObjectsWithTag(unsigned int tag);

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(unsigned int name);

		unsigned int m_name;
		std::vector <std::unique_ptr<GameObject>> m_objects{};
		std::multimap<CollisionComponent*, GameObject*> m_CurrentCollisions{};

		static unsigned int m_idCounter; 
	};

}
