#include "Nytram.h"

GameEngine engine;

// Camera
void Camera_SetEye(GLfloat x, GLfloat y, GLfloat z)
{
	engine.setCameraEye(vec3(x, y, z));
}

void Camera_SetProjection(GLfloat width, GLfloat height, GLfloat nearClip, GLfloat farClip)
{
	engine.setCameraProjection(width, height, nearClip, farClip);
}

// Engine
void Nytram_Run()
{
	engine.run();
}

void Nytram_Stop()
{
	engine.stop();
}

// Entity
GLuint Entity_Add()
{
	return engine.addEntity();
}

void Entity_SetStartCallback(GLuint entityId, Start_Callback_fp startCallback)
{
	engine.setEntityStartCallback(entityId, startCallback);
}

void Entity_SetUpdateCallback(GLuint entityId, Update_Callback_fp updateCallback)
{
	engine.setEntityUpdateCallback(entityId, updateCallback);
}

void Entity_RotateInXY(GLuint entityId, GLfloat angleInDegrees)
{
	engine.rotateEntityInXY(entityId, angleInDegrees);
}

void Entity_RotateInYZ(GLuint entityId, GLfloat angleInDegrees)
{
	engine.rotateEntityInYZ(entityId, angleInDegrees);
}

void Entity_RotateInXZ(GLuint entityId, GLfloat angleInDegrees)
{
	engine.rotateEntityInXZ(entityId, angleInDegrees);
}

void Entity_Scale(GLuint entityId, GLfloat x, GLfloat y, GLfloat z)
{
	engine.scaleEntity(entityId, vec3(x, y, z));
}

void Entity_Translate(GLuint entityId, GLfloat x, GLfloat y, GLfloat z)
{
	engine.translateEntity(entityId, vec3(x, y, z));
}

void Entity_AddRenderer(GLuint entityId, GLuint rendererId)
{
	engine.addRendererToEntity(entityId, rendererId);
}

// Input
void Keyboard_SetCallback(Keyboard_Callback callback)
{
	engine.setKeyboardCallback(callback);
}

void Mouse_SetButtonCallback(MouseButton_Callback callback)
{
	engine.setMouseButtonCallback(callback);
}

// Loop
void Loop_AddCallback(Loop_Callback_fp callback)
{
	engine.addLoopCallback(callback);
}

// Renderers
GLuint Renderer_Add(GLuint shaderProgramId)
{
	return engine.addRenderer(shaderProgramId);
}

void Renderer_AddElementBuffer(GLuint rendererId, GLuint elements[], GLuint size)
{
	engine.addElementBuffer(rendererId, elements, size);
}

void Renderer_AddVertexBuffer(GLuint rendererId, GLuint shaderAttribute, float vertices[], GLuint size)
{
	engine.addVertexBuffer(rendererId, shaderAttribute, vertices, size);
}

// Scene
void Scene_SetStartCallback(Start_Callback_fp startCallback)
{
	engine.setSceneStartCallback(startCallback);
}

void Scene_SetUpdateCallback(Update_Callback_fp updateCallback)
{
	engine.setSceneUpdateCallback(updateCallback);
}

// Shaders
void Shader_AddShader(GLuint id, const char* filePath, GLenum shaderType)
{
	engine.addShader(id, filePath, shaderType);
}

void Shader_AddProgram(GLuint id, GLuint shaderIds[], GLuint size)
{
	vector<GLuint> vectorOfShaderIds;
	for (GLuint i = 0; i < size; i++)
	{
		vectorOfShaderIds.push_back(shaderIds[i]);
	}
	engine.addShaderProgram(id, vectorOfShaderIds);
}

// Time
long Time_SinceLastFrame()
{
	return engine.getTimeSinceLastFrame();
}

// Window
void Window_SetTitle(const char* title)
{
	engine.setWindowTitle(title);
}

void Window_SetSize(int width, int height)
{
	engine.setWindowSize(width, height);
}