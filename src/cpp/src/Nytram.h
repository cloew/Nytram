#pragma once

#include "GameEngine.h"

#include <glm/glm.hpp>

using namespace glm;

#define NYTRAM_API __declspec(dllexport)

#if __cplusplus
extern "C" {
#endif
	
	typedef void (*Start_Callback_fp)();
	typedef void (*Update_Callback_fp)();
	typedef void (*Loop_Callback_fp)(long msSinceLastFrame);

	// Camera
	NYTRAM_API void Camera_SetEye(GLfloat x, GLfloat y, GLfloat z);
	NYTRAM_API void Camera_SetProjection(GLfloat width, GLfloat height, GLfloat nearClip, GLfloat farClip);

	// Engine
	NYTRAM_API void Nytram_Run();
	NYTRAM_API void Nytram_Stop();

	// Entity
	NYTRAM_API GLuint Entity_Add();
	NYTRAM_API void Entity_SetStartCallback(GLuint entityId, Start_Callback_fp startCallback);
	NYTRAM_API void Entity_SetUpdateCallback(GLuint entityId, Update_Callback_fp updateCallback);
	NYTRAM_API void Entity_RotateInXY(GLuint entityId, GLfloat angleInDegrees);
	NYTRAM_API void Entity_RotateInYZ(GLuint entityId, GLfloat angleInDegrees);
	NYTRAM_API void Entity_RotateInXZ(GLuint entityId, GLfloat angleInDegrees);
	NYTRAM_API void Entity_Scale(GLuint entityId, GLfloat x, GLfloat y, GLfloat z);
	NYTRAM_API void Entity_Translate(GLuint entityId, GLfloat x, GLfloat y, GLfloat z);
	NYTRAM_API void Entity_AddRenderer(GLuint entityId, GLuint rendererId);

	// Input
	NYTRAM_API void Keyboard_SetCallback(Keyboard_Callback callback);
	NYTRAM_API void Mouse_SetButtonCallback(MouseButton_Callback callback);

	// Loop
	NYTRAM_API void Loop_AddCallback(Loop_Callback_fp callback);

	// Renderers
	NYTRAM_API GLuint Renderer_Add(GLuint shaderProgramId);
	NYTRAM_API void Renderer_AddElementBuffer(GLuint rendererId, GLuint elements[], GLuint size);
	NYTRAM_API void Renderer_AddVertexBuffer(GLuint rendererId, GLuint shaderAttribute, float vertices[], GLuint size);

	// Scene
	NYTRAM_API void Scene_SetStartCallback(Start_Callback_fp startCallback);
	NYTRAM_API void Scene_SetUpdateCallback(Update_Callback_fp updateCallback);

	// Shaders
	NYTRAM_API void Shader_AddShader(GLuint id, const char* filePath, GLenum shaderType);
	NYTRAM_API void Shader_AddProgram(GLuint id, GLuint shaderIds[], GLuint size);

	// Time
	NYTRAM_API long Time_SinceLastFrame();

	// Window
	NYTRAM_API void Window_SetTitle(const char* title);
	NYTRAM_API void Window_SetSize(int width, int height);
	
#if __cplusplus
}
#endif