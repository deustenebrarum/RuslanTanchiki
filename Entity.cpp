#include "Entity.hpp"

void Entity::move(Direction direction) {
	Point old_position = position();
	Point new_position = position();

	switch (direction) {
	case Direction::UP:
		new_position.y -= 1;
		break;
	case Direction::DOWN:
		new_position.y += 1;
		break;
	case Direction::LEFT:
		new_position.x -= 1;
		break;
	case Direction::RIGHT:
		new_position.x += 1;
		break;
	}


	set_position(new_position);
}