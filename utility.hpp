#ifndef UTILITY_H
#define UTILITY_H

#include <type_traits>

template<typename Base, typename T>
bool is_instance_of(const T) {
	return std::is_base_of_v<Base, T>;
}

struct Point
{
	int x, y;
	bool operator==(const Point& another) const {
		return (x == another.x && y == another.y);
	}
	bool operator!=(const Point& another) const {
		return !(*this == another);
	}
};

enum class Direction {
	LEFT,
	RIGHT,
	DOWN,
	UP
};

#endif
