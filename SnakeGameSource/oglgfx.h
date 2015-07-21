#include "snake.h"
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <QtOpenGL>
#include <math.h>
#include <string>
#include <unistd.h>
#include "kbdctl.h"

#define SWAPBUFFERS SwapBuffers(ghDC)
#define WIDTH 300
#define HEIGHT 200

#define WINDOW_STYLE WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
extern char szAppName[];

void FindSnake(GLdouble &nx, GLdouble &ny, GLdouble &nz);
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
void gamepad(unsigned int buttonMask, int x, int y, int z);
GLvoid PutCube (GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2);
GLvoid tPutCube (GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2);
GLvoid uctPutCube (GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2);
GLvoid PutMiniCube(int x, int y, int p);
GLvoid polarView (GLdouble radius);
GLvoid drawSceneU(void);
GLvoid  drawScene(void);
class oglgfx : public snakegfx, public snakectl
{
	friend void drawScene(void);
	friend void drawSceneU(void);
	friend void processNormalKeys(unsigned char key, int x, int y);
	friend void processSpecialKeys(int key, int x, int y);
	friend void PutMiniCube(int x, int y, int p);
	friend void polarView(GLdouble radius);

private:

	int keypress;
	int speed;

    GLfloat angle;
	GLdouble radius;

	GLfloat curlng;
	GLfloat curlat;
	GLfloat deslng;
	GLfloat deslat;

	/* Draw a cube */
	GLvoid resize(GLsizei,GLsizei);
	void polarView(GLdouble);
	void createObjects();
	
public:

	int pollinput();
	int getinput();
	int isai();

	//.void __cdecl processSpecialKeys(int key, int x, int y);

	/* initialize gfx */
	virtual void init(int argc, char **argv);

	/* render the whole field. override me */
	virtual void renderplane(snakeplane* sp, snake *s);

	/* rotate the cube to a given side */
	void rotatecube(int side);

	/* constructor */
	oglgfx();
	/* destructor */
	virtual ~oglgfx();
};


