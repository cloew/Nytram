#include "EntityGraphic.h"

void EntityGraphic::initialize()
{
	vao.makeCurrent();

	GLuint elements[] =
	{
		0,1,2
	};

	buffers.reserve(attributeToValues.size()+1);
	GLBuffer elementBuffer(GL_ELEMENT_ARRAY_BUFFER);
	buffers.push_back(elementBuffer);
	buffers[0].setData(sizeof(elements), elements, GL_STATIC_DRAW);

	for (auto &pair : attributeToValues)
	{
		GLBuffer buffer(GL_ARRAY_BUFFER);
		buffers.push_back(buffer);
		size_t index = buffers.size()-1;
		buffers[index].setData(pair.second, GL_STATIC_DRAW);
		shaderProgram->getAttribute(pair.first)->bind(buffers[index], 3, GL_FLOAT, GL_FALSE, 0, 0);
	}
}

void EntityGraphic::addVertexBuffer(GLuint shaderAttribute, GLfloat vertices[], GLuint size)
{
	vector<GLfloat> floats;
	floats.reserve(size);
	for (GLuint i = 0; i < size; i++)
	{
		floats.push_back(vertices[i]);
	}

	attributeToValues[shaderAttribute] = floats;
}

void EntityGraphic::draw()
{
	vao.makeCurrent();
	shaderProgram->use();
	//shaderProgram->setUniformValue("triangleColor", 0, 1, 0);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}