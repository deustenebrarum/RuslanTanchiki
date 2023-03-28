#include "Tank.hpp"
#include "Bullet.hpp"
#include "Key.hpp"


Tank::Tank(Point position, int HP)
	: Entity(position), HP_(HP), collision_(this), look_direction_(Direction::UP) {}

void Tank::shoot() {
	GameObject::save(new Bullet(position(), look_direction_));
}

void Player::update() {
	if (is_key_pressed(Key::UP_ARROW)) {
		move(Direction::UP);
	}
	else if (is_key_pressed(Key::DOWN_ARROW)) {
		move(Direction::DOWN);
	}
	else if (is_key_pressed(Key::LEFT_ARROW)) {
		move(Direction::LEFT);
	}
	else if (is_key_pressed(Key::RIGHT_ARROW)) {
		move(Direction::RIGHT);
	}

	if (is_key_pressed(Key::SPACE)) {
		shoot();
	}
}

void Tank::move(Direction direction) {
	Point old_position = position();

	Entity::move(direction);

	look_direction_ = direction;

	if (collision_.is_collided())
		set_position(old_position);
}

void Enemy::update()  {
	random_device rand;
	uniform_int_distribution<size_t> distribution(0, 5);
	const size_t random_index = distribution(rand);
	const array<Direction, 6> possible_directions{ look_direction_, look_direction_, Direction::UP, Direction::LEFT, Direction::RIGHT, Direction::DOWN };
	move(possible_directions[random_index]);
}

void Tank::take_damage(int damage) {
	HP_ -= damage;
	if (HP_ <= 0)
		delete this;
}