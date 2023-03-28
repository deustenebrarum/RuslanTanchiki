#include "Bullet.hpp"
#include "Tank.hpp"
#include "Wall.hpp"
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
		GameObject* collided_object = collided_object_optional.value();
		if (is_instance_of<Tank>(collided_object)) {
			reinterpret_cast<Tank*>(collided_object)->take_damage(1);
		}
		if (is_instance_of<Bullet>(collided_object))
		{
			auto another_bullet = reinterpret_cast<Bullet*>(collided_object);

			if (another_bullet->direction_ != direction_)
			{
				delete another_bullet;
			}
		}
		delete this;
	}
}