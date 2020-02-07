// C program to demonstrate 
// drawing a circle using 
// OpenGL 

#include<iostream>
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	// making picture color green (in RGB mode), as middle argument is 1.0 
	glColor3f(1.0, 0.1, 0.6); 
	
	// breadth of picture boundary is 1 pixel 
	glPointSize(.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction 
	gluOrtho2D(-420, 420, -420, 420); 
} 

float r;

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POINTS); 
	float x, y, i; 
	
	// iterate y up to 2*pi, i.e., 360 degree 
	// with small increment in angle as 
	// glVertex2i just draws a point on specified co-ordinate 
	for ( i = -2 * pi; i < (2 * pi); i += 0.0001) 
	{ 
		// let 200 is radius of circle and as, 
		// circle is defined as x=r*cos(i) and y=r*sin(i) 
		x = r * i;
		y = r * (cos(i) * sin(i) + sin(i) * tan(i));
		
		glVertex2i(x, y); 
	} 
	glEnd(); 
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	std::cout << "Enter Radius : ";
	std::cin >> r;
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(768, 768); 
	glutInitWindowPosition(0, 0); 
	
	// Giving name to window 
	glutCreateWindow("Circle Drawing"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

