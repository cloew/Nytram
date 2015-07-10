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
	Shader(const char* filePath, GLenum shaderType);
	~Shader();

	GLuint getShaderId() {return shaderId;}

private:
	GLuint shaderId;
	
	void loadShaderCode(const char* filePath, string& shaderCode);
	void compile(char const* sourcePointer);
	void checkCompileErrors();
};
