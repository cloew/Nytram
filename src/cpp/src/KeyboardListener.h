#pragma once

#include <windows.h>

#include "Keyboard.h"
#include "VirtualKeyMap.h"

#define BIT(x) (1 << x)

class KeyboardListener
{
public:
	KeyboardListener() {}
	KeyboardListener(Keyboard* keyboardHandler);

	void onKeyPressed(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	Keyboard* keyboard;
	VirtualKeyMap keyMap;
};

