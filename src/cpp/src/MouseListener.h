#pragma once

#include <windows.h>

#include "Mouse.h"

class MouseListener
{
public:
	MouseListener() {}
	MouseListener(Mouse* mouseHandler);

	void onButtonPressed(UINT uMsg, WPARAM wParam);
	int getXButtonNumber(WPARAM wParam);

private:
	Mouse* mouse;
};

