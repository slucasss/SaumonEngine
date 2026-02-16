#pragma once
#include <SFML/Window.hpp>

class IRenderSystem{
public:
	virtual void Render(sf::Window* window) = 0;
};

