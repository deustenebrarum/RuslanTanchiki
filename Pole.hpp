#ifndef POLE_H
#define POLE_H

#include <vector>

#include "GameObject.hpp"

namespace Pole {
	constexpr char EMPTY_CELL = ' ';
	constexpr size_t height = 11;
	constexpr size_t width = 21;

	void print(std::vector<GameObject*> objects);
};

#endif
