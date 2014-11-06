#pragma once

#include "GameLoop.h"
#include "GameWindow.h"

#define NYTRAM_API __declspec(dllexport)

#if __cplusplus
extern "C" {
#endif

	NYTRAM_API int Nytram_Run();
	
#if __cplusplus
}
#endif