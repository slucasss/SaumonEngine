#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

InputManager::InputManager(){
	for (State& state : m_keyboardState) {
		state.isDown = false;
		state.isHeld = false;
		state.isUp = false;
	}

	for (MouseState& state : m_mouseState) {
		state.isMouseDown = false;
		state.isMouseHeld = false;
		state.isMouseUp = false;
	}
	m_mouseX = sf::Mouse::getPosition().x;
	m_mouseY = sf::Mouse::getPosition().y;

}

InputManager* InputManager::Get() {
	if (Instance == nullptr) {
		Instance = new InputManager;
	}
	return Instance;
}

void InputManager::Update(){
	
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	m_mouseX = static_cast<float>(mousePos.x);
	m_mouseY = static_cast<float>(mousePos.y);

	for (State& state : m_keyboardState)
	{
		if (state.isDown) {
			state.isHeld = true;
		}
		if (state.isUp) {
			state.isHeld = false;
		}
		state.isDown = false;
		state.isUp = false;
	}

	for (MouseState& state : m_mouseState)
	{
		if (state.isMouseDown)
		{
			state.isMouseHeld = true;
		}
		if (state.isMouseUp)
		{
			state.isMouseHeld = false;
		}
		state.isMouseDown = false;
		state.isMouseUp = false;
	}
}

bool InputManager::IsHeld(sf::Keyboard::Key key){
	return m_keyboardState[static_cast<int>(key)].isHeld;
}

bool InputManager::IsDown(sf::Keyboard::Key key){
	return m_keyboardState[static_cast<int>(key)].isDown;
}

bool InputManager::IsUp(sf::Keyboard::Key key){
	return m_keyboardState[static_cast<int>(key)].isUp;
}


