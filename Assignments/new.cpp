#include<iostream>
#include<math.h>
#include<GL/glut.h>

void myInit(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-420,420,-420,420);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(760,760);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Practise GL");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	glFlush();
	return 0;
}
