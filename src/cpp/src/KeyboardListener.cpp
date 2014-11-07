#include "KeyboardListener.h"

KeyboardListener::KeyboardListener(Keyboard* keyboardHandler)
{
	keyboard = keyboardHandler;
}

void KeyboardListener::onKeyPressed(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Ignore key repeats
    if (uMsg == WM_KEYDOWN && (lParam & BIT(30)))
        return;

    bool pressed = uMsg == WM_KEYDOWN || uMsg == WM_SYSKEYDOWN;
    auto it = keyMap.find(wParam);
    if (it == keyMap.end())
    {
        UINT vkey = MapVirtualKey((lParam >> 16) & 0xff, MAPVK_VSC_TO_VK_EX);
        it = keyMap.find(vkey);
    }
    
	if (it != keyMap.end())
        keyboard->setKeyPressed(it->second, pressed);
}
