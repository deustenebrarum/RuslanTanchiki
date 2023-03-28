#include <Windows.h>

#include "Key.hpp"

bool is_key_pressed(int code) {
	constexpr auto PRESSED_FLAG = 0x8000;
	const auto key_state = GetKeyState(code);
	if (key_state & PRESSED_FLAG)
		return true;
	return false;
}

bool is_key_pressed(Key key) {
	switch (key) {
	case Key::LEFT_ARROW:
		return is_key_pressed(VK_LEFT);
	case Key::UP_ARROW:
		return is_key_pressed(VK_UP);
	case Key::RIGHT_ARROW:
		return is_key_pressed(VK_RIGHT);
	case Key::DOWN_ARROW:
		return is_key_pressed(VK_DOWN);
	case Key::Q:
		return is_key_pressed(0x51);
	case Key::SPACE:
		return is_key_pressed(VK_SPACE);
	default:
		return false;
	}
}