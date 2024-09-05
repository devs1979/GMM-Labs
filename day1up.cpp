#include<stdio.h>
#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);  
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POINTS);
	glVertex2f(12.0, 210.0);
	glVertex2f(104.0, 130.0);
	glVertex2f(150.0, 90.0);
	glVertex2f(243.0, 20.0);
	glEnd();
	glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}
