#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int n;

void init()
{
   glClearColor(0.0,0.0,0.0,0.0);
   glMatrixMode(GL_PROJECTION);
   //glLoadIdentity();
   gluOrtho2D(0,500,0,500);
}

int round1(double number)
{
   return (number>=0) ? (int)(number+0.5):(int)(number-0.5);
}

void setPixel(GLint x,GLint y)
{
   //glColor3f(0,1,1);
   glBegin(GL_POINTS);
   glVertex2f(x,y);
   glEnd();
}

/*void LineWithDDA(int x0,int y0,int x1,int y1)
{
   int dy=y1-y0;
   int dx=x1-x0;
   int steps,i;
   float xinc,yinc,x=x0,y=y0;
   if(abs(dx)>abs(dy))
   {
     steps=abs(dx);
   }
   else
   {
     steps=abs(dy);
   }
   xinc=(float)dx/(float)steps;
   yinc=(float)dy/(float)steps;
   setPixel(round1(x),round1(y));
   for(i=0;i<steps;i++)
   {
     x+=xinc;
     y+=yinc;
     setPixel(round1(x),round1(y));
   }
   glutSwapBuffers();
}*/

void set(int x,int y)
	{
		glBegin(GL_POINTS);
	  	glVertex2i(x,y);
	  	glEnd();
	
	}
	
void drawCircle(int xc, int yc, int x, int y) 
{ 
    set(xc+x, yc+y); 
    set(xc-x, yc+y); 
    set(xc+x, yc-y); 
 	set(xc-x, yc-y); 
    set(xc+y, yc+x); 
    set(xc-y, yc+x); 
    set(xc+y, yc-x); 
    set(xc-y, yc-x); 
} 

void circleBres(int xc, int yc, int r) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y);
     glFlush(); 
    while (y >= x) 
    { 
        
          
        x++; 
  
      
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(xc, yc, x, y); 
          glFlush();
    } 
}

int k=1;
int X[10],Y[10];

void mouseClick(int button, int state, int x, int y)
{
   switch(button)
   {
      case GLUT_LEFT_BUTTON: printf(" LEFT ");
      if (state == GLUT_DOWN)
      {   
            printf("DOWN\n");
            printf("(%d, %d)\n", x, y);
            X[k]=x;
            Y[k]=500-y; //i did this to match the glut coordinate to window coordinate :)
            //LineWithDDA(0,0,x,y);
            if(k%2==0)
            	r=sqrt(((X[k-1]-X[k])*(X[k-1]-X[k])) + ((Y[k-1]-Y[k])*(Y[k-1]-Y[k])));
            	circleBres(X[k-1],Y[k-1], r);
              
            
            else if(k>1 && k%2!=0)
            r=sqrt(((X[k-1]-X[k])*(X[k-1]-X[k])) + ((Y[k-1]-Y[k])*(Y[k-1]-Y[k])));
            	circleBres(X[k-1],Y[k-1], r);
              //LineWithDDA(X[k-1],Y[k-1],X[k],Y[k-1]);
      
      
            glutSwapBuffers();
            k++; 
      }
      else if (state == GLUT_UP)
      {
             printf("UP\n");
      }
      
      
     break;
     case GLUT_RIGHT_BUTTON: printf(" RIGHT \n Clearing Screen");
     // Repaint/Clear the screen as same code of function Display()
		  glClearColor(0,0,0,0);
		  glClear(GL_COLOR_BUFFER_BIT);
		  //LineWithDDA(0,0,50,50);
		  glFlush();
    // Reset Value of K to 1
       k=1;
     
       
     break;
     
     default:
     break;
   }
   fflush(stdout);                         
}

void Display()
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  //LineWithDDA(0,0,50,50);
  glFlush();
}

int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50,50);
  glutInitWindowSize(500,500);
  glutCreateWindow("polygon...");
  init();
  glutDisplayFunc(Display);
  glutMouseFunc(mouseClick);
  glutMainLoop();
  return 0;
}
