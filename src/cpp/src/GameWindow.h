#pragma once

#include <windows.h>
#include <string>

using namespace std;

class GameWindow
{
public:
	GameWindow();

	int open();

private:
	HWND windowHandle;
	int width;
	int height;
	LPCTSTR windowClass;
	string title;
};