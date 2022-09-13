// Include GLUT, openGL, input.
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include <vector>
#include "Camera.h"
class Skybox
{
public:
	Skybox();
	~Skybox();

	void setSkybox();
	void setCube();
	void setPosition(Vector3 p);

	GLuint	skybox;
	Camera camera;
	Vector3 position;
};
