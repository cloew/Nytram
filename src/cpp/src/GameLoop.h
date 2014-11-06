#pragma once

#include <chrono>
#include <thread>

#include "GameWindow.h"

class GameLoop
{
public:
	GameLoop(GameWindow* window);
	~GameLoop();

	void run();
	void stop();

private:
	GameWindow* gameWindow;
	float clockSpeed;
};

