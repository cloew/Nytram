// NytramRunner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Nytram.h"

using namespace std;

void loopCallback()
{
	return;
}
void keyboardCallback(int key, bool pressed)
{
	cout << "Key: " << key << " was pressed: " << pressed << endl;
	return;
}
void mouseCallback(int button, bool pressed)
{
	cout << "Button: " << button << " was pressed: " << pressed << endl;
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	GameLoop_Callback myLoopCallback = loopCallback;
	Shader_AddShader(1, "../../resources/basic.vert", GL_VERTEX_SHADER);
	Shader_AddShader(2, "../../resources/basic.frag", GL_FRAGMENT_SHADER);

	GLuint shaderIds[] = {1, 2};
	Shader_AddProgram(1, shaderIds, 2);
	
	// Entity
	GLuint entity1Id = Entity_Add();
	GLuint renderer1Id = Renderer_Add(1);

	Entity_AddRenderer(entity1Id, renderer1Id);

	GLuint elements[] =
	{
		0,1,2,
		3,1,4
	};
	
	float vertices[] = 
	{
		-1, 1, 0,
		0, 0, 0,
		-1, -1, 0,
		1, 1, 0,
		1, -1, 0
	};
	float colors[] = 
	{
		1, 0, 0,
		0, 1, 0,
		0, 0, 1,
		1, 0, 0,
		0, 0, 1
	};

	Renderer_AddElementBuffer(renderer1Id, elements, 6);
	Renderer_AddVertexBuffer(renderer1Id, 0, vertices, 15);
	Renderer_AddVertexBuffer(renderer1Id, 1, colors, 15);

	// Transform
	Entity_Translate(entity1Id, 0, 0, 0);
	Entity_RotateInXY(entity1Id, 0);
	Entity_Scale(entity1Id, 1, 1, 1);

	Window_SetSize(480, 480);
	Window_SetTitle("My Blank Title");

	Keyboard_SetCallback((Keyboard_Callback) keyboardCallback);
	Mouse_SetButtonCallback((MouseButton_Callback) mouseCallback);
	
	Nytram_Run(myLoopCallback);
	
	system("PAUSE");
	return 0;
}
