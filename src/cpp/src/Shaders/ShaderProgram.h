#pragma once

#include "IncludeGL.h"
#include "Shader.h"

#include <vector>

using namespace std;

class ShaderProgram
{
public:
	ShaderProgram(vector<Shader*> shaders);
	~ShaderProgram();

private:
	GLuint programId;
};