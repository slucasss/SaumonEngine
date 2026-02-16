#include <SFML/Graphics.hpp>



class Scene;

class Engine {
private:
	
	float m_deltaTime;
	int m_FPS;

	bool m_running;

	Scene* m_currentScene;
	sf::RenderWindow m_window;

	sf::Vector2u m_windowSize;

public:

	Engine() :m_currentScene(nullptr), m_deltaTime(0), m_FPS(60), m_running(false), m_windowSize({ 0, 0 }) {};

	void Run(bool fullscreen, unsigned int width, unsigned int height);
	void Stop() { m_running = false; };

	void SetCurrentScene(Scene* scene) { m_currentScene = scene; };
	void SetFPSCap(int fps) { m_FPS = fps; };

};