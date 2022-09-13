#include "Camera.h"
Camera::Camera()
{

	position.set(0.0f, 1.0, 6.0f);
	up.set(0.0, 1.0, 0.0);
	lookAt.set(0.0, 0.0, 0.0);

	yaw = 0;
	pitch = 0;
	roll = 0;

}

Camera::~Camera()
{

}

void Camera::update()
{
	gluLookAt
	(position.x, position.y, position.z,
		lookAt.x, lookAt.y, lookAt.z,
		up.x, up.y, up.z);
}

void Camera::calculateValues()
{
	cosY = cosf(yaw * 3.1415 / 180);
	cosP = cosf(pitch * 3.1415 / 180);
	cosR = cosf(roll * 3.1415 / 180);

	sinY = sinf(yaw * 3.1415 / 180);
	sinP = sinf(pitch * 3.1415 / 180);
	sinR = sinf(roll * 3.1415 / 180);
}

void Camera::calculateForward()
{
	forward.x = sinY * cosP;
	forward.y = sinP;
	forward.z = cosP * -cosY;

}

void Camera::calculateUp()
{
	upX = -cosY * sinR - sinY * sinP * cosR;
	upY = cosP * cosR;
	upZ = -sinY * sinR - sinP * cosR * -cosY;
	upVec.set(upX, upY, upZ);
}

void Camera::calculateRight()
{
	right = forward.cross(upVec);

}

void Camera::moveRight(float dt)
{
	calculateValues();
	calculateForward();
	calculateUp();
	Vector3 right;


	right = forward.cross(upVec);


	right.scale(dt * 100);
	position.add(right);


	lookAt.add(right);

	setPosition(position);
	setLookAt(lookAt);
}

void Camera::moveLeft(float dt)
{
	calculateValues();
	calculateForward();
	calculateUp();
	Vector3 right;


	right = forward.cross(upVec);
	right.scale(-1);

	right.scale(dt * 100);
	position.add(right);


	lookAt.add(right);

	setPosition(position);
	setLookAt(lookAt);
}


void Camera::handleInput(Input* in, float dt, int w, int h)
{
	input = in;
	float x = input->getMouseX();
	float y = input->getMouseY();

	pitch -= (y - (h / 2)) * (dt * 10);
	yaw += (x - (w / 2)) * (dt * 10);

	calculateValues();
	calculateForward();
	calculateUp();
	calculateRight();


	setLookAt(position + forward);

}

void Camera::moveForward(float dt)
{
	calculateValues();
	calculateForward();
	//forward.y = 0;			//CAMERA WON'T BE ABLE TO FLY

	forward.scale(dt * 100);
	position.add(forward);


	lookAt.add(forward);

	setPosition(position);
	setLookAt(lookAt);
}

void Camera::moveBackwards(float dt)
{
	calculateValues();
	calculateForward();

	forward.scale(dt * 100);
	position.subtract(forward);


	lookAt.subtract(forward);

	setPosition(position);
	setLookAt(lookAt);
}

void Camera::moveUp(float dt)
{
	calculateValues();
	calculateUp();

	upVec.scale(dt * 100);
	position.add(upVec);


	lookAt.add(upVec);

	setPosition(position);
	setLookAt(lookAt);
}

void Camera::moveDown(float dt)
{
	calculateValues();
	calculateUp();

	upVec.scale(dt * 100);
	position.subtract(upVec);


	lookAt.subtract(upVec);

	setPosition(position);
	setLookAt(lookAt);
}

void Camera::rotationRight(float dt)
{
	calculateValues();
	calculateForward();
	calculateUp();
	Vector3 right;


	right = forward.cross(upVec);


	right.scale(dt * 10);

	lookAt.add(right);

	setPosition(position);
	setLookAt(lookAt);
}

void Camera::rotationLeft(float dt)
{
	calculateValues();
	calculateForward();
	calculateUp();
	Vector3 right;
	right.scale(-1);

	right = forward.cross(upVec);


	right.scale(dt * 10);

	lookAt.subtract(right);

	setPosition(position);
	setLookAt(lookAt);
}

void Camera::rotationUp(float dt)
{
	calculateValues();
	calculateUp();

	upVec.scale(dt * 100);



	lookAt.add(upVec);

	setPosition(position);
	setLookAt(lookAt);
}

void Camera::rotationDown(float dt)
{
	calculateValues();
	calculateUp();

	upVec.scale(dt * 100);
	lookAt.subtract(upVec);

	setPosition(position);
	setLookAt(lookAt);
}

void Camera::setLookAt(Vector3 look)
{
	this->lookAt = look;
}


void Camera::setPosition(Vector3 posi)
{
	this->position = posi;
}

Vector3 Camera::getPosition()
{
	return position;
}
