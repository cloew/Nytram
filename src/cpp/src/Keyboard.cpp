#include "Keyboard.h"

Keyboard::Keyboard()
{
	callback = NULL;
	memset(keyStates, 0, sizeof(keyStates));
}

void Keyboard::setKeyPressed(int key, bool pressed)
{
	if (key >= 0 && key < Key_MaxKey)
	{
		if (keyStates[key] != pressed)
		{
			keyStates[key] = pressed;
			if (callback)
				callback(key, pressed);
		}
	}
}

void Keyboard::setCallback(Keyboard_Callback newCallback)
{
	callback = newCallback;
}