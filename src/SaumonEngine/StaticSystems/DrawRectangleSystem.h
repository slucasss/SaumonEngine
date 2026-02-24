#pragma once
#include "../EngineBase/IRenderSystem.h"

class DrawRectangleSystem: public IRenderSystem{
public:
	void Render(World* world, sf::RenderWindow* window) override;
};

