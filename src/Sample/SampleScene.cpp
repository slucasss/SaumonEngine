#include <memory>
#include <iostream>

#include "SampleScene.h"

//Static systems
#include "StaticSystems/MotionSystem.h"
#include "StaticSystems/DrawRectangleSystem.h"

//Dynamic systems
#include "DynamicSystems/CustomUpdateSystem.h"

//Components
#include "StaticComponents/Transformable.h"
#include "StaticComponents/Movable.h"
#include "StaticComponents/Rectangle.h"
#include "DynamicComponents/CustomUpdateComponent.h"


void SampleScene::InitializeWorld(){
	//Update systems
	m_updateSystems.push_back(new MotionSystem);
	m_updateSystems.push_back(new CustomUpdateSystem);

	//Render systems
	m_renderSystems.push_back(new DrawRectangleSystem);

	//Basic Entities creation

		//Rectangle Creation
		{
			Entity* rectangle = m_world->CreateEntity();

			Transformable* transformable = new Transformable;
			transformable->m_position = { 300, 100 };
			m_world->AddComponent<Transformable>(rectangle, transformable);


			Rectangle* rectangleComponent = new Rectangle(true, Vector2f{ 200, 100 });
			m_world->AddComponent<Rectangle>(rectangle, rectangleComponent);

			CustomUpdateComponent* custom = new CustomUpdateComponent;
			custom->Update = [](Entity* entity, World* world, float dt){
				std::cout << "Abonnez vous" << std::endl;
			};


			m_world->AddComponent<CustomUpdateComponent>(rectangle, custom);
		}
}
