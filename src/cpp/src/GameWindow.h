#pragma once

#include <string>
#include <iostream>

#include "IncludeGL.h"

using namespace std;

class GameWindow
{
public:
	GameWindow();

	int open();
	void clear();
	void swapBuffers();
	int shouldClose();
	void quit();

	// Getters
	GLFWwindow* getGLFWWindow() {return window;}

	// Setters
	void setTitle(const char* title);
	void setSize(int newWidth, int newHeight);

private:
	GLFWwindow* window;
	int width;
	int height;
	string title;
};