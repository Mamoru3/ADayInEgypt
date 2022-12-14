#include "Scene.h"

// Scene constructor, initilises OpenGL
// You should add further variables to need initilised.
Scene::Scene(Input *in)
{
	// Store pointer for input class
	input = in;
	initialiseOpenGL();

	// Other OpenGL / render setting should be applied here.
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	
	// Initialise scene variables

	//Model loading
	
	

}

void Scene::handleInput(float dt)
{
	// Handle user input
	inputMan(dt);

}

void Scene::update(float dt)
{
	// update scene related variables.




	// Calculate FPS for output
	calculateFPS();
}

void Scene::render() {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Reset transformations
	glLoadIdentity();
	// Set the camera


	//Camera update


	
	camera.update();

	glutWarpPointer(width / 2, height / 2);
	glutSetCursor(GLUT_CURSOR_NONE);
	

	glPushMatrix();
	{

	light.render(30, 30);
	}
	glPopMatrix();



	
	glPushMatrix();
	{
		glDisable(GL_LIGHTING);
		skybox.setPosition(camera.getPosition());
		skybox.setCube();
		glEnable(GL_LIGHTING);
	}
	glPopMatrix();
	

	glPushMatrix();
	{
		model.modelRender(40,40);
	}
	glPopMatrix();


	

	// Render geometry/scene here -------------------------------------
	


	// End render geometry --------------------------------------

	// Render text, should be last object rendered.
	renderTextOutput();
	
	// Swap buffers, after all objects are rendered.
	glutSwapBuffers();
}

void Scene::initialiseOpenGL()
{
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.39f, 0.58f, 93.0f, 1.0f);			// Cornflour Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	glEnable(GL_NORMALIZE);
}

// Handles the resize of the window. If the window changes size the perspective matrix requires re-calculation to match new window size.
void Scene::resize(int w, int h) 
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 5000.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

// Calculates FPS
void Scene::calculateFPS()
{
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
}

// Compiles standard output text including FPS and current mouse position.
void Scene::renderTextOutput()
{
	// Render current mouse position and frames per second.
	sprintf_s(mouseText, "Mouse: %i, %i", input->getMouseX(), input->getMouseY());
	displayText(-1.f, 0.96f, 1.f, 0.f, 0.f, mouseText);
	displayText(-1.f, 0.90f, 1.f, 0.f, 0.f, fps);
}

// Renders text to screen. Must be called last in render function (before swap buffers)
void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width/(float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}

void Scene::inputMan(float dt)
{
	camera.handleInput(input, dt, width, height);

	// Handle user input
	//Player is allowed to move only forward, backwards, left and right
	if (input->isKeyDown('w'))
	{
		camera.moveForward(dt);
		input->setKeyUp('w');
	}
	if (input->isKeyDown('s'))
	{
		camera.moveBackwards(dt);
		input->setKeyUp('s');
	}
	if (input->isKeyDown('d'))
	{
		camera.moveRight(dt);
		input->setKeyUp('d');
	}
	if (input->isKeyDown('a'))
	{
		camera.moveLeft(dt);
		input->setKeyUp('a');
	}
/*	if (input->isKeyDown('i'))
	{
		camera.moveUp(dt);
		input->setKeyUp('i');
	}
	if (input->isKeyDown('o'))
	{
		camera.moveDown(dt);
		input->setKeyUp('o');
	}
	if (input->isKeyDown('m'))
	{
		camera.rotationRight(dt);
		input->setKeyUp('m');
	}
	if (input->isKeyDown('b'))
	{
		camera.rotationLeft(dt);
		input->setKeyUp('b');
	}
	if (input->isKeyDown('j'))
	{
		camera.rotationUp(dt);
		input->setKeyUp('j');
	}
	if (input->isKeyDown('n'))
	{
		camera.rotationDown(dt);
		input->setKeyUp('n');
	}*/
}