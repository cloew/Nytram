#pragma once

#include <Windows.h>
#include <chrono>
#include <thread>

#include "GameWindow.h"

typedef void (*GameLoop_Callback)();

class GameLoop
{
public:
	GameLoop(GameWindow* window);
	~GameLoop();

	void run(GameLoop_Callback callback);
	void stop();

private:
	GameWindow* gameWindow;
	float clockSpeed;
};

