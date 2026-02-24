#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>



class IComponentStorage {
public:
	virtual ~IComponentStorage() = default;
};

class Entity;


template <typename T>
class ComponentStorage : public IComponentStorage{
public:
	std::unordered_map<Entity*, T*> m_components;  //Entity's ptr, his component's ptr
};




class World{
	std::unordered_map<std::type_index, std::unique_ptr<IComponentStorage>> m_componentsStorage;

	std::vector<Entity*> m_entities;
	
	int m_lastIndex = 0;
	
public:

	template<typename T>
	inline ComponentStorage<T>* AddOrGetComponentsStorage() {
		std::type_index index = typeid(T);  //T objets' id
		auto& storage = m_componentsStorage[index];  //A pointer to the T components' storage

		if (storage == nullptr) { //If we don't find a storage for T objects, it create one
			storage = std::make_unique<ComponentStorage<T>>();
		}
		return static_cast<ComponentStorage<T>*>(m_componentsStorage[index].get()); //And then return it
	}
	

	//Add a component in it storage. Template parameter is the type of the added component
	template<typename T>
	inline void AddComponent(Entity* entity, T* component) {
		ComponentStorage<T>* storage = AddOrGetComponentsStorage<T>();

		if (storage->m_components.find(entity) == storage->m_components.end()) {
			storage->m_components[entity] = component;
		}
	}

	//Get the T type component of the entity
	//Return nullptr if it doesn't exist
	template<typename T>
	inline T* GetComponent(Entity* entity) {
		ComponentStorage<T>* storage = AddOrGetComponentsStorage<T>();
		auto it = storage->m_components.find(entity);
		if (it == storage->m_components.end()) {
			return nullptr;
		}
		return it->second;
	}

	//Return true if the entity (gave in parameter) has the component gave in template parameter
	template<typename T>
	inline bool HasComponent(Entity* entity) {
		ComponentStorage<T>* storage = AddOrGetComponentsStorage<T>();
		if (storage->m_components.find(entity) == storage->m_components.end()) {
			return false;
		}
		return true;
	}

	//Create a new entity, then you can add Components for it
	Entity* CreateEntity();

	
	//Return a std::vector<Entity*> containing all entities that have all components types specified in template parameter
	template <typename... Components>
	inline std::vector<Entity*>GetEntitiesWith() {
		std::vector<Entity*> result;

		for (Entity* e : m_entities) {
			if ((HasComponent<Components>(e) && ...)) {
				result.push_back(e);
			}
		}
		return result;
	}


	~World();

};


