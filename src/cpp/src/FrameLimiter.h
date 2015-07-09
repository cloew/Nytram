#pragma once

#include <Windows.h>
#include <chrono>
#include <thread>

class FrameLimiter
{
public:
	FrameLimiter();

	void start();
	void enforceFrameLimit();

	double getCurrentFps() {return currentFps;}

private:
	float targetFps;
	long targetFrameDuration;
	long now, lastFrameStart, dt;

    double currentFps;
	long reportInterval;
	long lastReportTime;
    int frameCount;

	inline void calculateCurrentFps(long now);
};

