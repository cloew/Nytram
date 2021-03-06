#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 inColor;
uniform mat4 MVP;
 
 out vec3 vertexColor;

void main()
{
	vertexColor = inColor;
    gl_Position = MVP*vec4(vertexPosition_modelspace, 1);
}