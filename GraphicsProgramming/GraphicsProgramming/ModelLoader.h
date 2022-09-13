
//MODEL CLASS THAT ALLOWS TO LOAD MODELS AND TEXTURES.
#define PI 3.1415


// INCLUDES //
#include <glut.h>
#include <fstream>
#include <gl/gl.h>
#include <gl/glu.h>

// MY CLASS INCLUDES //
#include <vector>
#include "Vector3.h"
#include "SOIL.h"
#include "Model.h"
class ModelLoader : public Model	//Model class inherited
{




public:
	ModelLoader();		//CONSTRUCTOR
	~ModelLoader();		//DESTRUCTOR

	void modelRender(float lats, float longs);		//function that renders all the models, called in scene.cpp
	void modelLoader();


	void floorRender();
	void sunRender(float lats, float longs);

protected:
	GLuint floor;		//floor texture
	GLuint sun;		//sun texture

	Model sphinx;		//sphinx model
	Model pyramid;
	
	float pyrX;
	float pyrY;
	float pyrZ;

	float plane[18] = { 0.0, 0.0, 0.0,
				  1.0, 0.0, 0.0,
				  0.0, 1.0, 0.0,
				  1.0, 0.0, 0.0,
				  1.0,1.0,0.0,
				  0.0,1.0,0.0 };

	int increaserX;
	int increaserY;
};

