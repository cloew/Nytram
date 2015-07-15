#include "Graphics.h"

void Graphics::initialize()
{
	glewExperimental = GL_TRUE; // Needed for core profile
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		cerr << "Failed to initialize GLEW: " << glewGetErrorString(error) << endl;
		return;
	}

	shaderManager.compileShaders();

	for (auto &renderer : entityGraphics)
	{
		renderer.initialize();
	}
}

GLuint Graphics::addRendererToEntity(Entity& entity, GLuint shaderProgramId)
{
	GLuint rendererIndex = addRenderer(shaderManager.getProgram(shaderProgramId));
	entity.setDrawCallback(entityGraphics[rendererIndex-1].getDrawCallback());
	return rendererIndex;
}

GLuint Graphics::addRenderer(ShaderProgram* shaderProgram)
{
	entityGraphics.push_back(EntityGraphic(shaderProgram));
	return entityGraphics.size();
}

void Graphics::addVertexBuffer(GLuint rendererId, GLuint shaderAttribute, float vertices[], GLuint size)
{
	entityGraphics[rendererId-1].addVertexBuffer(shaderAttribute, vertices, size);
}