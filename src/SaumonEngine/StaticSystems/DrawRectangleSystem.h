#pragma once
#include "../EngineBase/IRenderSystem.h"

class DrawRectangleSystem: public IRenderSystem{
public:
	void Render(World* world, sf::RenderTexture* window, sf::RenderTexture* debugWindow) override;
};

