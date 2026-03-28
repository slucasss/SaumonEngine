#include "EventManager.h"
#include "InputManager.h"

#include "SFML/Window.hpp"
#include "SFML/System.hpp"



EventManager* EventManager::Instance = nullptr;

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
			InputManager::Get()->m_keyboardState[static_cast<size_t>(key->code)].isUp = false;

		}
		
		if (auto key = event->getIf<sf::Event::KeyReleased>()) {
			InputManager::Get()->m_keyboardState[static_cast<size_t>(key->code)].isUp = true;
		}


		//Mouse events
		if (auto key = event->getIf<sf::Event::MouseButtonPressed>()) {
			InputManager::Get()->m_mouseState[static_cast<size_t>(key->button)].isMouseDown = true;
			InputManager::Get()->m_mouseState[static_cast<size_t>(key->button)].isMouseUp = false;

		}
		
		if (auto key = event->getIf<sf::Event::MouseButtonReleased>()) {
			InputManager::Get()->m_mouseState[static_cast<size_t>(key->button)].isMouseUp = true;
		}

		if (auto pos = event->getIf<sf::Event::MouseMoved>()) {
			InputManager::Get()->m_mouseX = pos->position.x;
			InputManager::Get()->m_mouseY = pos->position.y;
		}


		//Controller events
		if (auto button = event->getIf<sf::Event::JoystickButtonPressed>()) {
			InputManager::Get()->m_controllerState[static_cast<size_t>(button->button)].isButtonDown = true;
			InputManager::Get()->m_controllerState[static_cast<size_t>(button->button)].isButtonUp = false;
		}

		if (auto button = event->getIf<sf::Event::JoystickButtonReleased>()) {
			InputManager::Get()->m_controllerState[static_cast<size_t>(button->button)].isButtonUp = true;
		}

		if (auto joystick = event->getIf<sf::Event::JoystickMoved>()) {
			InputManager* input = InputManager::Get();

			if (joystick->axis == sf::Joystick::Axis::X) {
				input->m_leftJoystick.x = joystick->position;
			}
			if (joystick->axis == sf::Joystick::Axis::Y) {
				input->m_leftJoystick.y = joystick->position;
			}
			if (joystick->axis == sf::Joystick::Axis::Z) {
				input->m_rightJoystick.x = joystick->position;
			}
			if (joystick->axis == sf::Joystick::Axis::R) {
				input->m_rightJoystick.y = joystick->position;
			}
		}


		//Resize event
		if (auto resize = event->getIf<sf::Event::Resized>()) {
			sf::View view = window->getView();
			view.setSize({ static_cast<float>(resize->size.x),static_cast<float>(resize->size.y) });
			view.setCenter({ static_cast<float>(resize->size.x / 2),static_cast<float>(resize->size.y / 2) });
			window->setView(view);
		}


		//Focus events
		if (event->is<sf::Event::FocusLost>()) {
			
		}
		if (event->is<sf::Event::FocusGained>()) {

		}

	}
}

