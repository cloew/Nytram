#pragma once

#include "IncludeGL.h"

#include <vector>
using namespace std;

template <typename T>
vector<T> ArrayToVector(T elements[], GLuint size)
{
	vector<T> v;
	v.reserve(size);
	for (GLuint i = 0; i < size; i++)
	{
		v.push_back(elements[i]);
	}
	return v;
}