#pragma once

#include "FrameLimiter.h"
#include "GameWindow.h"
#include "InputHandler.h"

typedef void (*GameLoop_Callback)();

class GameLoop
{
public:
	GameLoop(GameWindow* window, InputHandler* inputHandler);

	void run(GameLoop_Callback callback);
	void stop();

private:
	GameWindow* gameWindow;
	InputHandler* inputHandler;
	FrameLimiter frameLimiter;
};

