#include <iostream>
#include <GL/glut.h>
#include<math.h> 
#define pi 3.142857 

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

void circle(float cx, float cy, float r, color c = color(1, 1, 1))
{
	glBegin(GL_POINTS);
	float x, y, i; 
	for ( i = -2 * pi; i < (2 * pi); i += 0.0001) 
	{
		x = r * cos(i) + cx;
		y = r * sin(i) + cy;
		
		glVertex2i(x, y); 
	}
	glEnd();
	glFlush();
}

void display(void)
{ 
	color white = color(1,1,1);
	color cyan = color(0, 1, 0);
	
	// Wheels
	circle(-250, -105, 70);
	circle(210, -105, 70);
	circle(-250,-105,8);
	circle(-250,-105,12);
	circle(210, -105,8);
	circle(210, -105,12);
	
	
	//wheelLine
	ddaLine(-400, -105, -340, -105);
	ddaLine(300, -105, 400, -105);
	
	//wheel1UpperHexagon
	ddaLine(-340, -105, -295, -27.06);
	ddaLine(-295, -27.06, -205, -27.06);
	ddaLine(-205, -27.06, -160, -105);
	//wheel2UpperHexagon
	ddaLine(-340+460, -105, -295+460, -27.06);
	ddaLine(-295+460, -27.06, -205+460, -27.06);
	ddaLine(-205+460, -27.06, -160+460, -105);
	
	//BottomLine
	ddaLine(-160, -105, -340+460, -105);
	
	//LeftVertical
	ddaLine(-400, -105, -400, 5);
	//RightVertical
	ddaLine(400, -105, 400, 25+800*tan(0.0436332));
	
	
	//MiddleSlopingLine
	ddaLine(-400, 5, 400, 25+800*tan(0.0436332));
	
	//LeftSlopingLine
	ddaLine(-400, 5, -50, 160);
	
	//RightSlopingLine
	ddaLine(-50, 160, 400, 25+800*tan(0.0436332));
	
	//3middleVerticalLines
	ddaLine(120, -105, 120, 39+500*tan(0.0436332));
	ddaLine(-20, -105, -20, 34+370*tan(0.0436332));
	ddaLine(-160, -105, -160, 29+240*tan(0.0436332));
	
	//WindowLeftSlope
	ddaLine(-290, 25+150*tan(0.0436332), -50, 150);
	
	//WindowBottomSlope
	ddaLine(-290, 25+150*tan(0.0436332), 120,  40+500*tan(0.0436332));
	
	//WindowRightSlope
	ddaLine(-50, 150, 120, 104);
	
	//WindowRightvertical
	ddaLine(120,  40+500*tan(0.0436332), 120, 104);
	
	
	glPointSize(1.0);
	// Axes
	//ddaLine(-420, 0, 420, 0, cyan);
	//ddaLine(0, 420, 0, -420, cyan);
	
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
