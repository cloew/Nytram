#include "GameLoop.h"

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

GameLoop::GameLoop(GameWindow* window)
{
	gameWindow = window;
	clockSpeed = 60.0f;
}


GameLoop::~GameLoop()
{
}

void GameLoop::run()
{
	gameWindow->open();

	long limit = (1 / clockSpeed) * 1000;
    long previous = milliseconds_now();
	
	while (true)
    {
		long start = milliseconds_now();
        long deltaTime = start - previous;
        previous = start;

		if (gameWindow->update())
			break;

		long end = milliseconds_now();
        long dt = end - start;
		
        if (dt < limit)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(limit - dt));
        }
    }
}

void GameLoop::stop()
{
	gameWindow->quit();
}