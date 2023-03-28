#include <chrono>

#include "GameObject.hpp"
#include "Tank.hpp"
#include "Bullet.hpp"
#include "Wall.hpp"
#include "Key.hpp"
#include "Pole.hpp"
#include "utility.hpp"

using namespace std;

void run() {
	using namespace std::chrono_literals;

	Player player(Point{ 1,7 }, 100);
	Enemy geind1(Point{ 20,1 }, 100);

	GameObject::save(&player);
	GameObject::save(&geind1);
	GameObject::save(new Wall({ 0,5 }, true));
	GameObject::save(new Wall({ 1,5 }, true));

	GameObject::save(new Wall({ 20, 5 }, true));
	GameObject::save(new Wall({ 19, 5 }, true));

	GameObject::save(new Wall({ 10,0 }, false));
	GameObject::save(new Wall({ 10,1 }, false));

	GameObject::save(new Wall({ 10,9 }, false));
	GameObject::save(new Wall({ 10,10 }, false));

	while (true) {
		Pole::print(GameObject::objects);

		for (GameObject* object_ptr : GameObject::objects) {
			object_ptr->update();
		}

		if (is_key_pressed(Key::Q))
			break;
		std::this_thread::sleep_for(200ms);
		system("cls");
	}
}

int main() {
	run();

	for (GameObject* object : GameObject::objects) {
		delete object;
	}
}


