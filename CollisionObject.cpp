#include "CollisionObject.hpp"

std::vector<CollisionObject*> CollisionObject::objects_{};

CollisionObject::CollisionObject(GameObject* parent)
	: parent_(parent)
{
	objects_.push_back(this);
}

bool CollisionObject::is_collided() {
	for (CollisionObject* object : objects_) {
		if ((parent() != object->parent()
			&& parent()->position() == object->parent()->position())
			|| parent()->position().x < 0
			|| parent()->position().x >= Pole::width
			|| parent()->position().y < 0
			|| parent()->position().y >= Pole::height) {
			return true;
		}
	}
	return false;
}

std::optional<GameObject*> CollisionObject::collided_with() {
	for (CollisionObject* object : objects_) {
		if ((parent() != object->parent()
			&& parent()->position() == object->parent()->position())
			|| parent()->position().x < 0
			|| parent()->position().x >= Pole::width
			|| parent()->position().y < 0
			|| parent()->position().y >= Pole::height) {
			return object->parent_;
		}
	}
	return std::nullopt;
}

CollisionObject::~CollisionObject() {
	objects_.erase(
		std::find(
			objects_.begin(),
			objects_.end(),
			this
		)
	);
}