#include "oglgfx.h"
#include "snake.h"

GLfloat angle;
GLfloat radius = 5.0; //radius of vision: > 6.0 - screen in not vision, < vision from inside cube, lol
GLdouble fct = 0;
//GLuint	texture[1];

bool needupdate;
snakeplane* sp;
snake* s;
int speedsetting = 0;
snakegame *maingame;
oglgfx *maingfx;

/*
GLvoid LoadGLTextures()
{
	// �������� ��������
	AUX_RGBImageRec *texture1;
	texture1 = auxDIBImageLoad("../back.bmp");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
}
    void polarView(GLdouble radius);
    void PutCube(GLfloat x1, GLfloat y1, GLf

GLvoid InitGL(GLsizei Width, GLsizei Height)
{
LoadGLTextures();			// �������� �������
glEnable(GL_TEXTURE_2D);		// ���������� ��������� ��������
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glClearDepth(1.0);
glDepthFunc(GL_LESS);
glEnable(GL_DEPTH_TEST);
glShadeModel(GL_SMOOTH);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);

glMatrixMode(GL_MODELVIEW);
}
*/
const GLubyte texture[]= 
 {
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x80,
  0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,
  0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,
  0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,
  0x00,0xff,0x00,0x00,0xff,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,
  0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,
  0x80,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,
  0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,
  0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,
  0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,
  0x00,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,
  0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,
  0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
  0x80,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,
  0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0xff,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,
  0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x00,
  0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,
  0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,
  0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,
  0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,
  0x00,0xff,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,
  0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,
  0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x00,
  0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,
  0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,
  0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,
  0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,
  0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,
  0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,
  0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,
  0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,
  0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x00,
  0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,
  0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,
  0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x00,
  0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x00,0x00,0xff,0x80,0x80,0x00,0x00,0x00,0xff,0x00,0x00,0xff,
  0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xff,0x80,0x80,0x00,0x00,
  0x00,0x00,0x00,0x00,0xff,0x00,0xff,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,
  0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,
  0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,
  0x00,0x80,0x80,0x00,0x00
  };
  
GLubyte fulltex[] = {
	0xff, 0xff, 0xff
};

void text(char* string)
{
    char* p;

    for (p = string; *p; p++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18  , *p); //choose font for ingame text
	/* fonts, for example u also can use: 

	        |  GLUT_BITMAP_9_BY_15         |
		    |  GLUT_BITMAP_8_BY_13         |
		    |  GLUT_BITMAP_TIMES_ROMAN_10  |
		    |  GLUT_BITMAP_TIMES_ROMAN_24  |
		    |  GLUT_BITMAP_HELVETICA_10    |
		    |  GLUT_BITMAP_HELVETICA_12    |
		    |  GLUT_BITMAP_HELVETICA_18    |

		thats only BITMAP text options
    */
}

