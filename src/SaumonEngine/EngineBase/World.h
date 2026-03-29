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
	std::vector<T> m_components;  //All the T type components 
	std::unordered_map<Entity*, size_t> m_entityToIndex;  //Entity ptr and the index of it component
	std::vector<Entity*> m_indexToEntity;  //Entity ptr
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

		if (storage->m_entityToIndex.find(entity) != storage->m_entityToIndex.end()) {
			return;
		}

		size_t index = storage->m_components.size();
		storage->m_components.push_back(*component);
		storage->m_entityToIndex[entity] = index;
		storage->m_indexToEntity.push_back(entity);	
	}

	//Get the T type component of the entity
	//Return nullptr if it doesn't exist
	template<typename T>
	inline T* GetComponent(Entity* entity) {
		ComponentStorage<T>* storage = AddOrGetComponentsStorage<T>();
		auto it = storage->m_entityToIndex.find(entity);
		if (it == storage->m_entityToIndex.end()) {
			return nullptr;
		}

		return &storage->m_components[it->second];
	}

	//Return true if the entity (gave in parameter) has the component gave in template parameter
	template<typename T>
	inline bool HasComponent(Entity* entity) {
		ComponentStorage<T>* storage = AddOrGetComponentsStorage<T>();
		if (storage->m_entityToIndex.find(entity) == storage->m_entityToIndex.end()) {
			return false;
		}
		return true;
	}

	//Create a new entity, then you can add Components for it
	Entity* CreateEntity();

	
	//Change the vector result (parameter) to contains all entities that have all components types specified in template parameter
	template <typename FirstComponent, typename... Components>
	inline void GetEntitiesWith(std::vector<Entity*>* result){

		result->clear();

		ComponentStorage<FirstComponent>* storage = AddOrGetComponentsStorage<FirstComponent>();

		for (Entity* e : storage->m_indexToEntity) {
			if ((HasComponent<Components>(e) && ...)) {
				result->push_back(e);
			}
		}
	}


	~World();

};


