#pragma once

#include "GameLoop.h"
#include "GameWindow.h"

#define NYTRAM_API __declspec(dllexport)

#if __cplusplus
extern "C" {
#endif

	NYTRAM_API int Nytram_Run();
	NYTRAM_API void Nytram_Stop();

	// Window
	NYTRAM_API void Window_SetSize(int width, int height);
	
#if __cplusplus
}
#endif