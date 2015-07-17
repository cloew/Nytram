#pragma once

#include "GameLoop.h"
#include "GameWindow.h"
#include "Graphics.h"
#include "InputHandler.h"

#include "GameObjects/Scene.h"

#include <glm/glm.hpp>

using namespace glm;

class GameEngine
{
public:
	GameEngine();

	// Camera
	void setCameraEye(const vec3& eye) {scene.setEye(eye);}
	void setCameraProjection(GLfloat width, GLfloat height, GLfloat nearClip, GLfloat farClip) {scene.setProjection(width, height, nearClip, farClip);}

	// Engine
	void run();
	void stop();

	// Entities
	GLuint addEntity() {return scene.addEntity();}
	void setEntityUpdateCallback(GLuint entityId, Update_Callback updateCallback) {scene.getEntity(entityId).setUpdateCallback(updateCallback);}
	void rotateEntityInXY(GLuint entityId, GLfloat angleInDegrees) {scene.getEntity(entityId).rotateInXY(angleInDegrees);}
	void rotateEntityInYZ(GLuint entityId, GLfloat angleInDegrees) {scene.getEntity(entityId).rotateInYZ(angleInDegrees);}
	void rotateEntityInXZ(GLuint entityId, GLfloat angleInDegrees) {scene.getEntity(entityId).rotateInXZ(angleInDegrees);}
	void scaleEntity(GLuint entityId, const vec3& scaling) {scene.getEntity(entityId).scale(scaling);}
	void translateEntity(GLuint entityId, const vec3& translation);
	void addRendererToEntity(GLuint entityId, GLuint rendererId);
	
	// Graphics
	GLuint addRenderer(GLuint shaderProgramId) {return graphics.addRenderer(shaderProgramId);}
	void addElementBuffer(GLuint rendererId, GLuint elements[], GLuint size) {graphics.addElementBuffer(rendererId, elements, size);}
	void addVertexBuffer(GLuint rendererId, GLuint shaderAttribute, float vertices[], GLuint size) {graphics.addVertexBuffer(rendererId, shaderAttribute, vertices, size);}
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