#include "Nytram.h"

GameWindow gameWindow;
GameLoop loop(&gameWindow);

int Nytram_Run()
{
	loop.run();

	return 0;
}

void Nytram_Stop()
{
	loop.stop();
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