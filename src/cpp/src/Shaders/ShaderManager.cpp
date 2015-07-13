#include "ShaderManager.h"

void ShaderManager::addShader(GLuint id, const char* filePath, GLenum shaderType)
{
	idToShader[id] = Shader(filePath, shaderType);
}

void ShaderManager::addProgram(GLuint id, vector<GLuint> shaderIds)
{
	idToProgramShaders[id] = shaderIds;
}

void ShaderManager::compileShaders()
{
	map<GLuint, Shader>::iterator it;
	for (auto pair : idToShader)
    {
		pair.second.compile();
    }
}

ShaderProgram* ShaderManager::getProgram(GLuint id)
{
	if (idToShaderProgram.find(id) == idToShaderProgram.end())
	{
		vector<Shader*> shaders;
		vector<GLuint> shaderIds = idToProgramShaders[id];
		for (auto &id : shaderIds)
		{
			shaders.push_back(getShader(id));
		}
		idToShaderProgram[id] = ShaderProgram(shaders);
	}
	return &idToShaderProgram[id];
}