#pragma once

#include "GameLoop.h"
#include "GameWindow.h"
#include "Graphics.h"
#include "InputHandler.h"

class GameEngine
{
public:
	GameEngine();

	// Engine
	void run(GameLoop_Callback callback);
	void stop();

	// Input
	void setKeyboardCallback(Keyboard_Callback callback) {inputHandler.setKeyboardCallback(callback);}
	void setMouseButtonCallback(MouseButton_Callback callback) {inputHandler.setMouseButtonCallback(callback);}

	// Window
	void setWindowTitle(const char* title) {gameWindow.setTitle(title);}
	void setWindowSize(int width, int height) {gameWindow.setSize(width, height);}

private:
	GameWindow gameWindow;
	Graphics graphics;
	InputHandler inputHandler;
	GameLoop loop;
};