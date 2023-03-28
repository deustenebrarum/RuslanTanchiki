#ifndef ENTITY_H
#define ENTITY_H

#include "utility.hpp"
#include "GameObject.hpp"

class Entity : public GameObject {
public:
	using GameObject::GameObject;

	virtual void move(Direction direction);
};

#endif
