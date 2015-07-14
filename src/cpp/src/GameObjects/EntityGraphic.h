#pragma once

#include "Entity.h"

#include "Graphics/GLVertexArray.h"
#include "Shaders/ShaderProgram.h"

#include <functional>

class EntityGraphic
{
public:
	EntityGraphic() {}
	EntityGraphic(ShaderProgram* shaderProgram) {this->shaderProgram = shaderProgram;}

	void initialize();
	void draw();
	Draw_Callback getDrawCallback() {return std::bind(&EntityGraphic::draw, this);}

private:
	GLVertexArray vao;
	vector<GLBuffer> buffers;
	ShaderProgram* shaderProgram;
};