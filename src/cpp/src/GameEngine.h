#pragma once

#include "GameLoop.h"
#include "GameWindow.h"
#include "Graphics.h"
#include "InputHandler.h"

#include "GameObjects/Scene.h"

class GameEngine
{
public:
	GameEngine();

	// Engine
	void run(GameLoop_Callback callback);
	void stop();

	// Entities
	GLuint addEntity() {return scene.addEntity();}
	GLuint addRendererToEntity(GLuint entityId);
	
	// Graphics
	void addShader(GLuint id, const char* filePath, GLenum shaderType) {graphics.addShader(id, filePath, shaderType);}
	void addShaderProgram(GLuint id, vector<GLuint> shaderIds) {graphics.addShaderProgram(id, shaderIds);}

	// Input
	void setKeyboardCallback(Keyboard_Callback callback) {inputHandler.setKeyboardCallback(callback);}
	void setMouseButtonCallback(MouseButton_Callback callback) {inputHandler.setMouseButtonCallback(callback);}

	// Window
	void setWindowTitle(const char* title) {gameWindow.setTitle(title);}
	void setWindowSize(int width, int height) {gameWindow.setSize(width, height);}

private:
	GameWindow gameWindow;
	Graphics graphics;
	InputHandler inputHandler;
	GameLoop loop;

	Scene scene;
};