#pragma once
#include "../Managers/AssetsManager.h"
#include "../Utils.h"

struct Sprite{
	sf::Texture* m_texture;
	Vector2f m_offset;
	sf::FloatRect m_srcRect;
	bool m_visible;

	Sprite(const char* path, bool visible, sf::FloatRect srcRect, Vector2f offset = { 0, 0 }) : m_texture(AssetsManager::Get()->Load(path)), m_offset(offset), m_srcRect(srcRect), m_visible(visible) {};
};

