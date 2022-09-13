#pragma once

// Include GLUT, openGL, input.
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include <vector>
class Light
{


public:


	Light();
	~Light();

	void render(float lats, float longs);
	

protected:

	
};

