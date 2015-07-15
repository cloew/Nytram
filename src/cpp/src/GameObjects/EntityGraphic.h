#pragma once

#include "Entity.h"

#include "Graphics/GLVertexArray.h"
#include "Shaders/ShaderProgram.h"

#include <functional>
#include <vector>

using namespace std;

class EntityGraphic
{
public:
	EntityGraphic() {}
	EntityGraphic(ShaderProgram* shaderProgram) {this->shaderProgram = shaderProgram;}

	void initialize();
	void addVertexBuffer(GLuint shaderAttribute, float vertices[], GLuint size);
	void draw();

	// Getters
	Draw_Callback getDrawCallback() {return std::bind(&EntityGraphic::draw, this);}

private:
	GLVertexArray vao;
	vector<GLBuffer> buffers;
	ShaderProgram* shaderProgram;

	map<GLuint, vector<GLfloat>> attributeToValues;
};