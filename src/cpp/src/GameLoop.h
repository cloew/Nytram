#pragma once

#include "FrameLimiter.h"
#include "GameWindow.h"
#include "InputHandler.h"

#include "GameObjects/Scene.h"

class GameLoop
{
public:
	GameLoop() {}
	GameLoop(GameWindow* window, InputHandler* inputHandler);

	void run(Scene& scene);
	void stop();

private:
	GameWindow* gameWindow;
	InputHandler* inputHandler;
	FrameLimiter frameLimiter;
};

