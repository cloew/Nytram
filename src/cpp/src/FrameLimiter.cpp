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
	clockSpeed = 60.0f;
	limit = (1 / clockSpeed) * 1000;
}

void FrameLimiter::start()
{
	lastFrameStart = milliseconds_now();
}

void FrameLimiter::enforceFrameLimit()
{
	now = milliseconds_now();
    dt = now - lastFrameStart;
		
    if (dt < limit)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(limit - dt));
    }
	lastFrameStart = milliseconds_now();
}
