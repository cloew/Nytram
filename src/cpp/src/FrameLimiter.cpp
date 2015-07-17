#include "FrameLimiter.h"

long long milliseconds_now()
{
    static LARGE_INTEGER s_frequency;
    static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
    if (s_use_qpc) {
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (1000LL * now.QuadPart) / s_frequency.QuadPart;
    }
    else {
        return GetTickCount();
    }
}

FrameLimiter::FrameLimiter()
{
	targetFps = 60.0f;
	targetFrameDuration = (1 / targetFps) * 1000;

	currentFps = 0;
	frameCount = 0;
	lastFrameDuration = 0;
	reportInterval = 3000;
}

void FrameLimiter::start()
{
	lastFrameStart = milliseconds_now();
	lastReportTime = lastFrameStart;
}

void FrameLimiter::enforceFrameLimit()
{
	now = milliseconds_now();
    dt = now - lastFrameStart;

	if (true)
	{
		calculateCurrentFps(now);
	}
		
    if (dt < targetFrameDuration)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(targetFrameDuration - dt));
    }
	now = milliseconds_now();
	lastFrameDuration = now - lastFrameStart;
	lastFrameStart = now;
}

void FrameLimiter::calculateCurrentFps(long now)
{
	if ((now - lastReportTime) > reportInterval)
	{
		currentFps =  ((double)frameCount*1000) / (now - lastReportTime);
		frameCount = 1;
		lastReportTime = now;
	}
	else
	{
		++frameCount;
	}
}