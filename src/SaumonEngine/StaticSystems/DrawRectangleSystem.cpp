#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "DrawRectangleSystem.h"

#include "../StaticComponents/Rectangle.h"
#include "../StaticComponents/Transformable.h"


void RectangleRendererSystem::Render(World* world, sf::RenderTexture* window, sf::RenderTexture* debugWindow){
	std::vector<Entity*> entities;
	world->GetEntitiesWith<Rectangle, Transformable>(&entities);

	for (Entity* e : entities) {
		Rectangle* rectangleComponent = world->GetComponent<Rectangle>(e);
		if (rectangleComponent->m_draw == false) {
			continue;
		}
		Transformable* transformableComponent = world->GetComponent<Transformable>(e);

		Vector2f position = transformableComponent->m_position;
		Vector2f size = rectangleComponent->m_size;

		sf::RectangleShape rectangle;

		rectangle.setSize({ size.x, size.y });
		rectangle.setPosition({ position.x, position.y });

		rectangle.setFillColor(rectangleComponent->m_color);


		window->draw(rectangle);
	}
}
