#pragma once
class Entity{
	friend class World;

	int m_id;

	Entity(int id) : m_id(id) {};
};

