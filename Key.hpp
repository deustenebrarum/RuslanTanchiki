#pragma once
#ifndef KEY_H
#define KEY_H

enum class Key {
	LEFT_ARROW,
	RIGHT_ARROW,
	DOWN_ARROW,
	UP_ARROW,
	Q,
	NOT_DEFINED,
	SPACE
};

bool is_key_pressed(int code);

bool is_key_pressed(Key key);

#endif
