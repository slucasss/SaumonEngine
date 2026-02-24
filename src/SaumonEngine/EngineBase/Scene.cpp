#include "Scene.h"

#include "IRenderSystem.h"
#include "IUpdateSystem.h"

void Scene::Update(float dt){
	for (auto& s : m_updateSystems) {
		s->Update(m_world, dt);
	}
}

void Scene::Render(sf::RenderWindow* window){
	for (auto& s : m_renderSystems) {
		s->Render(m_world, window);
	}
}
