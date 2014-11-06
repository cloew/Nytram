#pragma once

#include <windows.h>

typedef void (*MouseButton_Callback)(int button, bool pressed);

class Mouse
{
public:
	Mouse();

	void setButtonPressed(int button, bool pressed);
	void setButtonCallback(MouseButton_Callback newCallback);

private:
	unsigned int buttons;
	MouseButton_Callback callback;
};

