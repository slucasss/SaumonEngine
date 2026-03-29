#pragma once
#include "../EngineBase/IRenderSystem.h"
#include "SFML/Graphics.hpp"


class SpriteRendererSystem: public IRenderSystem{
	void Render(World* world, sf::RenderTexture* window, sf::RenderTexture* debugWindow) override;

public:
	SpriteRendererSystem() = default;
};

