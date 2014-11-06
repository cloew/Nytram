#include "Nytram.h"

NYTRAM_API int Nytram_Run()
{
	GameWindow gameWindow;
	GameLoop loop(gameWindow);

	loop.run();

	return 0;
}