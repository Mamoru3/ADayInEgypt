#include "Light.h"

Light::Light()
{


}

Light::~Light()
{
}

void Light::render(float lats, float longs)
{

	glPushMatrix();
	GLfloat Light_Ambient[] = { 0.5, 0.5f, 0.5f, 1.0f };
	GLfloat Light_Diffuse[] = { 1.0f,  1.0f,  1.0f, 1.0f };
	GLfloat Light_Position[] = { 0.0f, 100.0f, 500.0f, 1.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, Light_Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_Diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, Light_Position);
	glEnable(GL_LIGHT0);
	glPopMatrix();

	

}
