#include <vector>

#include "GameObject.hpp"

std::vector<GameObject*> GameObject::objects{};

const void GameObject::save(GameObject* object) {
	objects.push_back(object);
}