#include "EntityGraphic.h"

void EntityGraphic::initialize()
{
	vao.makeCurrent();

	GLuint elements[] =
	{
		0,1,2
	};
	/*{
		1,5,0,
		1,4,5,
		1,2,4,
		2,3,4
	};*/

	float vertices[] = 
	{
		-.5, -.5,
		0, .5,
		.5, -.5
	};
	/*{
		-.5, -1,
		.5, -1,
		1, 0,
		.5, 1,
		-.5, 1,
		-1, 0
	};*/
	float colors[] = 
	{
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	};
	GLBuffer elementBuffer(GL_ELEMENT_ARRAY_BUFFER);
	buffers.push_back(elementBuffer);

	GLBuffer vertexBuffer(GL_ARRAY_BUFFER);
	buffers.push_back(vertexBuffer);

	GLBuffer colorBuffer(GL_ARRAY_BUFFER);
	buffers.push_back(colorBuffer);

	buffers[0].setData(sizeof(elements), elements, GL_STATIC_DRAW);
	buffers[1].setData(sizeof(vertices), vertices, GL_STATIC_DRAW);
	buffers[2].setData(sizeof(colors), colors, GL_STATIC_DRAW);
	
	shaderProgram->getAttribute(0)->bind(buffers[1], 2, GL_FLOAT, GL_FALSE, 0, 0);
	shaderProgram->getAttribute(1)->bind(buffers[2], 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void EntityGraphic::draw()
{
	vao.makeCurrent();
	shaderProgram->use();
	//shaderProgram->setUniformValue("triangleColor", 0, 1, 0);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}