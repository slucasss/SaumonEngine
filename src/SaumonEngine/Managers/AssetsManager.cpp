#include "AssetsManager.h"


AssetsManager* AssetsManager::Get(){
	if (Instance == nullptr) {
		Instance = new AssetsManager;
	}
	return Instance;
}
