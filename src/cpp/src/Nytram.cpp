#include "Nytram.h"

Mouse mouse;
GameWindow gameWindow(&mouse);
GameLoop loop(&gameWindow);

int Nytram_Run(GameLoop_Callback callback)
{
	loop.run(callback);
	return 0;
}

void Nytram_Stop()
{
	loop.stop();
}

// Mouse
void Mouse_SetButtonCallback(MouseButton_Callback callback)
{
	mouse.setButtonCallback(callback);
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