void oglgfx :: init (int argc, char **argv)
{
	int  fullscreen;
	char modestring [50];
	cout << "system: SuperSnake3D 2013" << endl;
	cout << "system: ver.: 1.0a" << endl;
	cout << "system: initializing GLUT" << endl;

    glutInit(&argc,argv);
	cout << "system: setting up display modes" << endl;
    if (argc > 1 && !strcmp(argv[1], "-w")) fullscreen = GL_FALSE;
    else fullscreen = GL_TRUE;

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	if (fullscreen) {
		cout << "system: entering fullscreen mode" << endl;
		cout << "system: run with -w to override" << endl;
		cout << "system: input a full-screen mode string in the form of \"Width x Height\"" << endl;
		cout << "user: ";
		//cin  >> modestring;
		cout << "system: entering game mode at " << modestring << "...";
		glutGameModeString(modestring);
		glutEnterGameMode();
	} else {
		/*cout << "system: entering windowed mode." << endl;*/
		glutInitWindowSize(1280, 720);
		glutCreateWindow("SuperSnake 3D");
      //  glutFullScreen();

	}

	cout << "system: setting up event handlers." << endl;

    glutDisplayFunc(drawScene);
    glutIdleFunc(snakeup);
    glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc (processSpecialKeys);
    glutJoystickFunc(gamepad, 300);
	glutForceJoystickFunc();
	speedsetting = 100;

	cout << "system: setting up depth buffer." << endl;

	glEnable(GL_DEPTH_TEST); 
 

	//������������ �����������
    glMatrixMode(GL_PROJECTION);  
    gluPerspective(45.0, 1.5, 2.0, 10.0); /* �����������: ������ �������� - ����������� ��������� �����: ����������� ������ ��� ������,
	                                         ���� ��������� ������������, ����������� � �������� 0 - 180, 
	                                         ������ - �� ���� ������ ������� �����, � ��� ��� ���� �������� �� ��� Y*/

	//������������ ���� �������
    glMatrixMode(GL_MODELVIEW); 


	cout << "system: setting up lighting and colors." << endl;

	glColorMaterial(GL_BACK, GL_AMBIENT_AND_DIFFUSE);
	
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	cout << "system: setting up texturization." << endl;
	
	glEnable(GL_TEXTURE_2D);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 32, 32, 0, 
		 GL_BGR_EXT, GL_UNSIGNED_BYTE, texture);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    radius = 5.0;
    angle = 0.0f;
	curlat=curlng=deslat=deslng=0;
	cout << "system: entering main loop..." << endl;
	glutMainLoop();
}

void processNormalKeys(unsigned char key, int x, int y)
{

	char buf[30];
	switch (key)
	{
	case 'q':
	case 'Q':
	case 27:
		exit(0);
	case '8':
		maingfx->keypress = DIR_UP;
		break;
	case '4':
		maingfx->keypress = DIR_LEFT;
		break;
	case '6':
		maingfx->keypress = DIR_RIGHT;
		break;
	case '2':
		maingfx->keypress = DIR_DOWN;
		break;
	case 's':
    case 'S':
        sprintf(&buf[0], "Your score is %d.", maingame->players[0]->score);
        /*msgBox.setText(&buf[0]);
        msgBox.exec();*/
		break;
	case '0':
		speedsetting = speedsetting + 1;
		speedsetting = speedsetting > 100 ? 100 : speedsetting;
		break;
	case '9':
		speedsetting = speedsetting - 1;
		speedsetting = speedsetting < 0 ? 0 : speedsetting;
		break;
    default:
        maingfx->keypress = 0;
		glRasterPos2i(0,0);
		text("Illegal input - use the numpad to turn.");
        /*msgBox.setText("Illegal input - use the numpad to turn.");
        msgBox.exec();*/
//		MessageBeep(MB_OK);

#define ANNOYING_MESSAGE MessageBox(NULL, "Illegal input.\n8/4/6/2 = turn\nS = score\nQ = exit.", "Snake3D/Win32",0);
		break;
	}
}

/* GLUT_KEY_LEFT, _UP, _RIGHT, and _DOWN. */
void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		maingfx->keypress = DIR_UP;
		break;
	case GLUT_KEY_LEFT:
		maingfx->keypress = DIR_LEFT;
		break;
	case GLUT_KEY_RIGHT:
		maingfx->keypress = DIR_RIGHT;
		break;
	case GLUT_KEY_DOWN:
		maingfx->keypress = DIR_DOWN;
		break;
	default:
		maingfx->keypress = 0;
//		MessageBeep(MB_OK);
	};
}
void gamepad(unsigned int buttonMask, int x, int y, int z){
			char buf[100];
	if(buttonMask & GLUT_JOYSTICK_BUTTON_A) {
		sprintf(&buf[0], "button A is pressed");
	}
	if(buttonMask & GLUT_JOYSTICK_BUTTON_B) {
		sprintf(&buf[0], "button B is pressed");
	}
	if(buttonMask & GLUT_JOYSTICK_BUTTON_C) {
		sprintf(&buf[0], "button C is pressed ");
	}
	if(buttonMask & GLUT_JOYSTICK_BUTTON_D) {
		sprintf(&buf[0], "button D is pressed ");
	}
}
oglgfx :: oglgfx ()
{
	//MessageBox(NULL,"oglgfx class created","oglgfx",0);
	maingfx = this;
	keypress = 0;
}

