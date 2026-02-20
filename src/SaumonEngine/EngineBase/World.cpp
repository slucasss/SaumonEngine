#include "World.h"
#include "Entity.h"


template<typename T>
inline ComponentStorage<T>* World::AddOrGetComponentsStorage(){
	std::type_index index = typeid(T);  //T objets' id
	auto& storage = m_componentsStorage[index];  //A pointer to the T components' storage

	if (storage == nullptr) { //If we don't find a storage for T objects, it create one
		storage = std::make_unique<ComponentStorage<T>>;
	}
	return m_componentsStorage[index].get(); //And then return it
}

template<typename T>
inline void World::AddComponent(Entity* entity, T component){
	ComponentStorage<T>* storage = AddOrGetComponentsStorage<T>();
	
	if (storage->m_components.find(entity) == storage->m_components.end()) {
		storage->m_components[entity] = component;
	}
}

template<typename T>
inline T* World::GetComponent(Entity* entity){
	ComponentStorage<T>* storage = AddOrGetComponentsStorage<T>();
	auto it = storage->m_components.find(entity);
	if (it == storage->m_components.end()) {
		return nullptr;
	}
	return &it->second;
}

template<typename T>
bool World::HasComponent(Entity* entity){
	ComponentStorage<T>* storage = AddOrGetComponentsStorage<T>();
	if (storage->m_components.find(entity) == storage->m_components.end()) {
		return false;
	}
	return true;
}

Entity* World::CreateEntity(){
	m_lastIndex++;
	Entity* entity = new Entity(m_lastIndex);
	m_entities.push_back(entity);
	return entity;
}

template <typename... Components>
inline std::vector<Entity*>World::GetEntitiesWith() {
	std::vector<Entity*> result;

	for (Entity* e : m_entities) {
		if ((HasComponent<Components>(e->m_id) && ...)) {
			result.push_back(e);
		}
	}
	return result;
}
