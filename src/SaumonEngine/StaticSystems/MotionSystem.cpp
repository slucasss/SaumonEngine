#include "MotionSystem.h"

#include "../EngineBase/World.h"
#include "../EngineBase/Entity.h"

#include "../StaticComponents/Movable.h"
#include "../StaticComponents/Transformable.h"




void MotionSystem::Update(World* world, float dt){
	std::vector<Entity*> entities;
	world->GetEntitiesWith<Movable, Transformable>(&entities);

	for (auto& e : entities) {

		Transformable* transformable = world->GetComponent<Transformable>(e);
		Movable* movable = world->GetComponent<Movable>(e);

		if (transformable == nullptr || movable == nullptr) {
			continue;
		}

		transformable->m_position = transformable->m_position + ((movable->m_direction.normalize() * movable->m_speed) * dt);
	}
}
