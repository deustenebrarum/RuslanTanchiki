#ifndef BULLET_H
#define BULLET_H

#include "CollisionObject.hpp"
#include "Entity.hpp"

using namespace std;

class Bullet : public Entity {
public:
	Bullet(Point position, Direction direction);
	
	void update() override;

	char view() override {
		return char(250);
	}

	void move(Direction direction) override;
private:
	Direction direction_;
	CollisionObject collision_;
};

#endif
