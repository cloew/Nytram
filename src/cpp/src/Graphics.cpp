#include "Graphics.h"

void Graphics::initialize()
{
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		cerr << "Failed to initialize GLEW." << endl;
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