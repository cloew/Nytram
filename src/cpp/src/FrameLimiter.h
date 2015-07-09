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

private:
	float clockSpeed;
	long limit;
	long now, lastFrameStart, dt;
};

