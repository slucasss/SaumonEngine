#include "Engine.h"
#include "Scene.h"
#include "../Managers/EventManager.h"
#include "../Managers/InputManager.h"


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


	m_renderTexture.resize(m_windowSize);
	m_debugTexture.resize(m_windowSize);
	
	m_renderTexture.clear(sf::Color::Transparent);
	m_debugTexture.clear(sf::Color::Transparent);


	m_running = true;

	//Initialize clock to calculate delta Time
	sf::Time frameDuration = sf::milliseconds(1 /m_FPS);
	sf::Clock clock;

	while (m_running == true) {
		clock.start();

		//Scene update
		m_currentScene->Update(m_deltaTime);

		//Scene render
		m_renderTexture.clear();
		m_currentScene->Render(&m_renderTexture, &m_debugTexture);
		m_renderTexture.display();


		m_window.clear();
		sf::Sprite renderTexture(m_renderTexture.getTexture());
		renderTexture.setPosition({ 0, 0 });

		m_window.draw(renderTexture);

		/*sf::Sprite debugTexture(m_debugTexture.getTexture());
		m_window.draw(debugTexture);*/

		m_window.display();




		//Event Update (for keys, window)
		EventManager::Get()->EventUpdate(&m_window);

		//Input Update
		InputManager::Get()->Update();

		//FPS caping
		sf::Time deltaTime = clock.reset();
		if (deltaTime < frameDuration) {
			sf::sleep(frameDuration - deltaTime);
		}

		//m_deltaTime = static_cast<float>(deltaTime);
		m_deltaTime = deltaTime.asSeconds();
		if (m_window.isOpen() == false) { Stop(); };
	}
}
