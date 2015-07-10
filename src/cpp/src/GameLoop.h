#pragma once

#include "FrameLimiter.h"
#include "GameWindow.h"
#include "Graphics.h"
#include "InputHandler.h"

typedef void (*GameLoop_Callback)();

class GameLoop
{
public:
	GameLoop(GameWindow* window, Graphics* graphics, InputHandler* inputHandler);

	void run(GameLoop_Callback callback);
	void stop();

private:
	GameWindow* gameWindow;
	Graphics* graphics;
	InputHandler* inputHandler;
	FrameLimiter frameLimiter;
};

