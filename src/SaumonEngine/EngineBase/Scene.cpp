#include "Scene.h"

#include "IRenderSystem.h"
#include "IUpdateSystem.h"


//Static systems
#include "../StaticSystems/MotionSystem.h"
#include "../StaticSystems/DrawRectangleSystem.h"

//Dynamic systems
#include "../DynamicSystems/CustomUpdateSystem.h"


Scene::Scene(){

	//Update systems
	m_updateSystems.push_back(new CustomUpdateSystem);


	m_updateSystems.push_back(new MotionSystem);

	//Render systems
	m_renderSystems.push_back(new DrawRectangleSystem);
}

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
