#include<GL/freeglut.h>
#include<iostream.h>
using namespace std;

const int inside = 0;
const int left = 1;
const int right = 2;
const int bottom = 4;
const int top = 8;

const double xmin = 20 , xmax = 200 , ymin = 20 , ymax = 200;

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    //draw axes
    glBegin(GL_LINES);
    glVertex2f(-300.0 , 0.0);
    glVertex2f(300.0 , 0.0);
    glVertex2f(0.0 , -300.0);
    glVertex2f(0.0 , 300.0);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    
    glBegin(GL_LINES_LOOP);
    glVertex2f(xmin , ymin);
    glVertex2f(xmin , ymax);
    glVertex2f(xmax , ymax);
    glVertex2f(xmax , ymin);
    glEnd();
    
    
}

int main(int argc , char **argv){
	cin>>a>>b>>c>>d;
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500 , 500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cohen sutherland");
	myInit();
	glutInitFunc(display);
	glutMainLoop();
	return 0;
}

