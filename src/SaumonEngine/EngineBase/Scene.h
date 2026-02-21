#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>


class World;
class IUpdateSystem;
class IRenderSystem;


class Scene {
private:
	World* m_world;
	
	std::vector<std::unique_ptr<IUpdateSystem>> m_updateSystems;
	std::vector<std::unique_ptr<IRenderSystem>> m_renderSystems;

public:
	void Update(float dt);

	void Render(sf::RenderWindow* window);
};