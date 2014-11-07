#pragma once

#include <windows.h>
#include <unordered_map>

#include "Keys.h"

using namespace std;

#define ARRAY_COUNT(x) (sizeof(x) / sizeof(x[0]))

class VirtualKeyMap
{
public:
	VirtualKeyMap();

	unordered_map<UINT, int>::const_iterator find(UINT virtualKey);

private:
	unordered_map<UINT, int> keyMap;
};

