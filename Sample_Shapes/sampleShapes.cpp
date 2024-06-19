#include <GL/glut.h> // GLUT, include glu.h and gl.h
//#include <windows.h>
//#include <GL/gl.h> // for MS Windows

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 1.0, 0.0);
    glLineWidth(1);

    glBegin(GL_LINES);
    glVertex2i(250, 0);
    glVertex2i(250, 500);
    glVertex2i(0,250);
    glVertex2i(500, 250);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glVertex2i(75, 75);
    glVertex2i(175, 75);
    glVertex2i(175, 175);
    glVertex2i(75, 175);

    glEnd();
    glFlush();

    glColor3f (0.91, 0.52, 0.08);

    glBegin(GL_TRIANGLES);
    glVertex2i(345, 75);
    glVertex2i(405, 75);
    glVertex2i(375, 175);

    glEnd();
    glFlush();

    glColor3f (1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);
    glVertex2i(75, 325);
    glVertex2i(175, 325);
    glVertex2i(125, 411.6);

    glEnd();
    glFlush();

    glColor3f (1.0, 1.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex2i(325, 375);
    glVertex2i(345, 325);
    glVertex2i(405, 325);
    glVertex2i(425, 375);
    glVertex2i(405, 425);
    glVertex2i(345, 425);

    glEnd();
    glFlush();
}

void myInit (void){
    glClearColor(0.5, 0.5, 0.5, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (400, 100);
    glutCreateWindow ("First Lab Task");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
