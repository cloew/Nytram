#include "InputHandler.h"

Keyboard_Callback keyboardCallback = NULL;
MouseButton_Callback mouseButtonCallback = NULL;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action != GLFW_REPEAT)
	{
		keyboardCallback(key, (action == GLFW_PRESS));
	}
}

void mousebutton_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action != GLFW_REPEAT)
	{
		mouseButtonCallback(button, (action == GLFW_PRESS));
	}
}

InputHandler::InputHandler(GameWindow* window)
{
	gameWindow = window;
}

void InputHandler::bindCallbacks()
{
	glfwSetKeyCallback(gameWindow->getGLFWWindow(), key_callback);
	glfwSetMouseButtonCallback(gameWindow->getGLFWWindow(), mousebutton_callback);
}

void InputHandler::setKeyboardCallback(Keyboard_Callback newCallback)
{
	keyboardCallback = newCallback;
}

void InputHandler::setMouseButtonCallback(MouseButton_Callback newCallback)
{
	mouseButtonCallback = newCallback;
}