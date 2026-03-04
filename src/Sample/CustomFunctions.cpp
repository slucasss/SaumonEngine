#include <iostream>

#include "CustomFunctions.h"

//Components
#include "StaticComponents/Transformable.h"
#include "StaticComponents/Movable.h"
#include "StaticComponents/Rectangle.h"
#include "DynamicComponents/CustomUpdateComponent.h"

#include "EngineBase/World.h"

#include "Managers/InputManager.h"


void MovePlayer(Entity* entity, World* world) {

	Movable* movable = world->GetComponent<Movable>(entity);

	if (movable == nullptr) {
		return;
	}

	movable->m_direction.x = 0;
	movable->m_direction.y = 0;

	{
		if (InputManager::Get()->IsHeld(sf::Keyboard::Key::Q)) {
			movable->m_direction.x = -1;
		}
		if (InputManager::Get()->IsHeld(sf::Keyboard::Key::D)) {
			movable->m_direction.x = 1;
		}
		if (InputManager::Get()->IsHeld(sf::Keyboard::Key::Z)) {
			movable->m_direction.y = -1;
		}
		if (InputManager::Get()->IsHeld(sf::Keyboard::Key::S)) {
			movable->m_direction.y = 1;
		}
		movable->m_direction = movable->m_direction.normalize();
	}
}


void CreatePlayer(World* world){
	Entity* rectangle = world->CreateEntity();

	Transformable* transformable = new Transformable;
	transformable->m_position = { 100, 100 };
	world->AddComponent<Transformable>(rectangle, transformable);


	Rectangle* rectangleComponent = new Rectangle(true, Vector2f{ 100, 100 });
	world->AddComponent<Rectangle>(rectangle, rectangleComponent);


	Movable* movable = new Movable;
	movable->m_direction = { 0, 0 };
	movable->m_speed = 200;
	world->AddComponent<Movable>(rectangle, movable);


	CustomUpdateComponent* custom = new CustomUpdateComponent;
	custom->Update = [](Entity* entity, World* world, float dt) {
		MovePlayer(entity, world);
	};


	world->AddComponent<CustomUpdateComponent>(rectangle, custom);
}