#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H

#include <vector>
#include <optional>

#include "GameObject.hpp"
#include "Pole.hpp"

class CollisionObject {
public:
	CollisionObject(GameObject* parent);

	bool is_collided();

	std::optional<GameObject*> collided_with();

	~CollisionObject();

	const GameObject* parent() const {
		return parent_;
	}
private:
	static std::vector<CollisionObject*> objects_;
	GameObject* parent_;
};

#endif