oglgfx :: ~oglgfx ()
{
	//MessageBox(NULL,"oglgfx class destroyed","oglgfx",0);
}

void oglgfx :: renderplane (snakeplane *spx, snake *sx)
{
	needupdate = 1;
	sp = spx;
	s = sx;
	drawSceneU();
}

void oglgfx :: rotatecube (int side)
{
	maingame->pause = 1;
	deslng=deslat=0;

	switch (side)
	{
	case 3:
		deslng=90;
		break;
	case 5:
		deslng=-90;
		break;
	case 1:
		deslat=180;
		break;
	case 2:
		deslat=90;
		break;
	case 6:
		deslat=-90;
	default:
		break;
	}
}

int oglgfx :: pollinput ()
{
	if (keypress != 0)
		return 1;
	else
		return 0;
}

int oglgfx :: getinput ()
{
	int temp = keypress;
	keypress = 0;
	return temp;
}


int oglgfx :: isai()
{
	return 0;
}


GLvoid oglgfx :: resize( GLsizei width, GLsizei height ) 
{ 
    GLfloat aspect; 
 
    glViewport( 0, 0, width, height ); 
 
    aspect = (GLfloat) width / height; 
 
    glMatrixMode( GL_PROJECTION ); 
    glLoadIdentity(); 
    gluPerspective( 45.0, aspect, 3.0, 7.0 );
    glMatrixMode( GL_MODELVIEW ); 
}     

GLvoid drawScene()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up some colors
	static GLdouble red[3] = {0.8, 0.0, 0.0};
	static GLdouble green[3] = {0.0, 0.75, 0.0};
	static GLdouble blue[3] = {0.0, 0.0, 1.0};

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_TEXTURE_2D);

    glPushMatrix();

    polarView(radius); 

	glColor3dv(green);
	//glBindTexture(GL_TEXTURE_2D, 1);
	PutCube (-1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f);
	
	fct += 0.05;

	glPopMatrix();  
 
    glutSwapBuffers(); 

}

//GLvoid __cdecl drawSceneU(GLvoid)
GLvoid drawSceneU()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up some colors
	static GLdouble red[3] = {2.0, 0.0, 0.0};
	static GLdouble green[3] = {0.0, 2.0, 0.0};
	static GLdouble blue[3] = {0.0, 0.0, 2.0};

    glPushMatrix();

	fct = (fct < 3.14159) ? (fct + 0.05) : (0);

	maingfx->rotatecube(maingame->snakes[0]->last->side);

    polarView( radius); 

	glColor3dv(green);;

    /*PutCube(0,0,0,0.1,0.1,2);
	glColor3dv(red);
	PutCube(0,0,0,2,0.1,0.1);
	glColor3dv(blue);
    PutCube(0,0,0,0.1,2,0.1);*/

    /*for (int i=0;i<6;i++)
	{
		glColor3dv(green);
        PutMiniCube(0,0,i);
		glColor3dv(red);
		PutMiniCube(15,0,i);
		glColor3dv(blue);
		PutMiniCube(0,15,i);
    }*/

	

	for (int p=0;p<6;p++)
	{
		for (int x=0;x<BOARDWIDTH;x++)
		{
			for (int y=0;y<BOARDWIDTH;y++)
			{
				short cell;
				cell = sp->grid[x][y][p];
				if (cell)
				{
					switch (cell)
					{
					case CELL_BLOCK:
						glColor3dv(blue);
						break;
					case CELL_SNAKE:              //color of snake
						glColor3d(40,255,0);
						break;
					case CELL_FOOD:               //color of food (mini cubes/blocks)
						glColor3dv(red);
						break;
				    case CELL_FOOD_2:               
						glColor3dv(green);
						break;
					default:
						cout << "uhh... watsa " << cell << "? a food is " << CELL_FOOD << "..." << endl;
						cout << "uhh... watsa " << cell << "? a food is " << CELL_FOOD_2 << "..." << endl;
						cerr << "err> illegal cell" << endl;
						cerr.flush();
						glColor3d(0,0,0);
					}
                   PutMiniCube(x,y,p);
               }
			}
		}
	}
	
	//glColor3d(0,0,0);
    //glBindTexture(GL_TEXTURE_2D, 1);
    uctPutCube (-1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f);

	glPopMatrix();  
 
    glutSwapBuffers(); 

   usleep(speedsetting*500);
}

