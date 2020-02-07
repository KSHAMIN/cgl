#include <iostream>
#include <GL/glut.h>
#include<math.h> 
#define pi 3.142857 
#define e 2.71828

class color{
	public:
	int r;
	int g;
	int b;
	color(int r, int g, int b){
		this->r = r;
		this->g = g;
		this->b = b;
	}
};

void plot(float x, float y, color c = color(1, 1, 1))
{
	glBegin(GL_POINTS);
	glColor3f(c.r, c.g, c.b);
	glVertex2i(x, y);
	glEnd();
}



void ddaLine(float x1, float y1, float x2, float y2, color clr1=color(1, 1, 1))
{
	float dx = x2-x1 , dy = y2-y1, xin, yin, step, x=x1, y=y1;
	if(abs(dy)>abs(dx))
		step = abs(dy);
	else
		step = abs(dx);
	xin = (dx/step);
	yin = (dy/step);
	for(int i=0;i<=step;i++,x+=xin,y+=yin)
		plot(x,y, clr1);
}

void circle(float cx, float cy, float r, color c = color(0, 0, 1))
{
	glBegin(GL_POINTS);
	float x, y, i; 
	for ( i = -pi; i < (15.5*pi); i += 0.0001) 
	{
		r = pow(e,0.12*i);
		y = r * cos(i) + cx;
		x = r * sin(i) + cy;
		plot(x,y,c);                          
		//glVertex2i(x, y); 
	}
	glEnd();
	glFlush();
}

void display(void)
{ 
	color white = color(1,1,1);
	color cyan = color(0, 1, 0);

	glPointSize(1.0);
	// Axes
	ddaLine(-420, 0, 420, 0, cyan);
	ddaLine(0, 420, 0, -420, cyan);
	
	circle(0,0,100);
	
	glPointSize(1.0);
	
	glFlush();
}

void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-420,420,-420,420);
}

int main(int argc, char* argv[])
{

	
	
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (720, 720);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Assignment 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	
	glFlush();
	return 0;
}
