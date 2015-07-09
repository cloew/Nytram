#pragma once

#include <string>
#include <iostream>

#include <glfw3.h>

using namespace std;

class GameWindow
{
public:
	GameWindow();

	int open();
	void processEvents();
	int shouldClose();
	void quit();

	// Setters
	void setTitle(const char* title);
	void setSize(int newWidth, int newHeight);

private:
	GLFWwindow* window;
	int width;
	int height;
	string title;
};