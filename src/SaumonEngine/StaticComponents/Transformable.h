#pragma once
#include "../Utils.h"


struct Transformable{
	Vector2f m_position; //Position in pixels

	float m_rotation;  //rotation in degrees around z axis
	Vector2f m_rotationCenter; //Rotation center

	Vector2f m_scale;  //size factor

};

