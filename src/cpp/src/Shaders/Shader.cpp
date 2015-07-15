#include "Shader.h"

Shader::Shader(const char* filePath, GLenum shaderType)
{
	shaderId = NULL;
	this->filePath = filePath;
	this->shaderType = shaderType;
}

Shader::~Shader()
{
	if (shaderId != NULL)
	{
		glDeleteShader(shaderId);
	}
}

void Shader::compile()
{
	shaderId = glCreateShader(shaderType);

	string shaderCode;
	loadShaderCode(filePath, shaderCode);
	
	char const * sourcePointer = shaderCode.c_str();
	compile(sourcePointer);
	
	checkCompileErrors();
}

void Shader::loadShaderCode(const string& filePath, string& shaderCode)
{
	ifstream shaderStream(filePath, ios::in);
	if(shaderStream.is_open())
	{
		string line = "";
		while(getline(shaderStream, line))
			shaderCode += "\n" + line;
		shaderStream.close();
	}
	else
	{
		cout << "Unable to open shader: " << filePath << endl;
	}
}

void Shader::compile(char const* sourcePointer)
{
	glShaderSource(shaderId, 1, &sourcePointer , NULL);
	glCompileShader(shaderId);
}

void Shader::checkCompileErrors()
{
	GLint Result = GL_FALSE;
	int InfoLogLength;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		vector<char> shaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(shaderId, InfoLogLength, NULL, &shaderErrorMessage[0]);
		cout << &shaderErrorMessage[0] << endl;
	}
}