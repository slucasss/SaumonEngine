#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>


class AssetsManager{
	static AssetsManager* Instance;

public:
	static AssetsManager* Get();

	std::map<std::string, sf::Texture> m_textures;

	sf::Texture* Load(std::string path);
};

