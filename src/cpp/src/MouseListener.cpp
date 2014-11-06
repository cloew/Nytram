#include "MouseListener.h"

MouseListener::MouseListener(Mouse* mouseHandler)
{
	mouse = mouseHandler;
}

void MouseListener::onButtonPressed(UINT uMsg, WPARAM wParam)
{
    int button = 0;
    bool pressed = false;
    switch (uMsg)
    {
    case WM_LBUTTONDOWN:
        button = 1; 
        pressed = true;
        break;
    case WM_MBUTTONDOWN:
        button = 3; 
        pressed = true;
        break;
    case WM_RBUTTONDOWN:
        button = 2; 
        pressed = true;
        break;
    case WM_XBUTTONDOWN:
		button = 3 + getXButtonNumber(wParam);
        pressed = true;
        break;
    case WM_LBUTTONUP:
        button = 1; 
        pressed = false;
        break;
    case WM_MBUTTONUP:
        button = 3; 
        pressed = false;
        break;
    case WM_RBUTTONUP:
        button = 2; 
        pressed = false;
        break;
    case WM_XBUTTONUP:
		button = 3 + getXButtonNumber(wParam);
        pressed = false;
        break;
    }

	mouse->setButtonPressed(button, pressed);
}

int MouseListener::getXButtonNumber(WPARAM wParam)
{
	int button = 1;
	if (HIWORD(wParam) & XBUTTON2)
		button = 2;
	return button;
}