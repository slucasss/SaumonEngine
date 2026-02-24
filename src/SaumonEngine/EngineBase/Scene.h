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

public:
	void Update(float dt);

	void Render(sf::RenderWindow* window);
	
	virtual void InitializeWorld() = 0;
};