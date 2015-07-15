#pragma once

#include "IncludeGL.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shader
{
public:
	Shader() {shaderId = NULL;}
	Shader(const char* filePath, GLenum shaderType);
	~Shader();

	void compile();

	// Getters
	GLuint getShaderId() {return shaderId;}

private:
	GLuint shaderId;
	string filePath;
	GLenum shaderType;
	
	void loadShaderCode(const string& filePath, string& shaderCode);
	void compile(char const* sourcePointer);
	void checkCompileErrors();
};
