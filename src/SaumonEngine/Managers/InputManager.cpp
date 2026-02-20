#include "InputManager.h"



InputManager* InputManager::Get() {
	if (Instance == nullptr) {
		Instance = new InputManager;
	}
	return Instance;
}
