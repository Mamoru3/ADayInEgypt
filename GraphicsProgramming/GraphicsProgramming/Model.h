#ifndef _MODEL_H_
#define _MODEL_H_
//MODEL CLASS THAT ALLOWS TO LOAD MODELS AND TEXTURES.


// INCLUDES //
#include <glut.h>
#include <fstream>
#include <gl/gl.h>
#include <gl/glu.h>

using namespace std;

// MY CLASS INCLUDES //
#include <vector>
#include "Vector3.h"
#include "SOIL.h"

class Model
{



public:

	Model();
	~Model();

	bool load(char* modelFilename, char* textureFilename);
	void render();

	void loadFloor();


private:

	void loadTexture(char*);
	bool loadModel(char*);

	// model texture
	GLuint texture;
	
	// Stoagre for sorted data

	vector<float> vertex, normals, texCoords;

};

#endif