#include <GL/freeglut.h>
#include <cmath>

void drawLine(int x1, int y1, int x2, int y2) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); 

    float dx = x2 - x1;
    float dy = y2 - y1;

    
    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

   
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

   
    float x = x1, y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);

    for (int k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        glVertex2i(round(x), round(y));
    }

    glEnd();
    glFlush();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glClear(GL_COLOR_BUFFER_BIT);

   // m > 0
    drawLine(100, 100, 300, 200);

    //  m = 0
    drawLine(100, 100, 300, 100);

    //  m < 0
    drawLine(100, 200, 300, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

