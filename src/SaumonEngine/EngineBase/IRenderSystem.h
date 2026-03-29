#pragma once
#include <SFML/Graphics.hpp>
#include "../EngineBase/World.h"

class IRenderSystem{
public:
	virtual void Render(World* world, sf::RenderTexture* window, sf::RenderTexture* debugWindow) = 0;
};

