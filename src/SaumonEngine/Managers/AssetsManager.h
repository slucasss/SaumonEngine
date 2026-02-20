#pragma once
#include <map>
#include <string>


class AssetsManager{
	static AssetsManager* Instance;

public:
	static AssetsManager* Get();

	std::map<std::string, int > m_textures;/*Texture SFML> */

	/*Texture sfml*/ Load(std::string path);
};

