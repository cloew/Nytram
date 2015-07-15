#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 inColor;
 
 out vec3 vertexColor;

void main()
{
	vertexColor = inColor;
    gl_Position = vec4(vertexPosition_modelspace, 1);
}