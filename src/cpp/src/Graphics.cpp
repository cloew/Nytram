#include "Graphics.h"

void Graphics::initialize()
{
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		cerr << "Failed to initialize GLEW." << endl;
		return;
	}
}