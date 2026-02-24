#include "EngineBase/Engine.h"
#include "SampleScene.h"

int main() {
	Engine engine;

	SampleScene scene;


	engine.SetCurrentScene(&scene);

	scene.InitializeWorld();

	engine.Run(false, 1000, 500);
	
	return 0;
}