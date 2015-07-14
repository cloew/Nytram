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
		renderer.initialize(shaderManager.getProgram(1));
	}
}

GLuint Graphics::addRendererToEntity(Entity& entity)
{
	GLuint rendererIndex = addRenderer();
	entity.setDrawCallback(entityGraphics[rendererIndex-1].getDrawCallback());
	return rendererIndex;
}

GLuint Graphics::addRenderer()
{
	entityGraphics.push_back(EntityGraphic());
	return entityGraphics.size();
}