#pragma once

#include <windows.h>
#include <string>

using namespace std;

class GameWindow
{
public:
	GameWindow();

	int open();
	bool update();
	void quit();

	// Setters
	void setWindowSize(int newWidth, int newHeight);

private:
	HWND windowHandle;
	int width;
	int height;
	LPCTSTR windowClass;
	string title;
	MSG msg;
};