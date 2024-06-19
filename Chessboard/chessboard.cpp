#include <GL/glut.h> // GLUT, include glu.h and gl.h
//#include <windows.h>
//#include <GL/gl.h> // for MS Windows

void black_box(int x, int y){
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_QUADS);

    glVertex2i(x, y);
    glVertex2i(x, y+1);
    glVertex2i(x+1, y+1);
    glVertex2i(x+1, y);

    glEnd();
    glFlush();
}

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);

    for (int i=0; i<8; i++){
        int n;
        if (i%2==0) n = 0;
        else n = 1;

        for (int j=n; j<8; j+=2){
            black_box(i, j);
        }
    }

    glEnd();
    glFlush();
}

void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 8.0, 0.0, 8.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-600)/2, (glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
    glutCreateWindow ("Chess Board");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}