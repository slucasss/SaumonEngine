#include <vector>

#include "World.h"
#include "Entity.h"


Entity* World::CreateEntity(){
	m_lastIndex++;
	Entity* entity = new Entity(m_lastIndex);
	m_entities.push_back(entity);
	return entity;
}

World::~World() = default;