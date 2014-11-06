#pragma once

#include <windows.h>
#include <string>

#include "Mouse.h"
#include "MouseListener.h"

using namespace std;

class GameWindow
{
public:
	GameWindow(Mouse* mouseHandler);

	int open();
	bool update();
	void quit();

	// Setters
	void setTitle(const char* title);
	void setSize(int newWidth, int newHeight);

private:
	HWND windowHandle;
	int width;
	int height;
	LPCTSTR windowClass;
	string title;
	MSG msg;

	// Event Listeners
	MouseListener mouseListener;
};