#include <GL/glut.h> // GLUT, include glu.h and gl.h
//#include <windows.h>
//#include <GL/gl.h> // for MS Windows

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    
    glColor3f (1.0, 0.722, 0.11);

    glBegin(GL_TRIANGLES);
    glVertex2i(0, 60);
    glVertex2i(0, 540);
    glVertex2i(360, 300);

    glEnd();
    glFlush ();
    
    glColor3f (0.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);
    glVertex2i(0, 100);
    glVertex2i(0, 500);
    glVertex2i(300, 300);

    glEnd();
    glFlush ();
    
    glColor3f (1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
    glVertex2i(90, 0);
    glVertex2i(900, 0);
    glVertex2i(900,240);
    glVertex2i(450,240);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glVertex2i(90, 600);
    glVertex2i(900, 600);
    glVertex2i(900,360);
    glVertex2i(450,360);

    glEnd();
    glFlush ();

    glColor3f (0.0, 0.078,0.537);

    glBegin(GL_QUADS);
    glVertex2i(150, 0);
    glVertex2i(900, 0);
    glVertex2i(900,200);
    glVertex2i(460,200);

    glEnd();
    glFlush ();

    glColor3f (0.878, 0.235, 0.192);
    glBegin(GL_QUADS);
    glVertex2i(150, 600);
    glVertex2i(900, 600);
    glVertex2i(900,400);
    glVertex2i(460,400);

    glEnd();
    glFlush ();
}

void myInit (void){
    glClearColor(0.0, 0.467, 0.286, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 900.0, 0.0, 600.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (900, 600);
    glutInitWindowPosition (150, 20);
    glutCreateWindow ("South Africa Flag");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
