#pragma once

#include "FrameLimiter.h"
#include "GameWindow.h"

typedef void (*GameLoop_Callback)();

class GameLoop
{
public:
	GameLoop(GameWindow* window);

	void run(GameLoop_Callback callback);
	void stop();

private:
	GameWindow* gameWindow;
	FrameLimiter frameLimiter;
};

