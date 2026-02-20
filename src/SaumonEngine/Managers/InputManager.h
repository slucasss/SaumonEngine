#pragma once


class InputManager{

	static InputManager* Instance;


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

