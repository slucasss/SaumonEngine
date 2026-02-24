#pragma once
#include <SFML/Window.hpp>
#include "../EngineBase/World.h"

class IRenderSystem{
public:
	virtual void Render(World* world, sf::RenderWindow* window) = 0;
};

