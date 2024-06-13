#include <GL/glut.h> // GLUT, include glu.h and gl.h
//#include <windows.h>
//#include <GL/gl.h> // for MS Windows

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(0, 200);
    glVertex2i(1200, 200);
    glVertex2i(1200, 0);

    glEnd();
    glFlush ();

    glColor3f (0.0, 0.478, 0.239);
    glBegin(GL_QUADS);
    glVertex2i(0, 600);
    glVertex2i(1200, 600);
    glVertex2i(1200, 400);
    glVertex2i(0, 400);

    glEnd();
    glFlush ();

    glColor3f (0.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(300, 200);
    glVertex2i(300, 400);
    glVertex2i(0, 600);

    glEnd();
    glFlush ();
}

void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0.0, 600.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 600);
    glutInitWindowPosition (150, 20);
    glutCreateWindow ("Kuwait Flag");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
