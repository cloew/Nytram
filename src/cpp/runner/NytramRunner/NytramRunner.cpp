// NytramRunner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Nytram.h"

using namespace std;

void sceneCallback()
{
	cout << "In Scene Callback" << endl;
}

void entityCallback()
{
	cout << "In Entity Callback" << endl;
}

void loopCallback(long msSinceLastFrame)
{
	cout << "In Loop Callback: " << msSinceLastFrame << endl;
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
	Shader_AddShader(1, "../../resources/basic.vert", GL_VERTEX_SHADER);
	Shader_AddShader(2, "../../resources/basic.frag", GL_FRAGMENT_SHADER);

	GLuint shaderIds[] = {1, 2};
	Shader_AddProgram(1, shaderIds, 2);
	
	// Entity
	GLuint entity1Id = Entity_Add();
	GLuint renderer1Id = Renderer_Add(1);
	Scene_SetStartCallback(sceneCallback);
	Entity_AddRenderer(entity1Id, renderer1Id);
	Entity_SetStartCallback(entity1Id, entityCallback);
	//Entity_SetUpdateCallback(entity1Id, entityCallback);
	//Loop_AddCallback(loopCallback);

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

	Camera_SetEye(0, 0, 10);
	Camera_SetProjection(2, 2, 1, 100);

	Window_SetSize(480, 480);
	Window_SetTitle("My Blank Title");

	Keyboard_SetCallback((Keyboard_Callback) keyboardCallback);
	Mouse_SetButtonCallback((MouseButton_Callback) mouseCallback);
	
	Nytram_Run();
	
	system("PAUSE");
	return 0;
}
