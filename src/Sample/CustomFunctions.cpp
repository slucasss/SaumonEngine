#include <iostream>
#include "CustomFunctions.h"



//Components
#include "StaticComponents/Transformable.h"
#include "StaticComponents/Movable.h"
#include "StaticComponents/Rectangle.h"
#include "StaticComponents/Sprite.h"
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
	Entity* player = world->CreateEntity();

	Transformable transformable;
	transformable.m_position = { 100, 100 };
	transformable.m_scale = Vector2f{ 0.2, 0.2 };
	world->AddComponent<Transformable>(player, &transformable);


	Sprite spriteComponent("../../../src/Assets/moi.jpg", true, sf::IntRect{{0, 0}, {400, 400}}, {0, 0});
	world->AddComponent<Sprite>(player, &spriteComponent);

	/*Rectangle rectangle(true, Vector2f{100, 100});
	world->AddComponent<Rectangle>(player, &rectangle);*/


	Movable movable;
	movable.m_direction = { 0, 0 };
	movable.m_speed = 200;
	world->AddComponent<Movable>(player, &movable);


	CustomUpdateComponent custom;
	custom.Update = [](Entity* entity, World* world, float dt) {
		MovePlayer(entity, world);
	};


	world->AddComponent<CustomUpdateComponent>(player, &custom);
}