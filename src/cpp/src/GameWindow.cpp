#include "GameWindow.h"

DWORD GetWindowStyle()
{
    int style = WS_OVERLAPPEDWINDOW;
    if (!true)
        style &= ~(WS_THICKFRAME | WS_MAXIMIZEBOX);
    return style;
}

static void GetWindowFrameSizeForContentSize(int& width, int& height, int windowStyle)
{
    RECT windowRect;
    windowRect.left = 0;
    windowRect.top = 0;
    windowRect.right = width;
    windowRect.bottom = height;
    AdjustWindowRect(&windowRect, windowStyle, FALSE);
    width = windowRect.right - windowRect.left;
    height = windowRect.bottom - windowRect.top;
}

LRESULT WINAPI WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    switch (uMsg) 
    { 
    case WM_CREATE:
        break;

    case WM_DESTROY:
        PostQuitMessage(0);             
        break; 

    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
    case WM_KEYDOWN:
    case WM_KEYUP:
        return 0;

    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
        return 0;

    case WM_MOUSEMOVE:
        return 0;

    case WM_MOUSEWHEEL:
        return 0;

    case WM_INPUT_DEVICE_CHANGE:
        return 0;

    default: 
        return DefWindowProc (hWnd, uMsg, wParam, lParam); 
    } 

    return 1; 
}

GameWindow::GameWindow()
{
	width = 640;
	height = 480;
	windowClass = TEXT("NytramWnd");
	title = "Nytram Window";
	MSG othermsg = { 0 };
	msg = othermsg;
}

int GameWindow::open()
{
	WNDCLASS wndclass	   = { 0 }; 
    DWORD    windowStyle   = 0;
    HINSTANCE hInstance	   = GetModuleHandle(NULL);

    wndclass.style         = CS_OWNDC;
    wndclass.lpfnWndProc   = (WNDPROC)WndProc; 
    wndclass.hInstance     = hInstance; 
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); 
    wndclass.lpszClassName = windowClass;
    wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
    if (!RegisterClass (&wndclass) ) 
        return FALSE; 

    windowStyle = GetWindowStyle();

    // Adjust the window rectangle so that the client area has
    // the correct number of pixels
    int windowWidth = width;
    int windowHeight = height;
    GetWindowFrameSizeForContentSize(windowWidth, windowHeight, windowStyle);
    
    windowHandle = CreateWindow(
        windowClass,
        title.c_str(),
        windowStyle,
        0,
        0,
        windowWidth,
        windowHeight,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (!windowHandle)
        return -1;
	ShowWindow(windowHandle, TRUE);
	return 0;
}

bool GameWindow::update()
{
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
    {
        if (msg.message == WM_QUIT)
        {
            return true;
        }
        else
        {
            TranslateMessage(&msg); 
            DispatchMessage(&msg); 
        }
    }
    else
    {
        SendMessage(windowHandle, WM_PAINT, 0, 0 );
    }
	return false;
}

void GameWindow::quit()
{
    PostQuitMessage(0);
}

void GameWindow::setTitle(const char* newTitle)
{
	title = newTitle;
}

void GameWindow::setSize(int newWidth, int newHeight)
{
    width = newWidth;
	height = newHeight;
}