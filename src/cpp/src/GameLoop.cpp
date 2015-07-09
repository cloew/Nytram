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

void GameLoop::run(GameLoop_Callback callback)
{
	gameWindow->open();

	long limit = (1 / clockSpeed) * 1000;
    long previous = milliseconds_now();
	
	while (!gameWindow->shouldClose())
    {
		long start = milliseconds_now();
        long deltaTime = start - previous;
        previous = start;

		callback();
		gameWindow->processEvents();

		long end = milliseconds_now();
        long dt = end - start;
		
        if (dt < limit)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(limit - dt));
        }
    }
	glfwTerminate();
}

void GameLoop::stop()
{
	gameWindow->quit();
}