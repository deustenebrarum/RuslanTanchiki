#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include "utility.hpp"

using namespace std;

class GameObject {
public:
	virtual char view() = 0;
	virtual ~GameObject() {
		auto pos = std::find(
			objects.begin(),
			objects.end(),
			this
		);
		if (pos != objects.end())
			objects.erase(
				pos
			);
	}

	GameObject(Point position)
		: position_(position)
	{}

	static const void save(GameObject* object);

	const Point& position() const {
		return position_;
	}

	void set_position(Point new_position) {
		position_ = new_position;
	}

	virtual void update() = 0;
	virtual void init() {}
	virtual void destroy() {}
	static std::vector<GameObject*> objects;
protected:
	Point position_;
};


#endif