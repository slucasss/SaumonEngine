#include "Engine.h"
#include "Scene.h"


void Engine::Run(bool fullscreen = true, unsigned int width = 0, unsigned int height = 0){
	if (m_currentScene == nullptr) { return; };

	//Initialize SFML window;
	if (fullscreen == true) {
		m_window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().size), "SaumonEngine", sf::Style::None, sf::State::Fullscreen);
		m_windowSize = m_window.getSize();
	}
	else {
		sf::Vector2u size{ width, height };
		m_window.create(sf::VideoMode(size), "SaumonEngine", sf::Style::Default, sf::State::Windowed);
		m_windowSize = size;
	}

	m_running = true;

	//Initialize clock to calculate delta Time
	sf::Time frameDuration = sf::milliseconds(1 / m_FPS);
	sf::Clock clock;
	while (m_running = true ) {
		clock.start();

		//Scene update
		m_currentScene->Update(m_deltaTime);

		//Scene render
		m_window.clear();
		m_currentScene->Render(&m_window);
		m_window.display();


		//FPS caping
		sf::Time deltaTime = clock.reset();
		if (deltaTime < frameDuration) {
			sf::sleep(frameDuration - deltaTime);
		}
		if (m_window.isOpen() == false) { Stop(); };
	}
}
