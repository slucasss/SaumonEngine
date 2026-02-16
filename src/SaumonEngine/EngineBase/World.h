#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>

class IComponentStorage {
};

template <typename T>
class ComponentStorage : public IComponentStorage{
public:
	std::vector<Entity>

	std::unordered_map<int, T> m_components;  //Id de l'entité, son composant associé
};



class Entity;

class World{
	std::unordered_map<std::type_index, std::unique_ptr<IComponentStorage>> m_componentsStorage;
	std::vector<Entity*> m_entities;
	int m_lastIndex = 0;

public:

	template <typename T>
	ComponentStorage<T>* AddOrGetComponentsStorage();

	template <typename T>
	void AddComponent(int entity, T component);

	template <typename T>
	T* GetComponent(int entity);

	Entity* CreateEntity();

};

