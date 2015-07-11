#pragma once

#include "Shader.h"

#include <map>

using namespace std;

class ShaderManager
{
public:
	void addShader(GLuint id, const char* filePath, GLenum shaderType);
	void compileShaders();
	
	// Getters
	Shader* getShader(GLuint id) {return &idToShader[id];}

private:
	map<GLuint, Shader> idToShader;
};

