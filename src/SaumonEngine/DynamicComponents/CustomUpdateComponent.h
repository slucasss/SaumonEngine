#pragma once
#include <functional>

class Entity;
class World;

struct CustomUpdateComponent{
	std::function<void(Entity*, World*, float)> Update;
};

