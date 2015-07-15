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
	GLuint entityId = Entity_Add();
	GLuint rendererId = Entity_AddRenderer(entityId, 1);

	
	float vertices[] = 
	{
		-.5, -.5, 0,
		0, .5, 0,
		.5, -.5, 0
	};
	float colors[] = 
	{
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	};
	Renderer_AddVertexBuffer(rendererId, 0, vertices, 9);
	Renderer_AddVertexBuffer(rendererId, 1, colors, 9);

	Window_SetSize(480, 480);
	Window_SetTitle("My Blank Title");

	Keyboard_SetCallback((Keyboard_Callback) keyboardCallback);
	Mouse_SetButtonCallback((MouseButton_Callback) mouseCallback);
	
	Nytram_Run(myLoopCallback);
	
	system("PAUSE");
	return 0;
}
