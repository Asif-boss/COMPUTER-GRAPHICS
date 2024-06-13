#include <GL/glut.h> // GLUT, include glu.h and gl.h
//#include <windows.h>
//#include <GL/gl.h> // for MS Windows

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
    glVertex2i(6, 0);
    glVertex2i(6, 16);
    glVertex2i(10,16);
    glVertex2i(10,0);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glVertex2i(0, 6);
    glVertex2i(22, 6);
    glVertex2i(22,10);
    glVertex2i(0,10);

    glEnd();
    glFlush ();

    glColor3f (0.0, 0.125, 0.357);

    glBegin(GL_QUADS);
    glVertex2i(7, 0);
    glVertex2i(7, 16);
    glVertex2i(9,16);
    glVertex2i(9,0);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glVertex2i(0, 7);
    glVertex2i(22, 7);
    glVertex2i(22,9);
    glVertex2i(0,9);

    glEnd();
    glFlush ();
}

void myInit (void){
    glClearColor(0.729, 0.047, 0.184, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 22.0, 0.0, 16.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1100, 700);
    glutInitWindowPosition (150, 20);
    glutCreateWindow ("Norway Flag");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
