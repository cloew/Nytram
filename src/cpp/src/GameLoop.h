#pragma once

#include "FrameLimiter.h"
#include "GameWindow.h"
#include "InputHandler.h"

#include "GameObjects/Scene.h"

#include <vector>
using namespace std;

typedef std::function<void(const long timeSinceLastFrame)> Loop_Callback;

class GameLoop
{
public:
	GameLoop() {}
	GameLoop(GameWindow* window, InputHandler* inputHandler);

	void run(Scene& scene);
	void stop();
	void addLoopCallback(Loop_Callback callback) {loopCallbacks.push_back(callback);}

	// Frame Limiter
	long getTimeSinceLastFrame() {return frameLimiter.getTimeSinceLastFrame();};

private:
	GameWindow* gameWindow;
	InputHandler* inputHandler;
	FrameLimiter frameLimiter;
	vector<Loop_Callback> loopCallbacks;

	void performExtraCallbacks();
};

