#pragma once
class World;


class IUpdateSystem{
public:
	virtual void Update(World* world, float dt) = 0;
};

