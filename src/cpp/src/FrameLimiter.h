#pragma once

#include <Windows.h>
#include <chrono>
#include <thread>

#include <iostream>
using namespace std;

class FrameLimiter
{
public:
	FrameLimiter();

	void start();
	void enforceFrameLimit();

	// Getters
	double getCurrentFps() {return currentFps;}
	long getTimeSinceLastFrame() {return lastFrameDuration;}

private:
	float targetFps;
	long targetFrameDuration;
	long lastFrameDuration;
	long now, lastFrameStart, dt;

    double currentFps;
	long reportInterval;
	long lastReportTime;
    int frameCount;

	inline void calculateCurrentFps(long now);
};

