#pragma once

#include "GameLoop.h"
#include "GameWindow.h"
#include "Mouse.h"

#define NYTRAM_API __declspec(dllexport)

#if __cplusplus
extern "C" {
#endif

	NYTRAM_API int Nytram_Run(GameLoop_Callback callback);
	NYTRAM_API void Nytram_Stop();

	// Mouse
	NYTRAM_API void Mouse_SetButtonCallback(MouseButton_Callback callback);

	// Window
	NYTRAM_API void Window_SetTitle(const char* title);
	NYTRAM_API void Window_SetSize(int width, int height);
	
#if __cplusplus
}
#endif