#include "EntityGraphic.h"

void EntityGraphic::initialize()
{
	vao.makeCurrent();
	buffers.reserve(attributeToValues.size()+1);

	GLBuffer elementBuffer(GL_ELEMENT_ARRAY_BUFFER);
	buffers.push_back(elementBuffer);
	buffers[0].setData(this->elements, GL_STATIC_DRAW);

	for (auto &pair : attributeToValues)
	{
		GLBuffer buffer(GL_ARRAY_BUFFER);
		buffers.push_back(buffer);
		size_t index = buffers.size()-1;
		buffers[index].setData(pair.second, GL_STATIC_DRAW);
		shaderProgram->getAttribute(pair.first)->bind(buffers[index], 3, GL_FLOAT, GL_FALSE, 0, 0);
	}
}

void EntityGraphic::addElementBuffer(GLuint elements[], GLuint size)
{
	this->elements = ArrayToVector<GLuint>(elements, size);
}

void EntityGraphic::addVertexBuffer(GLuint shaderAttribute, GLfloat vertices[], GLuint size)
{
	attributeToValues[shaderAttribute] = ArrayToVector<GLfloat>(vertices, size);
}

void EntityGraphic::draw(const mat4& mvp)
{
	vao.makeCurrent();
	shaderProgram->use();
	shaderProgram->setUniformValue("MVP", mvp);
	glDrawElements(GL_TRIANGLES, elements.size(), GL_UNSIGNED_INT, 0);
}