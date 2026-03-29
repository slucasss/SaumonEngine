#include "Scene.h"

#include "IRenderSystem.h"
#include "IUpdateSystem.h"


//Static systems
#include "../StaticSystems/MotionSystem.h"
#include "../StaticSystems/DrawRectangleSystem.h"
#include "../StaticSystems/SpriteRendererSystem.h"

//Dynamic systems
#include "../DynamicSystems/CustomUpdateSystem.h"


Scene::Scene(){

	//Update systems
	m_updateSystems.push_back(new CustomUpdateSystem);

	m_updateSystems.push_back(new MotionSystem);

	//Render systems
	m_renderSystems.push_back(new RectangleRendererSystem);

	m_renderSystems.push_back(new SpriteRendererSystem);	
}

void Scene::Update(float dt){
	for (auto& s : m_updateSystems) {
		s->Update(m_world, dt);
	}
}

void Scene::Render(sf::RenderTexture* window, sf::RenderTexture* debugWindow){
	for (auto& s : m_renderSystems) {
		s->Render(m_world, window, debugWindow);
	}
}

void Scene::Draw(sf::RenderTexture* sceneTexture, sf::RenderWindow* window){
sf::Sprite renderTexture(sceneTexture->getTexture());
	renderTexture.setPosition({0, 0});

	if (m_globalShader == nullptr) {
		window->draw(renderTexture);
		return;
	}
	window->draw(renderTexture, m_globalShader);
}