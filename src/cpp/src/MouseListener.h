#pragma once

#include <windows.h>
#include <iostream>

class MouseListener
{
public:
	MouseListener(void);
	~MouseListener(void);

	void onButtonPressed(UINT uMsg, WPARAM wParam);
	int getXButtonNumber(WPARAM wParam);
};

