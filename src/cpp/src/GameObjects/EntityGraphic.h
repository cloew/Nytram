#pragma once

#include "Entity.h"

#include "Utils.h"
#include "Graphics/GLVertexArray.h"
#include "Shaders/ShaderProgram.h"

#include <functional>
#include <vector>

#include <glm/glm.hpp>

using namespace glm;
using namespace std;

class EntityGraphic
{
public:
	EntityGraphic() {}
	EntityGraphic(ShaderProgram* shaderProgram) {this->shaderProgram = shaderProgram;}

	void initialize();
	void addElementBuffer(GLuint elements[], GLuint size);
	void addVertexBuffer(GLuint shaderAttribute, float vertices[], GLuint size);
	void draw(const mat4& mvp);

	// Getters
	Draw_Callback getDrawCallback() {return std::bind(&EntityGraphic::draw, this, placeholders::_1);}

private:
	GLVertexArray vao;
	vector<GLBuffer> buffers;
	ShaderProgram* shaderProgram;

	vector<GLuint> elements;
	map<GLuint, vector<GLfloat>> attributeToValues;
};