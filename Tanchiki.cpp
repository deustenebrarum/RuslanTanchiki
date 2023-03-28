#include <chrono>
#include <iostream>

#include "GameObject.hpp"
#include "Tank.hpp"
#include "Wall.hpp"
#include "Key.hpp"
#include "Pole.hpp"
#include "utility.hpp"

using namespace std;

void run() {
	using namespace std::chrono_literals;

	std::ios_base::sync_with_stdio(false);

	GameObject::save(new Player(Point{ 1,7 }, 1));
	GameObject::save(new Enemy(Point{ 20,1 }, 1));

	GameObject::save(new Wall({ 0,5 }, true));
	GameObject::save(new Wall({ 1,5 }, true));

	GameObject::save(new Wall({ 20, 5 }, true));
	GameObject::save(new Wall({ 19, 5 }, true));

	GameObject::save(new Wall({ 10,0 }, false));
	GameObject::save(new Wall({ 10,1 }, false));

	GameObject::save(new Wall({ 10,9 }, false));
	GameObject::save(new Wall({ 10,10 }, false));

	while (true) {
		auto view = Pole::get_view(GameObject::objects);
		system("cls");
		std::cout << view;

		for (GameObject* object_ptr : GameObject::objects) {
			object_ptr->update();
		}

		if (is_key_pressed(Key::Q))
			break;
		std::this_thread::sleep_for(200ms);
		
	}
}

int main() {
	run();

	for (GameObject* object : GameObject::objects) {
		delete object;
	}
}


