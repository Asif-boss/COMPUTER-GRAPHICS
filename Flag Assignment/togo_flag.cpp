#include <GL/glut.h> // GLUT, include glu.h and gl.h
//#include <windows.h>
//#include <GL/gl.h> // for MS Windows

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.808, 0.0);

    glBegin(GL_QUADS);
    glVertex2i(0, 120);
    glVertex2i(0, 240);
    glVertex2i(971,240);
    glVertex2i(971,120);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glVertex2i(0, 360);
    glVertex2i(0, 480);
    glVertex2i(971,480);
    glVertex2i(971,360);

    glEnd();
    glFlush ();

    glColor3f (0.824, 0.063, 0.203);

    glBegin(GL_QUADS);
    glVertex2i(0, 240);
    glVertex2i(0, 600);
    glVertex2i(360,600);
    glVertex2i(360,240);

    glEnd();
    glFlush ();

    glColor3f (1.0, 1.0, 1.0);

    glBegin(GL_POLYGON); 
    glVertex2i(148, 455);
    glVertex2i(180, 540);
    glVertex2i(212, 455);
    glVertex2i(287, 455);
    glVertex2i(232, 400);
    glVertex2i(256, 308);
    glVertex2i(180, 360);
    glVertex2i(104, 308);
    glVertex2i(126, 400);
    glVertex2i(73, 455);
    
    glEnd();
    glFlush();
}

void myInit (void){
    glClearColor(0.0, 0.416, 0.29, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 971.0, 0.0, 600.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (971, 600);
    glutInitWindowPosition (150, 20);
    glutCreateWindow ("Togo Flag");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
