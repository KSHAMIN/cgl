#include <iostream>
#include <GL/glut.h>

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

void plot(float x, float y, color c = color(255, 255, 255))
{
	glBegin(GL_POINTS);
	glColor3f(c.r, c.g, c.b);
	glVertex2i(x, y);
	glEnd();
}


float x1,y1,x2,y2;


void ddaLine(float x1, float y1, float x2, float y2, color clr=color(255, 255, 255))
{
	float dx = x2-x1 , dy = y2-y1, xin, yin, step, x=x1, y=y1;
	if(abs(dy)>abs(dx))
		step = abs(dy);
	else
		step = abs(dx);
	xin = (dx/step);
	yin = (dy/step);
	for(int i=0;i<=step;i++,x+=xin,y+=yin)
		plot(x,y, clr);
}

void display(void)
{

	color white = color(255, 255, 255);
	color cyan = color(0, 255, 255);
	
	
	glPointSize(2.0);
	// Axes
	ddaLine(-150, 0, 150, 0, cyan);
	ddaLine(0, 150, 0, -150, cyan);
	
	
	glPointSize(2.0);
	// Outermost square
	ddaLine(x1, y2, x2, y2, white);
	ddaLine(x2, y2, x2, y1, white);
	ddaLine(x2, y1, x1, y1, white);
	ddaLine(x1, y1, x1, y2, white);
	
	// Middle turned square
	ddaLine(x1,(y1+y2)/2,(x1+x2)/2,y2, white);
	ddaLine((x1+x2)/2,y2,x2,(y1+y2)/2, white);
	ddaLine(x2,(y1+y2)/2,(x1+x2)/2,y1, white);
	ddaLine((x1+x2)/2,y1,x1,(y1+y2)/2, white);
	
	// Innermost square
	ddaLine((3*x1+x2)/4, (y1+3*y2)/4, (x1+3*x2)/4, (y1+3*y2)/4, white);
	ddaLine((x1+3*x2)/4, (y1+3*y2)/4, (x1+3*x2)/4, (3*y1+y2)/4, white);
	ddaLine((x1+3*x2)/4, (3*y1+y2)/4, (3*x1+x2)/4, (3*y1+y2)/4, white);
	ddaLine((3*x1+x2)/4, (3*y1+y2)/4, (3*x1+x2)/4, (y1+3*y2)/4, white);
	
	// Plot user-given points
	glPointSize(9.0);
	plot(x1, y1, color(256,0,0));
	plot(x2, y2, color(256,0,0));
	
	glFlush();
}

void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-150,150,-150,150);
}

int main(int argc, char* argv[])
{
	
	std::cout << "Enter Point1 (x1, y1) : ";
	std::cin >> x1 >> y1;
	std::cout << "Enter Point1 (x2, y2) : ";
	std::cin >> x2 >> y2;
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Assignment 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	
	glFlush();
	return 0;
}
