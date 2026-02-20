#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>



class IComponentStorage {
};

class Entity;


template <typename T>
class ComponentStorage : public IComponentStorage{
public:
	std::unordered_map<Entity*, T> m_components;  //Entity's ptr, his component
};




class World{
	std::unordered_map<std::type_index, std::unique_ptr<IComponentStorage>> m_componentsStorage;

	std::vector<Entity*> m_entities;
	
	int m_lastIndex = 0;

public:

	template <typename T>
	ComponentStorage<T>* AddOrGetComponentsStorage();
	

	//Add a component in it storage
	template <typename T>
	void AddComponent(Entity* entity, T component);


	//Get the T type component of the entity
	//Return nullptr if it doesn't exist
	template <typename T>
	T* GetComponent(Entity* entity);

	//Return true if the entity (gave in parameter) has the component gave in template parameter
	template <typename T>
	bool HasComponent(Entity* entity);

	//Create a new entity, then you can add Components for it
	Entity* CreateEntity();

	
	//Return a std::vector<Entity*> containing all entities that have all components types specified in template parameter
	template <typename... Components>
	std::vector<Entity*> GetEntitiesWith();

};


