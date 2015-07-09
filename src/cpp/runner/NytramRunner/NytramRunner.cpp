// NytramRunner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Nytram.h"

using namespace std;

void loopCallback()
{
	return;
}
void mouseCallback(int button, int pressed)
{
	cout << "Button: " << button << " was pressed: " << pressed << endl;
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	GameLoop_Callback myLoopCallback = loopCallback;
	Window_SetTitle("My Blank Title");
	Mouse_SetButtonCallback((MouseButton_Callback) mouseCallback);
	Nytram_Run(myLoopCallback);
	system("PAUSE");
	return 0;
}
