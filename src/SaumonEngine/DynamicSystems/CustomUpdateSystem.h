#pragma once
#include "../EngineBase/IUpdateSystem.h"
class CustomUpdateSystem: public IUpdateSystem{

	void Update(World* world, float dt) override;
};

