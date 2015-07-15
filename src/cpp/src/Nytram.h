#pragma once

#include "GameEngine.h"

#define NYTRAM_API __declspec(dllexport)

#if __cplusplus
extern "C" {
#endif

	// Engine
	NYTRAM_API void Nytram_Run(GameLoop_Callback callback);
	NYTRAM_API void Nytram_Stop();

	// Entity
	NYTRAM_API GLuint Entity_Add();
	NYTRAM_API GLuint Entity_AddRenderer(GLuint entityId, GLuint shaderProgramId);

	// Keyboard
	NYTRAM_API void Keyboard_SetCallback(Keyboard_Callback callback);

	// Mouse
	NYTRAM_API void Mouse_SetButtonCallback(MouseButton_Callback callback);

	// Renderers
	NYTRAM_API void Renderer_AddVertexBuffer(GLuint rendererId, GLuint shaderAttribute, float vertices[], GLuint size);

	// Shaders
	NYTRAM_API void Shader_AddShader(GLuint id, const char* filePath, GLenum shaderType);
	NYTRAM_API void Shader_AddProgram(GLuint id, GLuint shaderIds[], GLuint size);

	// Window
	NYTRAM_API void Window_SetTitle(const char* title);
	NYTRAM_API void Window_SetSize(int width, int height);
	
#if __cplusplus
}
#endif