#include <iostream>
#include "AssetsManager.h"


AssetsManager* AssetsManager::Get(){
	if (Instance == nullptr) {
		Instance = new AssetsManager;
	}
	return Instance;
}

sf::Texture* AssetsManager::Load(std::string path){
	sf::Texture texture;
	if (m_textures.find(path) == m_textures.end()) {
		if (!texture.loadFromFile(path)){
			std::cout << "Error in loading texture" << std::endl;
		}
		m_textures[path] = texture;
	}
	return &m_textures[path];
}
