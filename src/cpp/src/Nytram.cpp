#include "Nytram.h"

GameWindow gameWindow;
Graphics graphics;
InputHandler inputHandler(&gameWindow);
GameLoop loop(&gameWindow, &graphics, &inputHandler);

int Nytram_Run(GameLoop_Callback callback)
{
	loop.run(callback);
	return 0;
}

void Nytram_Stop()
{
	loop.stop();
}

// Keyboard
void Keyboard_SetCallback(Keyboard_Callback callback)
{
	inputHandler.setKeyboardCallback(callback);
}

// Mouse
void Mouse_SetButtonCallback(MouseButton_Callback callback)
{
	inputHandler.setMouseButtonCallback(callback);
}

// Window
void Window_SetTitle(const char* title)
{
	gameWindow.setTitle(title);
}

void Window_SetSize(int width, int height)
{
	gameWindow.setSize(width, height);
}