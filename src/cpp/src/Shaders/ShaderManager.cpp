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
	for (auto &pair : idToShader)
    {
		pair.second.compile();
    }

	for (auto &pair : idToShaderProgram)
    {
		vector<Shader*> shaders;
		vector<GLuint> shaderIds = idToProgramShaders[pair.first];
		for (auto &id : shaderIds)
		{
			shaders.push_back(getShader(id));
		}
		pair.second.initialize(shaders);
    }
}

ShaderProgram* ShaderManager::getProgram(GLuint id)
{
	return &idToShaderProgram[id];
}