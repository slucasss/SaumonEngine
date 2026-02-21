#include "EventManager.h"
#include "InputManager.h"

#include "SFML/Window.hpp"
#include "SFML/System.hpp"



EventManager* EventManager::Get() {
	if (Instance == nullptr) {
		Instance = new EventManager;
	}
	return Instance;
}

void EventManager::EventUpdate(sf::RenderWindow* window){

	while(auto event = window->pollEvent()){
		//Window events
		if(event->is<sf::Event::Closed>()){
			window->close();
		}


		//Keyboard events
		if (auto key = event->getIf<sf::Event::KeyPressed>()) {
			InputManager::Get()->m_keyboardState[static_cast<size_t>(key->code)].isDown = true;
		}
		if (auto key = event->getIf<sf::Event::KeyReleased>()) {
			InputManager::Get()->m_keyboardState[static_cast<size_t>(key->code)].isUp = true;
		}


		//Mouse events
		if (auto key = event->getIf<sf::Event::MouseButtonPressed>()) {
			InputManager::Get()->m_mouseState[static_cast<size_t>(key->button)].isMouseDown = true;
		}
		if (auto key = event->getIf<sf::Event::MouseButtonReleased>()) {
			InputManager::Get()->m_mouseState[static_cast<size_t>(key->button)].isMouseDown = true;
		}


		//Resize event
		if (auto resize = event->getIf<sf::Event::Resized>()) {
			sf::View view = window->getView();
			view.setSize({ resize->size.x,resize->size.y });
			view.setCenter({ resize->size.x / 2,resize->size.y / 2 });
			window->setView(view);
		}


		//Focus events
		if (event->is<sf::Event::FocusLost>()) {
			
		}
		if (event->is<sf::Event::FocusGained>()) {

		}

	}
}

