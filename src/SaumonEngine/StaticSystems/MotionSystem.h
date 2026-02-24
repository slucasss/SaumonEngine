#pragma once
#include "../EngineBase/IUpdateSystem.h"

class MotionSystem : public IUpdateSystem{
	void Update(World* world, float dt) override;
};

