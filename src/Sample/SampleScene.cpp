#include "EngineBase/Scene.h"
#include <memory>
#include <iostream>

#include "SampleScene.h"
#include "CustomFunctions.h"



void SampleScene::InitializeWorld(){
	CreatePlayer(m_world);
}


