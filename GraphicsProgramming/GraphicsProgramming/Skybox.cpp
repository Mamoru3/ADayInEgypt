
#include "Skybox.h"

Skybox::Skybox()
{

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	skybox = SOIL_load_OGL_texture
	(
		"gfx/skybox.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT 
	);
	
}
Skybox::~Skybox()
{

}
void Skybox::setSkybox()
{

}
void Skybox::setCube()
{

	glPushMatrix();
	glDisable(GL_DEPTH_TEST);

	glTranslatef(position.x, position.y, position.z);
	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glScalef(0.2, 0.2, 0.2);

	glBindTexture(GL_TEXTURE_2D, skybox);

	glBegin(GL_QUADS);
	//front face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.25f, 0.25f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.25f, 0.5f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.5f, 0.25f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	//right face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.5f, 0.25f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.75f, 0.5f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.75f, 0.25f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	//back face
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.75f, 0.25f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.75f, 0.5f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(1.0f, 0.5f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(1.0f, 0.25f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	//left face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.25f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.5f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.25f, 0.5f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.25f, 0.25f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	//top face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.25f, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.25f, 0.25f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.5f, 0.25f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	//bottom face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.25f, 0.5f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.25f, 0.75f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.5f, 0.75f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();
	glEnable(GL_DEPTH_TEST);
	glPopMatrix();
}

void Skybox::setPosition(Vector3 p)
{
	position = p;
}