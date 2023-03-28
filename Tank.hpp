#ifndef TANK_H
#define TANK_H

#include <random>

#include "CollisionObject.hpp"
#include "utility.hpp"
#include "Entity.hpp"

using namespace std;

class Tank : public Entity {
public:
	Tank(Point position, int HP);

	const int HP() const { return HP_; }

	char view() override {
		switch (look_direction_) {
		case Direction::LEFT:
			return char(185);
		case Direction::RIGHT:
			return char(204);
		case Direction::DOWN:
			return char(203);
		case Direction::UP:
			return char(202);
		}

		return '\0';
	}

	void move(Direction direction)override;

	void shoot();

	void take_damage(int damage);
protected:
	int HP_;
	CollisionObject collision_;
	Direction look_direction_;
};

class Player : public Tank {
public:
	using Tank::Tank;
	void update() override;
};

class Enemy : public Tank {
public:
	using Tank::Tank;
	void update() override;
};

#endif