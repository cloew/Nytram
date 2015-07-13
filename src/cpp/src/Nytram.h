#pragma once

#include "GameEngine.h"

#define NYTRAM_API __declspec(dllexport)

#if __cplusplus
extern "C" {
#endif

	NYTRAM_API void Nytram_Run(GameLoop_Callback callback);
	NYTRAM_API void Nytram_Stop();

	// Keyboard
	NYTRAM_API void Keyboard_SetCallback(Keyboard_Callback callback);

	// Mouse
	NYTRAM_API void Mouse_SetButtonCallback(MouseButton_Callback callback);

	// Shaders
	NYTRAM_API void Shader_AddShader(GLuint id, const char* filePath, GLenum shaderType);
	NYTRAM_API void Shader_AddProgram(GLuint id, GLuint shaderIds[], GLuint size);

	// Window
	NYTRAM_API void Window_SetTitle(const char* title);
	NYTRAM_API void Window_SetSize(int width, int height);
	
#if __cplusplus
}
#endif