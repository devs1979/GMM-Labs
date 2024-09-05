//#include <GL/freeglut.h>
//#include <cmath>
//
//void drawLine(int x1, int y1, int x2, int y2) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0); 
//
//    float dx = x2 - x1;
//    float dy = y2 - y1;
//
//    
//    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//
//   
//    float xIncrement = dx / steps;
//    float yIncrement = dy / steps;
//
//   
//    float x = x1, y = y1;
//    glBegin(GL_POINTS);
//    glVertex2i(x, y);
//
//    for (int k = 0; k < steps; k++) {
//        x += xIncrement;
//        y += yIncrement;
//        glVertex2i(round(x), round(y));
//    }
//
//    glEnd();
//    glFlush();
//}
//
//void display() {
//    glClearColor(0.0, 0.0, 0.0, 1.0); 
//    glClear(GL_COLOR_BUFFER_BIT);
//
//   // m > 0
//    drawLine(100, 100, 300, 200);
//
//    //  m = 0
//    drawLine(100, 100, 300, 100);
//
//    //  m < 0
//    drawLine(100, 200, 300, 100);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(400, 400);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("DDA Line Drawing Algorithm");
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, 400, 0, 400);
//
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}








#include <gl/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}

void myDisplay() {
	draw_line(x1, x2, y1, y2);
	glFlush();
}

int main(int argc, char **argv) {

	printf( "Enter x1: ");
	scanf("%d" , &x1);
    printf( "Enter y1: ");
	scanf("%d" , &y1);
	printf( "Enter x2: ");
	scanf("%d" , &x2);
    printf( "Enter y2: ");
	scanf("%d" , &y2);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}


//
//
//
//
//
//
//
//
//#include <iostream>
//#include <GL/glut.h>
//#include <bits/stdc++.h>
//
//struct Point {
//    int x, y;
//};
//
//Point p1, p2;
//
//void drawLineDDA(Point p1, Point p2) {
//    int dx = p2.x - p1.x;
//    int dy = p2.y - p1.y;
//    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//    float xIncrement = (float)dx / (float)steps;
//    float yIncrement = (float)dy / (float)steps;
//    
//    float x = p1.x;
//    float y = p1.y;
//    
//    glBegin(GL_POINTS);
//    for (int i = 0; i <= steps; i++) {
//        glVertex2i(round(x), round(y));
//        x += xIncrement;
//        y += yIncrement;
//    }
//    glEnd();
//    glFlush();
//}
//
//void drawAxes() {
//    glColor3f(1.0, 1.0, 1.0); // Set color to white
//    
//    // Draw X-axis
//    glBegin(GL_LINES);
//    glVertex2i(0, 250);
//    glVertex2i(500, 250);
//    glEnd();
//    
//    // Draw Y-axis
//    glBegin(GL_LINES);
//    glVertex2i(250, 0);
//    glVertex2i(250, 500);
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    
//    drawAxes();
//    
//    glColor3f(1.0, 1.0, 1.0); // Set color to white
//    drawLineDDA(p1, p2);
//}
//
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
//    gluOrtho2D(0, 500, 0, 500); // Set the coordinate system
//}
//
//int main(int argc, char** argv) {
//    std::cout << "Enter coordinates of point 1 (x y): ";
//    std::cin >> p1.x >> p1.y;
//    std::cout << "Enter coordinates of point 2 (x y): ";
//    std::cin >> p2.x >> p2.y;
//    
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("DDA Line Drawing Algorithm");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    
//    return 0;
//}
