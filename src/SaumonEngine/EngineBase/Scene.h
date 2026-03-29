#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "IUpdateSystem.h"
#include "IRenderSystem.h"

class World;


class Scene {
protected:
	World* m_world = new World;


	std::vector<IUpdateSystem*> m_updateSystems;
	std::vector<IRenderSystem*> m_renderSystems;

	sf::Shader* m_globalShader = nullptr;
public:

	Scene();

	void Update(float dt);

	void Render(sf::RenderTexture* window, sf::RenderTexture* debugWindow);
	
	virtual void InitializeWorld() = 0;

	void Draw(sf::RenderTexture* sceneTexture, sf::RenderWindow* window);

};