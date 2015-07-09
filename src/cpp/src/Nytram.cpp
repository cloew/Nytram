#include "Nytram.h"

//Keyboard keyboard;
//Mouse mouse;
GameWindow gameWindow;
InputHandler inputHandler(&gameWindow);
GameLoop loop(&gameWindow, &inputHandler);

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
//void Mouse_SetButtonCallback(MouseButton_Callback callback)
//{
	//mouse.setButtonCallback(callback);
//}

// Window
void Window_SetTitle(const char* title)
{
	gameWindow.setTitle(title);
}

void Window_SetSize(int width, int height)
{
	gameWindow.setSize(width, height);
}