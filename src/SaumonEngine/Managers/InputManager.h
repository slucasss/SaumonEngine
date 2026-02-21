#pragma once
#include <SFML/Window.hpp>


class InputManager{

	struct State {
		bool isDown;
		bool isHeld;
		bool isUp;
	};

	struct MouseState {
		bool isMouseDown;
		bool isMouseHeld;
		bool isMouseUp;
	};


	static InputManager* Instance;

	State m_keyboardState[sf::Keyboard::KeyCount];
	MouseState m_mouseState[sf::Mouse::ButtonCount];

	float m_mouseX = 0.f;
	float m_mouseY = 0.f;


	InputManager();

	friend class EventManager;

public:
	static InputManager* Get();


	//Update all the keys in the keys Table
	void Update();

	//Keyboard
	//bool IsHeld(identifiant de clé);
	//bool IsDown(identifiant de clé);
	//bool IsUp(identifiant de clé);


	//Mousse
	//bool IsHeld(identifiant de clé);
	//bool IsDown(identifiant de clé);
	//bool IsUp(identifiant de clé);
	


	//Controller
	//bool IsHeld(identifiant de clé);
	//bool IsDown(identifiant de clé);
	//bool IsUp(identifiant de clé);



};