#define FACETYPE GL_POLYGON /* or GL_LINES, but turn off lighting... */

GLvoid PutCube (GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2)
{
	glBegin (FACETYPE);               //right face
		glNormal3d(  0.0,   0.0,  z2);
		glVertex3d(   x2,    y2,  z2); 
		glVertex3d(   x1,    y2,  z2);
		glVertex3d(   x1,    y1,  z2);           
		glVertex3d(   x2,    y1,  z2);  
	glEnd();
	
	glBegin(FACETYPE);	//left
		glNormal3d(  0.0,   0.0,   z1);
		glVertex3d(   x2,    y2,   z1);
		glVertex3d(   x2,    y1,   z1);           
		glVertex3d(   x1,    y1,   z1);          
		glVertex3d(   x1,    y2,   z1);           
	glEnd();
	
	glBegin(FACETYPE); //Front
		glNormal3d(x1,  0.0,  0.0);
	    glVertex3d(x1,  y2,  z2);
	    glVertex3d(x1,  y2, z1);           
	    glVertex3d(x1, y1, z1);          
	    glVertex3d(x1, y1,  z2);           
	glEnd();

	glBegin(FACETYPE);  //Back
		glNormal3d(x2,  0.0,  0.0);
	    glVertex3d(x2,  y2,  z2);
	    glVertex3d(x2, y1,  z2);            
	    glVertex3d(x2, y1, z1);           
	    glVertex3d(x2,  y2, z1);            
	glEnd();

	glBegin(FACETYPE);  //Top
		glNormal3d( 0.0, y2,  0.0);
	    glVertex3d(x1, y2, z1);
	    glVertex3d(x1, y2,  z2);
	    glVertex3d( x2, y2,  z2);             
	    glVertex3d( x2, y2, z1);            
	glEnd();

	glBegin(FACETYPE);	//Bottom
		glNormal3d( 0.0, y1,  0.0);
	    glVertex3d(x1, y1, z1);
	    glVertex3d( x2, y1, z1);           
	    glVertex3d( x2, y1,  z2);            
	    glVertex3d(x1, y1,  z2);           
	glEnd();

}


