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

void Graphics::addRendererToEntity(Entity& entity, GLuint rendererId)
{
	entity.setDrawCallback(entityGraphics[rendererId-1].getDrawCallback());
}

GLuint Graphics::addRenderer(GLuint shaderProgramId)
{
	entityGraphics.push_back(EntityGraphic(shaderManager.getProgram(shaderProgramId)));
	return entityGraphics.size();
}

void Graphics::addElementBuffer(GLuint rendererId, GLuint elements[], GLuint size)
{
	entityGraphics[rendererId-1].addElementBuffer(elements, size);
}

void Graphics::addVertexBuffer(GLuint rendererId, GLuint shaderAttribute, float vertices[], GLuint size)
{
	entityGraphics[rendererId-1].addVertexBuffer(shaderAttribute, vertices, size);
}