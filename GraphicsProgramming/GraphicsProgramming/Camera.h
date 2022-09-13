#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
#include "SOIL.h"
#include <vector>
#include "Vector3.h"
#include<math.h>
class Camera
{



public:
	Vector3 position;
	Vector3 lookAt;
	Vector3 forward;
	Vector3 up;
	Vector3 right;
	Vector3 upVec;
public:

	Camera();
	~Camera();


	void calculateValues();
	void calculateForward();
	void calculateBackwards();
	void calculateRight();
	void calculateUp();

	void moveLeft(float dt);
	void moveRight(float dt);
	void moveForward(float dt);
	void moveBackwards(float dt);
	void moveUp(float dt);
	void moveDown(float dt);

	void rotationRight(float dt);
	void rotationLeft(float dt);
	void rotationDown(float dt);
	void rotationUp(float dt);

	void update();


	void setPosition(Vector3 posi);
	void setLookAt(Vector3 look);

	Vector3 getPosition();

	void handleInput(Input* in, float dt, int w, int h);


private:
	float cosR, cosP, cosY; //temp values for sin/cos from
	float sinR, sinP, sinY;

protected:

	Input* input;
	float yaw;
	float pitch;
	float roll;

	float upX, upY, upZ;
};

