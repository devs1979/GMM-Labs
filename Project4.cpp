

//
#include <GL/freeglut.h>
#include <cmath>
#include <vector>
//
//// Define constants
const int WIDTH = 800;
const int HEIGHT = 600;


float zBuffer[WIDTH][HEIGHT];


void initZBuffer() {
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            zBuffer[i][j] = 1.0f;
        }
    }
}

//// Draw cube function
void drawCube() {
    glutSolidCube(1);
}
//
//// Draw sphere function
void drawSphere() {
    glutSolidSphere(0.5, 20, 20);
}

//// Draw pyramid function
void drawPyramid() {
    glBegin(GL_TRIANGLES);
    // Front face
    glVertex3f(0, 1, 0);
    glVertex3f(-0.5, 0, 0.5);
    glVertex3f(0.5, 0, 0.5);
    // Right face
    glVertex3f(0, 1, 0);
    glVertex3f(0.5, 0, 0.5);
    glVertex3f(0.5, 0, -0.5);
    // Back face
    glVertex3f(0, 1, 0);
    glVertex3f(0.5, 0, -0.5);
    glVertex3f(-0.5, 0, -0.5);
    // Left face
    glVertex3f(0, 1, 0);
    glVertex3f(-0.5, 0, -0.5);
    glVertex3f(-0.5, 0, 0.5);
    // Bottom face
    glVertex3f(-0.5, 0, 0.5);
    glVertex3f(0.5, 0, 0.5);
    glVertex3f(0.5, 0, -0.5);
    glVertex3f(-0.5, 0, -0.5);
    glVertex3f(-0.5, 0, 0.5);
    glEnd();
}

//// Initialize OpenGL
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    initZBuffer(); // Initialize Z-buffer
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   gluPerspective(90.0, (double)WIDTH / (double)HEIGHT, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, -5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    // Draw primitives
    glColor3f(1.0f, 1.0f, 1.0f); // White
    
    // Cube
    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    drawCube();
    glPopMatrix();
    
    // Sphere
   glPushMatrix();
    glTranslatef(1.5, 0.0, 0.0);
    glColor3f(1.0f, 0.0f, 3.0f); // Red
    drawSphere();
    glPopMatrix();
    
    // Pyramid
    glPushMatrix();
    glTranslatef(0.0, 0.0, 2.0);
    drawPyramid();
    glPopMatrix();

    glutSwapBuffers();
}

//// Reshape function
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

//// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("3D Scene with Painters algorithnm");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}








