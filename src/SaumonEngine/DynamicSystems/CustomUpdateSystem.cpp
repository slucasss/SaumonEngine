#include "CustomUpdateSystem.h"
#include "../EngineBase/World.h"
#include "../DynamicComponents/CustomUpdateComponent.h"


//Do Update for all entities that have CustomUpdateComponent (with a Custom Update) 
void CustomUpdateSystem::Update(World* world, float dt) {

	ComponentStorage<CustomUpdateComponent>* storage = world->AddOrGetComponentsStorage<CustomUpdateComponent>();

	for (auto component : storage->m_components) {
		if (component.second->Update) {
			component.second->Update(component.first, world, dt);
		}
	}
}
