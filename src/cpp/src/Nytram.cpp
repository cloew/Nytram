#include "Nytram.h"

GameWindow gameWindow;
GameLoop loop(gameWindow);

int Nytram_Run()
{
	loop.run();

	return 0;
}

void Nytram_Stop()
{
	loop.stop();
}