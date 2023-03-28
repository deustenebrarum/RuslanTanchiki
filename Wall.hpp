#ifndef WALL_H
#define WALL_H

#include "GameObject.hpp"
#include "CollisionObject.hpp"

class Wall : public GameObject {
public:
	Wall(Point position, bool is_horizontal)
		: GameObject(position), is_horizontal_(is_horizontal), collision_(this)
	{}

	void update() override {}

	char view() override {
		return is_horizontal_ ? char(196) : char(179);
	}
private:
	bool is_horizontal_;
	CollisionObject collision_;
};

#endif