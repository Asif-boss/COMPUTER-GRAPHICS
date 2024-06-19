
//#include <windows.h>
//#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
//#include <stdio.h>

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2i(255, 255); // Important point...

	glVertex2i(0, 315);
    glVertex2i(500, 315);
    glVertex2i(100, 0);
    glVertex2i(250, 500);
    glVertex2i(400, 0);
    glVertex2i(0, 315);

    glEnd();
    glFlush();

}

void myInit (void){
    glClearColor(0.5, 0.5, 0.5, 0.5);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-500)/2, (glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Second Star");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
