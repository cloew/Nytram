#pragma once

#include "GameWindow.h"

typedef void (*Keyboard_Callback)(int key, bool pressed);
typedef void (*MouseButton_Callback)(int button, bool pressed);

class InputHandler
{
public:
	InputHandler(GameWindow* window);

	void bindCallbacks(); // Must be called after the window has opened and created the underlying GLFW Window context
	void processEvents();

	// Setters
	void setKeyboardCallback(Keyboard_Callback newCallback);
	void setMouseButtonCallback(MouseButton_Callback newCallback);

private:
	GameWindow* gameWindow;
};

