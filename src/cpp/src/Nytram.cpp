#include "Nytram.h"

GameEngine engine;

// Engine
void Nytram_Run(GameLoop_Callback callback)
{
	engine.run(callback);
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

GLuint Entity_AddRenderer(GLuint entityId, GLuint shaderProgramId)
{
	return engine.addRendererToEntity(entityId, shaderProgramId);
}

// Keyboard
void Keyboard_SetCallback(Keyboard_Callback callback)
{
	engine.setKeyboardCallback(callback);
}

// Mouse
void Mouse_SetButtonCallback(MouseButton_Callback callback)
{
	engine.setMouseButtonCallback(callback);
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

// Window
void Window_SetTitle(const char* title)
{
	engine.setWindowTitle(title);
}

void Window_SetSize(int width, int height)
{
	engine.setWindowSize(width, height);
}