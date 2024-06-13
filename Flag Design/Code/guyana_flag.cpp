#include <GL/glut.h> // GLUT, include glu.h and gl.h
//#include <windows.h>
//#include <GL/gl.h> // for MS Windows

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

    glBegin(GL_TRIANGLES);
    glVertex2i(0, 0);
    glVertex2i(1000, 300);
    glVertex2i(0, 600);

    glEnd();
    glFlush ();

    glColor3f (1.0, 0.82, 0.0);

    glBegin(GL_TRIANGLES);
    glVertex2i(0, 20);
    glVertex2i(933.33, 300);
    glVertex2i(0, 580);

    glEnd();
    glFlush ();

    glColor3f (0.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);
    glVertex2i(0, 0);
    glVertex2i(500, 300);
    glVertex2i(0, 600);

    glEnd();
    glFlush ();

    glColor3f (0.937, 0.2, 0.251);

    glBegin(GL_TRIANGLES);
    glVertex2i(0, 30);
    glVertex2i(450, 300);
    glVertex2i(0, 570);

    glEnd();
    glFlush ();
}

void myInit (void){
    glClearColor(0.0, 0.592, 0.224, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 600.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 600);
    glutInitWindowPosition (150, 20);
    glutCreateWindow ("Guyana Flag");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
