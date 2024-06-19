#include <GL/glut.h> // GLUT, include glu.h and gl.h
//#include <windows.h>
//#include <GL/gl.h> // for MS Windows

void black_box(int x, int y){
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_QUADS);

    glVertex2i(x, y);
    glVertex2i(x, y+10);
    glVertex2i(x+10, y+10);
    glVertex2i(x+10, y);

    glEnd();
    glFlush();
}

void yellow_box(int x, int y){
    glColor3f (1.0, 1.0, 0.0);
    glBegin(GL_QUADS);

    glVertex2i(x, y);
    glVertex2i(x, y+10);
    glVertex2i(x+10, y+10);
    glVertex2i(x+10, y);

    glEnd();
    glFlush();
}

void full_yellow_box(int x, int y, int w, int h){
    glColor3f (1.0, 1.0, 0.0);
    glBegin(GL_QUADS);

    glVertex2i(x, y);
    glVertex2i(x, y+h*10);
    glVertex2i(x+w*10, y+h*10);
    glVertex2i(x+w*10, y);

    glEnd();
    glFlush();
}

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);

    glVertex2i(90, 50);
    glVertex2i(260, 50);
    glVertex2i(310, 100);
    glVertex2i(310, 160);
    glVertex2i(260, 220);
    glVertex2i(90, 220);
    glVertex2i(30, 160);
    glVertex2i(30, 100);
    
    black_box(20, 130);
    yellow_box(30, 130);

    black_box(170, 30);
    yellow_box(170, 40);

    black_box(320, 130);
    yellow_box(310, 130);

    black_box(170, 230);
    yellow_box(170, 220);
    yellow_box(170, 210);

    for (int i=0; i<3; i++){
        black_box(20, 140+i*10);
        yellow_box(30, 140+i*10);

        black_box(20, 120-i*10);
        yellow_box(30, 120-i*10);

        black_box(320, 140+i*10);
        yellow_box(310, 140+i*10);

        black_box(320, 120-i*10);
        yellow_box(310, 120-i*10);   
    }

    for (int i=0; i<7; i++){
        black_box(20+i*10, 160+i*10);
        yellow_box(30+i*10, 160+i*10);
        yellow_box(40+i*10, 160+i*10);

        black_box(20+i*10, 100-i*10);
        yellow_box(30+i*10, 100-i*10);
        yellow_box(40+i*10, 100-i*10);

        black_box(320-i*10, 160+i*10);
        yellow_box(310-i*10, 160+i*10);
        yellow_box(300-i*10, 160+i*10);

        black_box(320-i*10, 100-i*10);
        yellow_box(310-i*10, 100-i*10);
        yellow_box(300-i*10, 100-i*10);   
    }   

    for (int i=0; i<8; i++){
        black_box(90+i*10, 230);
        yellow_box(90+i*10, 220);
        yellow_box(90+i*10, 210);

        black_box(180+i*10, 230);
        yellow_box(180+i*10, 220);
        yellow_box(180+i*10, 210);

        black_box(90+i*10, 30);
        yellow_box(90+i*10, 40);
        yellow_box(90+i*10, 50);

        black_box(180+i*10, 30);
        yellow_box(180+i*10, 40); 
        yellow_box(180+i*10, 50);  
    }

    black_box(150, 210);
    black_box(190, 210);
    black_box(110, 50);
    black_box(230, 50);

    full_yellow_box(120, 170, 3, 4);
    full_yellow_box(120, 160, 2, 1);
    full_yellow_box(110, 170, 1, 3);

    full_yellow_box(200, 170, 3, 4);
    full_yellow_box(210, 160, 2, 1);
    full_yellow_box(230, 170, 1, 3);

    full_yellow_box(130, 60, 3, 2);
    yellow_box(120, 60); 
    yellow_box(140, 80); 

    full_yellow_box(190, 60, 3, 2);
    yellow_box(220, 60); 
    yellow_box(200, 80);

    glColor3f (1.0, 0.2, 0.8);
    glBegin(GL_LINES);

    for (int i=1; i<=34; i++){
        glVertex2i(i*10, 10);
        glVertex2i(i*10, 260);
    }
    for (int i=1; i<=26; i++){
        glVertex2i(10, i*10);
        glVertex2i(340, i*10);
    }
    glEnd();
    glFlush();
}

void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 350.0, 0.0, 270.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (700, 540);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-700)/2, (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow ("I am Batman");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}