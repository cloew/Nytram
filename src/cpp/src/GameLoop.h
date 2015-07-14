#pragma once

#include "FrameLimiter.h"
#include "GameWindow.h"
#include "InputHandler.h"

#include "GameObjects/Scene.h"

typedef void (*GameLoop_Callback)();

class GameLoop
{
public:
	GameLoop() {}
	GameLoop(GameWindow* window, InputHandler* inputHandler);

	void run(GameLoop_Callback callback, Scene& scene);
	void stop();

private:
	GameWindow* gameWindow;
	InputHandler* inputHandler;
	FrameLimiter frameLimiter;
};

