#pragma once

#include <chrono>
#include <thread>

#include "GameWindow.h"

class GameLoop
{
public:
	GameLoop(GameWindow window);
	~GameLoop();

	void run();

private:
	GameWindow gameWindow;
	float clockSpeed;
};

