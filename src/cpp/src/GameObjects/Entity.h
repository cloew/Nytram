#pragma once

#include "Graphics/GLVertexArray.h"
#include "Shaders/ShaderProgram.h"

#include <functional>

using namespace std;

typedef std::function<void()> Draw_Callback;

class Entity
{
public:
	void draw();
	
	// Setters
	void setDrawCallback(Draw_Callback drawCallback) {this->drawCallback = drawCallback;}

private:
	Draw_Callback drawCallback;
};

