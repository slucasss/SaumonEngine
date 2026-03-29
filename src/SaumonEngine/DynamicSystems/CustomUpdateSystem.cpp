#include "CustomUpdateSystem.h"
#include "../EngineBase/World.h"
#include "../DynamicComponents/CustomUpdateComponent.h"


//Do Update for all entities that have CustomUpdateComponent (with a Custom Update) 
void CustomUpdateSystem::Update(World* world, float dt) {

	ComponentStorage<CustomUpdateComponent>* storage = world->AddOrGetComponentsStorage<CustomUpdateComponent>();

	for (size_t i = 0; i < storage->m_components.size(); i++) {
		CustomUpdateComponent* update = &storage->m_components[i];
		if (update->Update) {
			update->Update(storage->m_indexToEntity[i], world, dt);
		}
	}
}