/* Texturized! PutCube */
GLvoid tPutCube (GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2)
{
	glBegin (FACETYPE);               //right face
		glNormal3d(  0.0,   0.0,  z2);
		glTexCoord2f(1.0, 1.0);
		glVertex3d(   x2,    y2,  z2); 
		glTexCoord2f(0.0, 1.0);
		glVertex3d(   x1,    y2,  z2);
		glTexCoord2f(0.0, 0.0);
		glVertex3d(   x1,    y1,  z2);           
		glTexCoord2f(1.0, 0.0);
		glVertex3d(   x2,    y1,  z2);  
	glEnd();
	
	glBegin(FACETYPE);	//left
		glNormal3d(  0.0,   0.0,   z1);
		glTexCoord2f(1.0, 1.0);
		glVertex3d(   x2,    y2,   z1);
		glTexCoord2f(1.0, 0.0);
		glVertex3d(   x2,    y1,   z1);           
		glTexCoord2f(0.0, 0.0);
		glVertex3d(   x1,    y1,   z1);          
		glTexCoord2f(0.0, 1.0);
		glVertex3d(   x1,    y2,   z1);           
	glEnd();
	
	glBegin(FACETYPE); //Front
		glNormal3d(x1,  0.0,  0.0);
		glTexCoord2f(1.0, 1.0);
	    glVertex3d(x1,  y2,  z2);
		glTexCoord2f(1.0, 0.0);
	    glVertex3d(x1,  y2, z1);           
		glTexCoord2f(0.0, 0.0);
	    glVertex3d(x1, y1, z1);
		glTexCoord2f(0.0, 1.0);
	    glVertex3d(x1, y1,  z2);           
	glEnd();

	glBegin(FACETYPE);  //Back
		glNormal3d(x2,  0.0,  0.0);
		glTexCoord2f(1.0, 1.0);
	    glVertex3d(x2,  y2,  z2);
		glTexCoord2f(0.0, 1.0);
	    glVertex3d(x2, y1,  z2);            
		glTexCoord2f(0.0, 0.0);
	    glVertex3d(x2, y1, z1);
		glTexCoord2f(1.0, 0.0);
	    glVertex3d(x2,  y2, z1);            
	glEnd();

	glBegin(FACETYPE);  //Top
		glNormal3d( 0.0, y2,  0.0);
		glTexCoord2f(0.0, 0.0);
	    glVertex3d(x1, y2, z1);
		glTexCoord2f(0.0, 1.0);
		glVertex3d(x1, y2,  z2);
		glTexCoord2f(1.0, 1.0);
	    glVertex3d( x2, y2,  z2);             
		glTexCoord2f(1.0, 0.0);
	    glVertex3d( x2, y2, z1);            
	glEnd();

	glBegin(FACETYPE);	//Bottom
		glNormal3d( 0.0, y1,  0.0);
		glTexCoord2f(0.0, 0.0);
	    glVertex3d(x1, y1, z1);
		glTexCoord2f(1.0, 0.0);
	    glVertex3d( x2, y1, z1);
		glTexCoord2f(1.0, 1.0);
	    glVertex3d( x2, y1,  z2);
		glTexCoord2f(0.0, 1.0);
	    glVertex3d(x1, y1,  z2);           
	glEnd();
}

