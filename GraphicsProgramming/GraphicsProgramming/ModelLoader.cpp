#include "ModelLoader.h"

ModelLoader::ModelLoader()
{
/*	floor = SOIL_load_OGL_texture
	(
		"gfx/sand3.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);*/



	sun = SOIL_load_OGL_texture
	(
		"gfx/SunText.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	sphinx.load("models/triSphinx.obj", "gfx/SphinxText.jpg");
	pyramid.load("models/pyramid1.obj", "gfx/crate.png");

			//------------------------first pyramid dimension
	pyrX = 10;
	pyrY = 10;
	pyrZ = 10;

	
}

ModelLoader::~ModelLoader()
{
}

void ModelLoader::modelRender(float lats,float longs)
{
	

	glPushMatrix();		//FLOOR IS RENDERED
	{
		floorRender();
	}
	glPopMatrix();


	glPushMatrix();		//3 PYRAMIDS 
	{
		int  pyrDistance = 0;				//VARIABLE FOR THE DISTANCE BETWEEN THE PYRAMIDS
		int distanceIncreaser = 250;	//DISTANCE INCREASER

		for (int i = 0; i < 3; i++)		//3 PYRAMID GENERATED
		{
			glTranslatef(pyrDistance, 0.0, 20.0f);		//PYRAMIDS ARE SLIGHTLY FARTHER THAN EACHOTHER IN THE Z AXIS
			glPushMatrix();
			{
				glTranslatef(-100, -2, 200.0f);
				
				glScalef(pyrX, pyrY, pyrZ);
				pyramid.render();
			}
			glPopMatrix();
			
			pyrDistance = distanceIncreaser;		//distance is increased
		}
	}
	glPopMatrix();

			//All models are rendered

	glPushMatrix();		
	{
		modelLoader();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(400.0f, 900.0f, 500.0f);
		glScalef(100.0f, 100.0f, 100.0f);
		sunRender(lats,longs);
	}
	glPopMatrix();
}

void ModelLoader::modelLoader()
{
	glPushMatrix();		//SPHINX IS RENDERED
	{
		glTranslatef(100, 0, -10);
		glRotatef(-90, 0, 1, 0);
		glScalef(0.5f, 0.5f, 0.5);
		sphinx.render();
	}
	glPopMatrix();



	
}



void ModelLoader::floorRender()
{

	increaserX = 0;
	increaserY = 0;
	

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	

	glTranslatef(-300, 0, 300);
	glRotatef(-90, 1, 0, 0);
	glScalef(400, 400, 1);

	glBindTexture(GL_TEXTURE_2D, floor);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 200; i++)
	{

		

		for (int j = 0; j < 200; j++)
		{
			glNormal3f(0.0, 0.0, 1.0);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(increaserX + (plane[0]), increaserY - plane[1], plane[2]);

			glNormal3f(0.0, 0.0, 1.0);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(increaserX + (plane[3]), increaserY - plane[4], plane[5]);

			glNormal3f(0.0, 0.0, 1.0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(increaserX + (plane[6]), increaserY - plane[7], plane[8]);

			glNormal3f(0.0, 0.0, 1.0);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(increaserX + (plane[9]), increaserY - plane[10], plane[11]);

			glNormal3f(0.0, 0.0, 1.0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(increaserX + (plane[12]), increaserY - plane[13], plane[14]);

			glNormal3f(0.0, 0.0, 1.0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(increaserX + (plane[15]), increaserY - plane[16], plane[17]);
			increaserY++;
		}
		
		increaserY = 0;
		increaserX++;
	}
	glEnd();
		
	
}

void ModelLoader::sunRender(float lats, float longs)
{

	float x2 = 0;	//VARIABLES FOR SPHERE
	float y2 = 0;
	float z2 = 0;
	float theta;
	float delta;
	float u = 1 / lats;
	float v = 1 / longs;

	theta = (2 * PI) / lats;
	delta = PI / longs;


	for (float lo = 0; lo < longs; lo++)
	{
		for (float la = 0; la < lats; la++)
		{
			x2 = cosf(theta * la) * sinf(delta * lo);
			y2 = cosf(delta * lo);
			z2 = sinf(theta * la) * sin(delta * lo);
			glBindTexture(GL_TEXTURE_2D, sun);
			glBegin(GL_QUADS);
			{
				//POINT 1
				glTexCoord2f(u * la, v * lo);	//FIRST POINT TEXT COORDS
				glNormal3f(x2, y2, z2);
				glVertex3f(x2, y2, z2);

				//POINT 2
				x2 = cosf(theta * (la + 1)) * sinf(delta * lo);
				y2 = cosf(delta * lo);
				z2 = sinf(theta * (la + 1)) * sinf(delta * lo);

				glTexCoord2f((u * la) + u, (v * lo));	//SECOND POINT TEXT COORDS
				glNormal3f(x2, y2, z2);
				glVertex3f(x2, y2, z2);

				//POINT 3
				x2 = cosf(theta * (la + 1)) * sinf(delta * (lo + 1));
				y2 = cosf(delta * (lo + 1));
				z2 = sinf(theta * (la + 1)) * sinf(delta * (lo + 1));

				glTexCoord2f((u * la) + u, (v * lo) + v);	//THIRD POINT TEXT COORDS
				glNormal3f(x2, y2, z2);
				glVertex3f(x2, y2, z2);

				//POINT 4

				x2 = cosf(theta * la) * sinf(delta * (lo + 1));
				y2 = cosf(delta * (lo + 1));
				z2 = sinf(theta * la) * sinf(delta * (lo + 1));

				glTexCoord2f((u * la), (v * lo) + v);		//FOURTH POINT TEXT COORDS
				glNormal3f(x2, y2, z2);
				glVertex3f(x2, y2, z2);
			}
			glEnd();
		}
	}








}

