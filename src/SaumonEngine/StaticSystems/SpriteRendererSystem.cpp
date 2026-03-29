#include "SpriteRendererSystem.h"
#include "../StaticComponents/Transformable.h"
#include "../StaticComponents/Sprite.h"



void SpriteRendererSystem::Render(World* world, sf::RenderTexture* window, sf::RenderTexture* debugWindow){
	std::vector<Entity*> entities = world->GetEntitiesWith<Transformable, Sprite>();
	for (Entity* e : entities) {
		Sprite* spriteComponent = world->GetComponent<Sprite>(e);
		if (spriteComponent->m_visible == false) {
			return;
		}
		Transformable* transformComponent = world->GetComponent<Transformable>(e);

		Vector2f position = transformComponent->m_position;
		Vector2f rescale = transformComponent->m_scale;

		sf::Sprite sprite(*spriteComponent->m_texture);

		

		sprite.setPosition(sf::Vector2f{ position.x, position.y });
		sprite.setScale(sf::Vector2f{ rescale.x, rescale.y });

		//Set src rect

	}

}