/* UltraColorTexturized! PutCube */
GLvoid uctPutCube (GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2)
{
	glBegin (FACETYPE);               //right face
		glNormal3d(  0.0,   0.0,  z2);
		glColor3ub(255, 255, 255);
		glTexCoord2f(1.0, 1.0);
		glVertex3d(   x2,    y2,  z2); 
		glColor3ub(0, 0, 255);
		glTexCoord2f(0.0, 1.0);
		glVertex3d(   x1,    y2,  z2);
		glColor3ub(0, 255, 0);
		glTexCoord2f(0.0, 0.0);
		glVertex3d(   x1,    y1,  z2);           
		glColor3ub(255, 0, 0);
		glTexCoord2f(1.0, 0.0);
		glVertex3d(   x2,    y1,  z2);  
	glEnd();
	
	glBegin(FACETYPE);	//left
		glNormal3d(  0.0,   0.0,   z1);
		glColor3ub(255, 255, 255);
		glTexCoord2f(1.0, 1.0);
		glVertex3d(   x2,    y2,   z1);
		glColor3ub(0, 0, 255);
		glTexCoord2f(1.0, 0.0);
		glVertex3d(   x2,    y1,   z1);           
		glColor3ub(0, 255, 0);
		glTexCoord2f(0.0, 0.0);
		glVertex3d(   x1,    y1,   z1);          
		glColor3ub(255, 0, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex3d(   x1,    y2,   z1);           
	glEnd();
	
	glBegin(FACETYPE); //Front
		glNormal3d(x1,  0.0,  0.0);
		glColor3ub(255,255,255);
		glTexCoord2f(1.0, 1.0);
	    glVertex3d(x1,  y2,  z2);
		glColor3ub(0,0,255);
		glTexCoord2f(1.0, 0.0);
	    glVertex3d(x1,  y2, z1);
		glColor3ub(0,255,0);
		glTexCoord2f(0.0, 0.0);
	    glVertex3d(x1, y1, z1);
		glColor3ub(255,0,0);
		glTexCoord2f(0.0, 1.0);
	    glVertex3d(x1, y1,  z2);           
	glEnd();

	glBegin(FACETYPE);  //Back
		glNormal3d(x2,  0.0,  0.0);
		glColor3ub(255,255,255);
		glTexCoord2f(0.0, 0.0);
	    glVertex3d(x2,  y2,  z2);
		glColor3ub(0,0,255);
		glTexCoord2f(1.0, 0.0);
	    glVertex3d(x2, y1,  z2);            
		glColor3ub(0,255,0);
		glTexCoord2f(1.0, 1.0);
	    glVertex3d(x2, y1, z1);
		glColor3ub(255,0,0);
		glTexCoord2f(0.0, 1.0);
	    glVertex3d(x2,  y2, z1);            
	glEnd();

	glBegin(FACETYPE);  //Top
		glNormal3d( 0.0, y2,  0.0);
		glColor3ub(255,255,255);
		glTexCoord2f(0.0, 0.0);
	    glVertex3d(x1, y2, z1);
		glColor3ub(0,0,255);
		glTexCoord2f(0.0, 1.0);
		glVertex3d(x1, y2,  z2);
		glColor3ub(0,255,0);
		glTexCoord2f(1.0, 1.0);
	    glVertex3d( x2, y2,  z2);
		glColor3ub(255,0,0);
		glTexCoord2f(1.0, 0.0);
	    glVertex3d( x2, y2, z1);            
	glEnd();

	glBegin(FACETYPE);	//Bottom
		glNormal3d( 0.0, y1,  0.0);
		glColor3ub(255,255,255);
		glTexCoord2f(0.0, 0.0);
	    glVertex3d(x1, y1, z1);
		glColor3ub(0,0,255);
		glTexCoord2f(1.0, 0.0);
	    glVertex3d( x2, y1, z1);
		glColor3ub(0,255,0);
		glTexCoord2f(1.0, 1.0);
	    glVertex3d( x2, y1,  z2);
		glColor3ub(255,0,0);
		glTexCoord2f(0.0, 1.0);
	    glVertex3d(x1, y1,  z2);           
	glEnd();

}

#define ROTSPEED 7
#define ADJUSTCONST 0.095
#define LINEX(num) ((1.450) - (ADJUSTCONST*num))

void polarView(GLdouble radius) 
{ 
	char buf[100];
	static float frames = 0.0f;

	glTranslated(0.0, 0.0, -0.3);
	glTranslated(0.0, 0.0, -radius); 

	glDisable(GL_LIGHTING);

	glColor3f(sin(frames) < 0.5 ? 0.5 : sin(frames), sin(frames*2) < 0.5 ? 0.5 : sin(frames * 2), sin(frames*3) < 0.5 ? 0.5 : sin(frames*3));
	frames += 0.05f;

	glRasterPos3f(-1.55f, LINEX(0), 1.0f);
	text("SuperSnake3D");
    sprintf(&buf[0], "Speed: %d. Use 0 and 9 to change.", ((speedsetting-100)*(-1)));
	glRasterPos3f(-1.55f, LINEX(1), 1.0f);
	text(&buf[0]);

	sprintf(&buf[0], "Score: %d.", maingame->players[0]->score);
	glRasterPos3f(-1.55f, LINEX(2), 1.0f);
	text(&buf[0]);

	glEnable(GL_LIGHTING);

	glRotatef(maingfx->curlng,0,1,0);
	glRotatef(maingfx->curlat,1,0,0);

	maingame->pause=0;
	if (maingfx->deslat>maingfx->curlat)
	{
		maingame->pause=1;
		maingfx->curlat+=ROTSPEED;
		if (maingfx->deslat<maingfx->curlat)
			maingfx->curlat=maingfx->deslat;
	}
	else if (maingfx->deslat<maingfx->curlat)
	{
		maingame->pause=1;
		maingfx->curlat-=ROTSPEED;
		if (maingfx->deslat>maingfx->curlat)
			maingfx->curlat=maingfx->deslat;
	}

	if (maingfx->deslng>maingfx->curlng)
	{
		maingame->pause=1;
		maingfx->curlng+=ROTSPEED;
		if (maingfx->deslng<maingfx->curlng)
			maingfx->curlng=maingfx->deslng;
	}
	else if (maingfx->deslng<maingfx->curlng)
	{
		maingame->pause=1;
		maingfx->curlng-=ROTSPEED;
		if (maingfx->deslng>maingfx->curlng)
			maingfx->curlng=maingfx->deslng;
	}	

/*	GLfloat yaw,pitch;
	GLdouble xs,ys,zs;

	FindSnake(xs,ys,zs);

#define PI 3.1415926535897932384626433832795

	yaw = (180/PI)* atan2(-zs,xs);
	pitch = (180/PI)* acos(ys/(sqrt((xs*xs)+(ys*ys)+zs*zs)));

	glRotatef(yaw,0,1,0);
	glRotatef(pitch,1,0,0);

/*	glRotatef(angle, 1,0,1);
	angle++;*/
}

void PutMiniCube(int x, int y, int p)  //������� ����� (���)
{
	switch (p)
	{
	case 0:
		PutCube(-1.0+(x*.125),	1.0-(y*.125),	-1.125,
			    -.875+(x*.125),	.875-(y*.125),	-1.0);
		return;
	case 1:
		PutCube(-1.0f+(x*.125),	1.0,			1.0-(y*.125),
				-.875+(x*.125), 1.125,			.875-(y*.125));
		return;
	case 2:
		PutCube(-1.125,			-.875+(y*.125),	-.875+(x*.125),
				-1.0,			-1.0+(y*.125), 	-1.0+(x*.125));
		return;
	case 3:
		PutCube(-1.0+(x*.125),	-1.0+(y*.125),	1.0,
			    -.875+(x*.125),	-.875+(y*.125),	1.125);
		return;
	case 4:
		PutCube(1.0,			-1.0+(y*.125),	1.0-(x*.125),
				1.125,			-.875+(y*.125), .875-(x*.125));
		return;
	case 5:
		PutCube(-1.0f+(x*.125),	-1.0,			-1.0+(y*.125),
				-.875+(x*.125), -1.125,			-.875+(y*.125));
		return;
	}
}
/*
void FindSnake(GLdouble &nx, GLdouble &ny, GLdouble &nz)
{
	int x,y,p;
	x = maingame->snakes[0]->last->x;
	y = maingame->snakes[0]->last->y;
	p = maingame->snakes[0]->last->side;

	switch (p)
	{
	case 1:
		nx=-1.0+(x*.125);
		ny=1.0-(y*.125);
		nz=-1.125;
		return;
	case 2:
		nx=-1.0f+(x*.125);
		ny=1.0;
		nz=1.0-(y*.125);
		return;
	case 3:
		nx=-1.125;
		ny=-.875+(y*.125);
		nz=-.875+(x*.125);
		return;
	case 4:
		nx=-1.0+(x*.125);
		ny=-1.0+(y*.125);
		nz=1.0;
		return;
	case 5:
		nx=1.0;
		ny=-1.0+(y*.125);
		nz=1.0-(x*.125);
		return;
	case 6:
		nx=-1.0f+(x*.125);
		ny=-1.0;
		nz=-1.0+(y*.125);
		return;
	default:
		MessageBox(NULL,"Guess what the coordinates of the snake are?","-12851",0);
	}
}
*/
