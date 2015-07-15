#pragma once

#include "IncludeGL.h"

#include "GameObjects/EntityGraphic.h"
#include "Shaders/ShaderManager.h"

#include <iostream>
using namespace std;

class Graphics
{
public:
	void initialize(); // Must be called AFTER the GameWindow has been opened

	// Renderers
	void addRendererToEntity(Entity& entity, GLuint shaderProgramId);
	GLuint addRenderer(GLuint shaderProgramId);
	void addVertexBuffer(GLuint rendererId, GLuint shaderAttribute, float vertices[], GLuint size);

	// Shaders
	void addShader(GLuint id, const char* filePath, GLenum shaderType) {shaderManager.addShader(id, filePath, shaderType);}
	void addShaderProgram(GLuint id, vector<GLuint> shaderIds) {shaderManager.addProgram(id, shaderIds);}

private:
	ShaderManager shaderManager;
	vector<EntityGraphic> entityGraphics;
};

