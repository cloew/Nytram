#pragma once

#include "Shader.h"
#include "ShaderProgram.h"

#include <map>

using namespace std;

class ShaderManager
{
public:
	void addShader(GLuint id, const char* filePath, GLenum shaderType);
	void addProgram(GLuint id, vector<GLuint> shaderIds);
	void compileShaders();
	
	// Getters
	Shader* getShader(GLuint id) {return &idToShader[id];}
	ShaderProgram* getProgram(GLuint id);

private:
	map<GLuint, Shader> idToShader;
	map<GLuint, vector<GLuint>> idToProgramShaders;
	map<GLuint, ShaderProgram> idToShaderProgram;
};

