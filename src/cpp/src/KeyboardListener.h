#pragma once

#include <windows.h>

#include "VirtualKeyMap.h"

#define BIT(x) (1 << x)

class KeyboardListener
{
public:
	KeyboardListener() {}

	void onKeyPressed(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	VirtualKeyMap keyMap;
};

