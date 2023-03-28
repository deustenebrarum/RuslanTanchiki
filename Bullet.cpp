#include "Bullet.hpp"
#include "Tank.hpp"
#include "utility.hpp"

Bullet::Bullet(Point position, Direction direction)
	: Entity(position), collision_(this), direction_(direction) {}

void Bullet::update() {
	move(direction_);
}

void Bullet::move(Direction direction) {

	Entity::move(direction);
	direction_ = direction;

	if (auto collided_object_optional = collision_.collided_with()) {
		delete this;
		GameObject* collided_object = collided_object_optional.value();
		if (instanceof<Tank>(collided_object))
			reinterpret_cast<Tank*>(collided_object)->take_damage(1);
	}
}