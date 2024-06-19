#include <GL/glut.h> // GLUT, include glu.h and gl.h


void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

    glBegin(GL_POLYGON); // 114 x 112
    glVertex2i(40, 74);
    glVertex2i(57, 112);
    glVertex2i(74, 74);
    glVertex2i(114, 71);
    glVertex2i(84, 45);
    glVertex2i(98, 0);
    glVertex2i(57, 26);
    glVertex2i(16, 0);
    glVertex2i(28, 45);
    glVertex2i(0,71);

    glEnd();
    glFlush();
}

void myInit(void){
    glClearColor(0.17, 0.19, 0.24, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 114.0, 0.0, 112.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-500)/2, (glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("First Star");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
