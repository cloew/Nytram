#include "InputHandler.h"

Keyboard_Callback keyboardCallback = NULL;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action != GLFW_REPEAT)
	{
		keyboardCallback(key, (action == GLFW_PRESS));
	}
}

InputHandler::InputHandler(GameWindow* window)
{
	gameWindow = window;
}

void InputHandler::bindCallbacks()
{
	glfwSetKeyCallback(gameWindow->getGLFWWindow(), key_callback);
}

void InputHandler::setKeyboardCallback(Keyboard_Callback newCallback)
{
	keyboardCallback = newCallback;
}