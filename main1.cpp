#include<bits/stdc++.h>
#include<GL/freeglut.h>

using namespace std;

void drawAxes(){
	glColor3f(0,0,0);
	int w=500;
	int h=500; 
	glBegin(GL_LINES);
	glVertex2f(-w/2,0);
	glVertex2f(w/2,0);
	glVertex2f(0,-h/2);
	glVertex2f(0,h/2); 
	glEnd(); 
}
void drawrectangle(){
	glColor3f(0,0,0);
	int w=500;
	int h=500; 
	glBegin(GL_LINE_LOOP);
	glVertex2f(50,50);
	glVertex2f(50,-50);
	glVertex2f(-50,-50);
	glVertex2f(-50,50); 
	glEnd(); 
}
void translate(){
	float tx=10;
	float ty=20;
	float a=50;
	float b=50;
	
	// float N=10000; 
	// glBegin(GL_POINTS);
	// for(int i=0;i<N;i++){ 
	// 	glVertex2f(a*cos(angle*i/N),b*sin(angle*i/N));  
	// }
	// glEnd(); 
    float thetha=2*3.14;
    glBegin(GL_POINTS);
     float angle=3.14*2; 
    for(int i=0;i<10000;i++){
    	glVertex2f(a*cos(thetha*i/10000)*cos(angle)-a*sin(thetha*i/10000)*sin(angle),a*sin(thetha*i/10000)*sin(angle)+a*sin(thetha*i/10000)*cos(angle));
       // glVertex2f(a*cos(thetha*i/10000)+tx,a*sin(thetha*i/10000)+ty);
    }
    glEnd();
	glColor3f(1,0,0); 
	glBegin(GL_LINE_LOOP);
	glVertex2f(50+tx,50+ty);
	glVertex2f(50+tx,-50+ty);
	glVertex2f(-50+tx,-50+ty);
	glVertex2f(-50+tx,50+ty); 
	glEnd(); 
}
void drawEllipse(){
	
	cout<<"ENTER A AND B : ";
	float a=50;
	float b=50;
	
	// float N=10000; 
	// glBegin(GL_POINTS);
	// for(int i=0;i<N;i++){ 
	// 	glVertex2f(a*cos(angle*i/N),b*sin(angle*i/N));  
	// }
	// glEnd(); 
    float thetha=2*3.14,angle=3.14/3;
    
    glBegin(GL_POINTS);
    for(int i=0;i<10000;i++){
        glVertex2f(a*cos(thetha*i/10000),a*sin(thetha*i/10000));
    }
    glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	drawAxes();
	drawrectangle();
	drawEllipse();
	translate();
	glFlush();	
}

void myinit(){
	glClearColor(1,1,1,1);
	gluOrtho2D(-250,250,-250,250);	
	glMatrixMode(GL_PROJECTION);
	glPointSize(2);
	glLineWidth(2);
}


int main(int argc,char ** argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutCreateWindow("Simple Ellipse");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
