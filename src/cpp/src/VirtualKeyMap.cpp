#include "VirtualKeyMap.h"

static struct {
    UINT virtualKey;
    int key;
} keyMapItems[] = {
    { 'A', Key_A },
    { 'B', Key_B },
    { 'C', Key_C },
    { 'D', Key_D },
    { 'E', Key_E },
    { 'F', Key_F },
    { 'G', Key_G },
    { 'H', Key_H },
    { 'I', Key_I },
    { 'J', Key_J },
    { 'K', Key_K },
    { 'L', Key_L },
    { 'M', Key_M },
    { 'N', Key_N },
    { 'O', Key_O },
    { 'P', Key_P },
    { 'Q', Key_Q },
    { 'R', Key_R },
    { 'S', Key_S },
    { 'T', Key_T },
    { 'U', Key_U },
    { 'V', Key_V },
    { 'W', Key_W },
    { 'X', Key_X },
    { 'Y', Key_Y },
    { 'Z', Key_Z },
    { VK_OEM_MINUS, Key_Minus },
    { VK_OEM_PLUS, Key_Plus },
    { VK_OEM_COMMA, Key_Comma },
    { VK_OEM_PERIOD, Key_Period },
    { VK_OEM_1, Key_Semicolon },
    { VK_OEM_2, Key_Slash },
    { VK_OEM_3, Key_Backtick },
    { VK_OEM_4, Key_LeftBracket },
    { VK_OEM_5, Key_Backslash },
    { VK_OEM_6, Key_RightBracket },
    { VK_OEM_7, Key_Quote },
    { '0', Key_Digit0 },
    { '1', Key_Digit1 },
    { '2', Key_Digit2 },
    { '3', Key_Digit3 },
    { '4', Key_Digit4 },
    { '5', Key_Digit5 },
    { '6', Key_Digit6 },
    { '7', Key_Digit7 },
    { '8', Key_Digit8 },
    { '9', Key_Digit9 },
    { VK_ESCAPE, Key_Escape },
    { VK_SPACE, Key_Space },
    { VK_LEFT, Key_Left },
    { VK_RIGHT, Key_Right },
    { VK_UP, Key_Up },
    { VK_DOWN, Key_Down },
    { VK_RETURN, Key_Enter },
    { VK_CONTROL, Key_Ctrl },
    { VK_LCONTROL, Key_Ctrl },
    { VK_RCONTROL, Key_Ctrl },
    { VK_SHIFT, Key_Shift },
    { VK_LSHIFT, Key_Shift },
    { VK_RSHIFT, Key_Shift },
    { VK_LMENU, Key_Alt },
    { VK_RMENU, Key_Alt },
    { VK_TAB, Key_Tab },
    { VK_INSERT, Key_Insert },
    { VK_DELETE, Key_Delete },
    { '\b', Key_Backspace },
    { VK_HOME, Key_Home },
    { VK_END, Key_End },
    { VK_PRIOR, Key_PageUp },
    { VK_NEXT, Key_PageDown },
    { VK_F1, Key_F1 },
    { VK_F2, Key_F2 },
    { VK_F3, Key_F3 },
    { VK_F4, Key_F4 },
    { VK_F5, Key_F5 },
    { VK_F6, Key_F6 },
    { VK_F7, Key_F7 },
    { VK_F8, Key_F8 },
    { VK_F9, Key_F9 },
    { VK_F10, Key_F10 },
    { VK_F11, Key_F11 },
    { VK_F12, Key_F12 },
    { VK_NUMPAD0, Key_NumPad0 },
    { VK_NUMPAD1, Key_NumPad1 },
    { VK_NUMPAD2, Key_NumPad2 },
    { VK_NUMPAD3, Key_NumPad3 },
    { VK_NUMPAD4, Key_NumPad4 },
    { VK_NUMPAD5, Key_NumPad5 },
    { VK_NUMPAD6, Key_NumPad6 },
    { VK_NUMPAD7, Key_NumPad7 },
    { VK_NUMPAD8, Key_NumPad8 },
    { VK_NUMPAD9, Key_NumPad9 },
    { VK_DIVIDE, Key_NumPadDiv },
    { VK_MULTIPLY, Key_NumPadMul },
    { VK_SUBTRACT, Key_NumPadSub },
    { VK_ADD, Key_NumPadAdd },
    { VK_DECIMAL, Key_NumPadPeriod }
};

VirtualKeyMap::VirtualKeyMap()
{
	keyMap.reserve(ARRAY_COUNT(keyMapItems));
    for (size_t i = 0; i < ARRAY_COUNT(keyMapItems); ++i)
        keyMap[keyMapItems[i].virtualKey] = keyMapItems[i].key;
}

unordered_map<UINT, int>::const_iterator VirtualKeyMap::find(UINT virtualKey)
{
	return keyMap.find(virtualKey);
}

unordered_map<UINT, int>::const_iterator VirtualKeyMap::end()
{
	return keyMap.end();
}