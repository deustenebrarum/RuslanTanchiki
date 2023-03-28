#include "utility.hpp"
#include "GameObject.hpp"

class Entity : public GameObject {
public:
	using GameObject::GameObject;

	virtual void move(Direction direction);
};