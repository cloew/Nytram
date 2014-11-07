#pragma once

#include <windows.h>

#include "Keys.h"

typedef void (*Keyboard_Callback)(int key, bool pressed);

class Keyboard
{
public:
	Keyboard();

	void setKeyPressed(int button, bool pressed);
	void setCallback(Keyboard_Callback newCallback);

private:
	bool keyStates[Key_MaxKey];
	Keyboard_Callback callback;
};

