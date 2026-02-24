#pragma once
#include "../Utils.h"

#include "SFML/Graphics.hpp"


struct Rectangle{
	bool m_draw;
	
	
	Vector2f m_size;
	Vector2f m_anchor;

	sf::Color m_color;

public:
	Rectangle(bool draw, Vector2f size, Vector2f anchor = { 0.f, 0.f }, sf::Color color = sf::Color::Magenta) :m_draw(draw), m_size(size), m_anchor(anchor), m_color(color) {};
};

