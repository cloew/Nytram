#include "Nytram.h"

GameEngine engine;

void Nytram_Run(GameLoop_Callback callback)
{
	engine.run(callback);
}

void Nytram_Stop()
{
	engine.stop();
}

// Keyboard
void Keyboard_SetCallback(Keyboard_Callback callback)
{
	engine.setKeyboardCallback(callback);
}

// Mouse
void Mouse_SetButtonCallback(MouseButton_Callback callback)
{
	engine.setMouseButtonCallback(callback);
}

// Window
void Window_SetTitle(const char* title)
{
	engine.setWindowTitle(title);
}

void Window_SetSize(int width, int height)
{
	engine.setWindowSize(width, height);
}