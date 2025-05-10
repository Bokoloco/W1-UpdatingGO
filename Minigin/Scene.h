#pragma once
#include "SceneManager.h"
#include <set>
#include <map>

namespace dae
{
	class CollisionComponent;
	class GameObject;
	class Scene final
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(GameObject* object);
		void Remove(GameObject* object);
		void RemoveAll();

		void Update();
		void LateUpdate();
		void Render() const;

		void CheckCollision();

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);

		std::string m_name;
		std::vector <GameObject*> m_objects{};
		std::map<CollisionComponent*, GameObject*> m_CurrentCollisions{};

		static unsigned int m_idCounter; 
	};

}
