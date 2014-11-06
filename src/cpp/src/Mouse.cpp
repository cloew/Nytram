#include "Mouse.h"

Mouse::Mouse()
{
	buttons = 0;
	callback = NULL;
}

void Mouse::setButtonPressed(int button, bool pressed)
{
	if (button >= 0 && button < 32)
	{
		unsigned int oldButtons = buttons;
		if (pressed)
			buttons |= (1 << button);
		else
			buttons &= ~(1 << button);

		if (buttons != oldButtons && callback)
			callback(button, pressed);
	}
}

void Mouse::setButtonCallback(MouseButton_Callback newCallback)
{
	callback = newCallback;
}