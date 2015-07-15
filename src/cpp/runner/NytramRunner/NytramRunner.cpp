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
	GLuint entity2Id = Entity_Add();
	GLuint renderer1Id = Renderer_Add(1);
	GLuint renderer2Id = Renderer_Add(1);

	Entity_AddRenderer(entity1Id, renderer1Id);
	Entity_AddRenderer(entity2Id, renderer2Id);
	
	float vertices1[] = 
	{
		-1, 1, 0,
		0, 0, 0,
		-1, -1, 0
	};
	float vertices2[] = 
	{
		1, 1, 0,
		1, -1, 0,
		0, 0, 0
	};
	float colors1[] = 
	{
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	};
	float colors2[] = 
	{
		1, 0, 0,
		0, 0, 1,
		0, 1, 0
	};
	Renderer_AddVertexBuffer(renderer1Id, 0, vertices1, 9);
	Renderer_AddVertexBuffer(renderer1Id, 1, colors1, 9);
	
	Renderer_AddVertexBuffer(renderer2Id, 0, vertices2, 9);
	Renderer_AddVertexBuffer(renderer2Id, 1, colors2, 9);

	Window_SetSize(480, 480);
	Window_SetTitle("My Blank Title");

	Keyboard_SetCallback((Keyboard_Callback) keyboardCallback);
	Mouse_SetButtonCallback((MouseButton_Callback) mouseCallback);
	
	Nytram_Run(myLoopCallback);
	
	system("PAUSE");
	return 0;
}
