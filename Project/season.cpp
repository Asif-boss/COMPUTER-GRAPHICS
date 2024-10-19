//#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

# define pi 3.1416

float _angle1 = 30.0f;
float cloud_move = 0.3f;
float windmill_move = 0.0f;
float boat_move = 0.6f;
float rain_cloud_move = 3.5f;
float rain_move = 2.50f;
float snow_move = 3.0f;
bool summer = true;
bool paused = false;
bool day = true;
bool rain_start = false;
bool ice_start = false;
bool snowfall_start = false;
char key;

void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void drawScene();
void scenario();
void sky();
void star();
void triangle(float a, float b, float c, float d, float e, float f);
void polygon(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j);
void mountain();
void circle(float x1, float y1, float r);
void cloud();
void cloud_update(int value);
void rain_cloud_update(int value);
void rain_update(int value);
void sun_moon();
void ground();
void river();
void tree();
void treeLeaf();
void windmill();
void windmill_update(int value);
void grass();
void treeFlower(float x, float y);
void grassFlower(float x, float y, char color);
void flower();
void house();
void boat();
void boat_update(int value);
void rainCloud();
void rain();
void rainDay();
void snowball();
void snowfall();
void snow_update(int value);

int main(int argc, char** argv) {
    cout << "                         OpenGl Project: Season Change\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << "                           MD. ASIF HOSSAIN 22-48965-3\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << "                           Mouse and Keyboard Sortcut\n";
    cout << "--------------------------------------------------------------------------------\n";

    cout << "Press 's' or 'S' to make it summer. \n\n";
    cout << "Press 'r' or 'R' to start or stop rain. \n\n";
    cout << "Press 'w' or 'W' to make it winter. \n\n";
    cout << "Press 'i' or 'I' to start or stop snowfall. \n\n";
    cout << "Press 'd' or 'D' to make it day. \n\n";
    cout << "Press 'n' or 'N' to make it night. \n\n";

	cout << "Press LEFT MOUSE BUTTON to display menu. \n\n";
	cout << "Press RIGHT MOUSE BUTTON to quit the program. \n\n\n";
	cout << "Select season[S/W]: ";
	cin >> key;

    bool check = true;

    while (check){
        switch (key){
            case 's':
            case 'S':
                summer = true;
                snowfall_start = false;
                ice_start = false;
                check = false;
                break;

            case 'w':
            case 'W':
                summer = false;
                rain_start = false;
                check = false;
                break;

            default:   
                cout << "Give currect input[S/W]: ";
                cin >> key;
        }
    }
    
    

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 700);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-800)/2, (glutGet(GLUT_SCREEN_HEIGHT)-700)/2);
	glutCreateWindow("BD Season");

	glutDisplayFunc(drawScene); //Set handler functions

    //glutSpecialFunc(specialKeys); //Special Key Handler
	glutKeyboardFunc(keyboard);   //Basic keyboard key handler
	glutMouseFunc(mouse);         //Mouse Handler
	//glutReshapeFunc(handleResize);

    glutTimerFunc(80, cloud_update, 0); //Add a timer for cloud
    glutTimerFunc(50, windmill_update, 0); //Add a timer for windmill
    glutTimerFunc(70, boat_update, 0); //Add a timer for boat
    glutTimerFunc(100, rain_cloud_update, 0);
    glutTimerFunc(100, rain_update, 0);
    glutTimerFunc(100, snow_update, 0);

	glutMainLoop();
	return 0;
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) exit(0);
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // Pause/resume
        paused = !paused;         // Toggle state
   }
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 'd':
        case 'D':       
            day = true;
            break;

        case 'n':
        case 'N':
            day = false;
            break;

        case 'r':
        case 'R':
            if (summer == true) rain_start = !rain_start;
            break;

        case 's':
        case 'S':
            summer = true;
            snowfall_start = false;
            ice_start = false;
            break;

        case 'w':
        case 'W':
            summer = false;
            rain_start = false;
            break;


        case 'i':
        case 'I':
            if (!summer){
                snowfall_start = !snowfall_start;
                ice_start = true;
            } 
            break;
    }
    glutPostRedisplay();
}

void drawScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    scenario();

    glutSwapBuffers();
}

void scenario(){
    sky();
    if (!rain_start && !snowfall_start) sun_moon();
    if (!day && !rain_start && !snowfall_start) star();
    if (day == true && !rain_start && !snowfall_start) cloud();
    mountain();
    ground();
    river();
    if (snowfall_start == false) boat();
    tree();
    windmill();
    grass();
    if (summer == true) flower();
    house();

    if (rain_start == true) rainDay();
    if (snowfall_start == true) snowfall();
}

void quad(float a, float b, float c, float d, float e, float f, float g, float h){
    glBegin(GL_QUADS);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glEnd();
}

void triangle(float a, float b, float c, float d, float e, float f){
    glBegin(GL_TRIANGLES);

    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);

    glEnd();
}

void circle(float x1, float y1, float r){
    glBegin(GL_POLYGON);
	for(int i=0;i<180;i++){
		float A=(i*2*pi)/180 ;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+x1, y+y1);
	}
    glEnd();
}

void polygon(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j){
    glBegin(GL_POLYGON);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glVertex2f(i, j);
    glEnd();
}

void sky(){
    if (summer == true && day == true && rain_start == true) glColor3ub(171, 183, 191);
    else if (!summer && day == true) glColor3ub(202, 237, 236);
    else if (day == true) glColor3f(0.25, 0.95, 1.0);
    else glColor3f(0.0, 0.0, 0.0);
    quad(-1,0, 1,0, 1,1, -1,1);
}

void sun_moon(){
    if (day == true) glColor3f(0.97, 0.91, 0.39);
    else glColor3f(1.0, 1.0, 1.0);
    circle(0.0, .75, .09);
}

void star(){
    glColor3f(1.0, 1.0, 1.0);
    // star1       
    triangle(0.15, 0.87, 0.135, 0.84, 0.165, 0.84);
    triangle(0.15, 0.83, 0.135, 0.86, 0.165, 0.86);
    // star2
    triangle(0.95, 0.84, 0.935, 0.81, 0.965, 0.81);
    triangle(0.95, 0.8, 0.935, 0.83, 0.965, 0.83);
    // star3
    triangle(0.75, 0.55, 0.735, 0.52, 0.765, 0.52);
    triangle(0.75, 0.51, 0.735, 0.54, 0.765, 0.54);
    // star4
    triangle(-0.25, 0.7, -0.235, 0.67, -0.265, 0.67);
    triangle(-0.25, 0.66, -0.235, 0.69, -0.265, 0.69);
    //star 5
    triangle(0.5, 0.78, 0.485, 0.75, 0.515, 0.75);
    triangle(0.5, 0.74, 0.485, 0.77, 0.515, 0.77);
    //star 6
    triangle(-0.8, 0.5, -0.785, 0.47, -0.815, 0.47);
    triangle(-0.8, 0.46, -0.785, 0.49, -0.815, 0.49);
    //star 7
    triangle(-0.7, 0.9, -0.685, 0.87, -0.715, 0.87);
    triangle(-0.7, 0.86, -0.685, 0.89, -0.715, 0.89);
}

void mountain(){
    // Right small mountain
    if (day == true) glColor3f(0.24,0.47,0.53);//font
    else glColor3f(0.105, 0.325, 0.38);
    triangle(.55, 0, 1.1, 0, .8, .22);

    if (day == true) glColor3f(0.11, 0.31, 0.36);
    else glColor3f(0, 0, 0);
    triangle(.55, 0, .65, 0, .8, .22);

    // main mountain
    if (day == true) glColor3f(0.29, 0.6, 0.68);
    else glColor3f(0, 0.44, 0.55);
    quad(-.35, 0, .75, 0, .25, .45, .1, .43);

    if (day == true) glColor3f(1.0, 1.0, 1.0);
    else glColor3f(0.83, 0.85, 0.88);

    glBegin(GL_POLYGON);

    glVertex2f(.25, .45); // right up
    glVertex2f(.1, .43); // left up
    glVertex2f(-.039, .3); // left down
    glVertex2f(.08, .35);; // left up 1
    glVertex2f(.06, .25);
    glVertex2f(.17, .355);// left up 2
    glVertex2f(.25, .27);
    glVertex2f(.25, .38); // left up 3
    glVertex2f(.42, .3); // rightt down

    glEnd();

    // small mountains from left side
    if (day == true) glColor3f(0.24,0.47,0.53);//font
    else glColor3f(0.105, 0.325, 0.38);

    triangle(-1.1, 0, -.75, 0, -.9, .12);
    triangle(-.8, 0, -.3, 0, -.55, .15);
    triangle(-.45, 0, .1, 0, -.2, .23);
    triangle(-.1, 0, .3, 0, .1, .12);

    // small mountains' shadow from left side
    if (day == true) glColor3f(0.11, 0.31, 0.36);
    else glColor3f(0, 0, 0);

    triangle(-1.1, 0, -.98, 0, -.9, .12);
    triangle(-.8, 0, -.7, 0, -.55, .15);
    triangle(-.45, 0, -.35, 0, -.2, .23);
    triangle(-.1, 0, 0, 0, .1, .12);

    if (ice_start == true){
        if (day == true) glColor3f(1.0, 1.0, 1.0);
        else glColor3f(0.83, 0.85, 0.88);

        glBegin(GL_POLYGON);
        glVertex2f(.25, .45);
        glVertex2f(.1, .43);
        glVertex2f(-.142, .2);
        glVertex2f(.04, .28);
        glVertex2f(.07, .18);
        glVertex2f(.17, .28);
        glVertex2f(.28, .15);
        glVertex2f(.35, .26);
        glVertex2f(.585, .15);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-.9, .12);
        glVertex2f(-1.0, .06);
        glVertex2f(-.95, .05);
        glVertex2f(-.89, .075);
        glVertex2f(-.82, .06);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-.55, .15);
        glVertex2f(-.67, .08);
        glVertex2f(-.65, .05);
        glVertex2f(-.55, .08);
        glVertex2f(-.4, .06);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-.2, .23);
        glVertex2f(-.356, .09);
        glVertex2f(-.3, .07);
        glVertex2f(-.2, .1);
        glVertex2f(-.1, .07);
        glVertex2f(-.03, .1);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(.8, .22);
        glVertex2f(.68, .12);
        glVertex2f(.71, .085);
        glVertex2f(.78, .11);
        glVertex2f(.85, .08);
        glVertex2f(.9, .11);
        glVertex2f(.98, .09);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(.1, .12);
        glVertex2f(.0, .06);
        glVertex2f(.05, .05);
        glVertex2f(.22, .05);
        glEnd();
    }
}

void cloud_update(int value){
    if( !paused ){
        cloud_move -= .01;
        if(cloud_move+3 < 1.0){
            cloud_move = 1.6; //when object goes out of display while incrementing its position, set the coordinate to the opposite position so that it feels like the object is continuously moving
        }
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(80, cloud_update, 0); //Notify GLUT to call update again in 25 milliseconds
}

void cloud(){
    glPushMatrix(); //Save the current state of transformations //Move to the center of the triangle
    glTranslatef(cloud_move, 0.0f, 0.0f); //moving along x-axis

    glColor3f(1.0, 1.0, 1.0);

    circle(.725, .68, .05);
    circle(.8, .7, .08);
    circle(.89, .682, .06);
    circle(.95, .68, .04);

    // CLOUD LEFT
    circle(-.425, .585, .04);
    circle(-.5, .6, .07);
    circle(-.59, .592, .05);
    circle(-.64, .58, .03);

    glPopMatrix();
}

void ground(){
    if (summer == true){
        if (day == true) glColor3f(0.43, 0.64, 0);
        else glColor3f(0.278, 0.4, 0.231);
    }else if (ice_start == true){
        if (day == true) glColor3ub(164, 199, 95);
        else glColor3ub(209, 232, 172);
    } else {
        if (day == true) glColor3ub(202, 212, 74);
        else glColor3ub(151, 157, 75);
    }
    
    quad(-1, -1, 1, -1, 1, 0, -1, 0);

    if (summer == true){
        if (day == true) glColor3f(0.59, 0.79, 0.15);
        else glColor3f(0.215, 0.345, 0.149);
    }else if (ice_start == true){
        if (day == true) glColor3ub(209, 232, 172);
        else glColor3ub(195, 207, 152);
    } else {
        if (day == true) glColor3ub(162, 194, 48);
        else glColor3ub(204, 181, 110);
    }
    
    triangle(-.5, -.2, 1, -.4, 1, -.1);
    triangle(-1, -.4, -1, -.7, 0, -.5);
}

void river(){
    if (day == true) glColor3f(0.17, 0.61, 0.811);
    else glColor3f(0, 0.223, 0.28);
    quad(-1, 0, 1, 0, 1, -0.1, -1, -0.1);
}

void boat_update(int value){
    if( !paused ){
        boat_move -= .01;
        if(boat_move+0.2 < -1.0){
            boat_move = 1; //when object goes out of display while incrementing its position, set the coordinate to the opposite position so that it feels like the object is continuously moving
        }
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(70, boat_update, 0); //Notify GLUT to call update again in 25 milliseconds
}

void boat(){
    glPushMatrix(); //Save the current state of transformations //Move to the center of the triangle
    glTranslatef(boat_move, 0.0f, 0.0f); //moving along x-axis

    glLineWidth(3);
    glColor3f(0.56, 0.34, 0.23);
    glBegin(GL_LINES);
    
    glVertex2f(-.01, -.04);
    glVertex2f(-.01, .3);

    glVertex2f(0.1, -.04);
    glVertex2f(-.01, .28);

    glEnd();

    glColor3f(0.99, 0.1, 0);
    triangle(-0.015, 0.28, -0.015, 00, -0.14, 0);

    glColor3f(0.99, 0.73, 0);
    quad(-0.16, -0.03, -0.13, -0.06, 0.13, -0.06, 0.16, -0.03);

    glPopMatrix();
}

void tree(){
    glPushMatrix();
    glTranslated(0, 0.13, 0);

    glColor3f(0.27, 0.12, 0.05);

    quad(-.67, -.2, -.84, -.9, -.73, -.9, -.6, -.2); // main
    quad(-.6, -.22, -.4, -.29, -.39, -.28, -.55, -.2); // right down
    quad(-.63, -.18, -.65, -.28, -.4, -.1, -.33, -.09); // right mid
    quad(-.6, -.18, -.55, -.18, -.55, -.01, -.56, -.02); // right up    
    quad(-.75, -.16, -.68, -.18, -.78, .02, -.8, .03); // left up
    quad(-.63, -.18, -.62, -.28, -.9, -.14, -.89, -.12); // left down

    if (ice_start == false) treeLeaf();

    if (ice_start == true){
        if (day == true) glColor3f(1.0, 1.0, 1.0);
        else glColor3f(0.83, 0.85, 0.88);

        quad (-.89, -.12, -.895, -.125, -.85, -.15, -.785, -.14); // left down
        polygon(-.78, .02, -.8, .03, -.75, -.08, -.75, -.1, -.695, -.145); // left up
        quad(-.59, -.15, -.55, -.1, -.55, -.01, -.56, -.02); // right up  
        quad(-.55, -.155, -.5, -.17, -.4, -.1, -.33, -.09); // right mid
        quad(-.5, -.25, -.4, -.29, -.39, -.28, -.55, -.2); // right down
    }

    glPopMatrix();
}

void treeLeaf(){
    // right down
    if (summer == false) glColor3ub(99, 112, 39);
    else if (summer == true && day == true) glColor3f(0.16, 0.54, 0.16);
    else glColor3f(0.12, 0.29, 0.06);  

    circle(-0.14, -0.25, 0.12);
    circle(-0.41, -0.2, 0.1);
    circle(-0.25, -0.28, 0.15);

    // left down
    circle(-0.85, -0.19, 0.1);
    circle(-1, -0.2, 0.15);

    // right up
    if (summer == false) glColor3ub(138, 163, 54);
    else if (summer == true && day == true) glColor3f(0.37, 0.66, 0.18);
    else glColor3f(0.16, 0.54, 0.16); 

    circle(-0.16, -0.18, 0.12);
    circle(-0.41, 0, 0.16);
    circle(-0.25, -0.05, 0.15);

    // left up
    circle(-0.82, 0, 0.15);
    circle(-0.95, -0.05, 0.12);

    // mid
    if (summer == false) glColor3ub(159, 173, 50);
    else if (summer == true && day == true) glColor3f(0.41, 0.72, 0.2);
    else glColor3f(0.37, 0.66, 0.18);

    circle(-0.79, 0.04, 0.12);
    circle(-0.32, 0.07, 0.12);
    circle(-0.63, 0.15, 0.22);
    circle(-0.47, 0.14, 0.17);
}

void windmill_update(int value){
    if(!paused) windmill_move += 0.2;
    
    glutPostRedisplay(); //Notify GLUT that the display has changed
    if (rain_start == true) glutTimerFunc(5, windmill_update, 0);
    else glutTimerFunc(50, windmill_update, 0); //Notify GLUT to call update again in 25 milliseconds
}

void windmill(){
    glPushMatrix();
    glTranslated(0.84, 0.2, 0);

    // pillar
    if (day == true) glColor3f(0.9, 0.74, 0.63);
    else glColor3f(0.635, 0.521, 0.443);
    quad(-.01, 0, -.03, -.35, .03, -.35, .01, 0);

    // Fan
    glRotatef(windmill_move, 0.0, 0.0, 0.1);
    glColor3f(1, 0.93, 0.6);

    quad(0, 0, 0, .2, -.1, .2, 0, 0);
    quad(0, 0, 0, -.2, .1, -.2, 0, 0);
    quad(0, 0, .2, 0, .2, .1, 0, 0);
    quad(0, 0, -.2, 0, -.2, -.1, 0, 0);

    if (day == true) glColor3f(0.59, 0.79, 0.15);
    else glColor3f(0.105, 0.325, 0.38);

    quad(0, 0, 0, 0.2, -0.01, 0.2, -0.01, 0);
    quad(0, 0, 0, -0.2, 0.01, -0.2, 0.01, 0);
    quad(0, 0, 0.2, 0, 0.2, 0.01, 0, 0.01);
    quad(0, 0, -0.2, 0, -0.2, -0.01, 0, -0.01);

    // center
    glColor3f(1, 1, 1);
    circle(0.0, 0.0, .015);
    glPopMatrix();
}

void grass(){
    if (summer == true){
        if (day == true) glColor3f(0.12, 0.29, 0.06);
        else glColor3f(0.074, 0.211, 0);
    }else if (ice_start == true){
        if (day == true) glColor3ub(77, 135, 73);
        else glColor3ub(161, 202, 130);
    } else {
        glColor3ub(83, 135, 61);
    }
    
    circle(-.9, -.9, .2);
    circle(0.9, -.9, .19);

    if (summer == true){
        if (day == true) glColor3f(0.19, 0.5, 0.06);
        else glColor3f(0.12, 0.29, 0.06);
    }else if (ice_start == true){
        glColor3ub(123, 150, 111);
    } else {
        glColor3ub(138, 163, 54);
    }

    circle(0.17, -.9, .15);
    circle(.37, -.95, .1);
    circle(-.88, -1, .12);

    if (summer == true){
        if (day == true) glColor3f(0.25, 0.64, 0.08);
        else glColor3f(0.19, 0.5, 0.06);
    }else if (ice_start == true){
        if (day == true) glColor3ub(131, 184, 112);
        else glColor3ub(161, 184, 159);
    } else {
        if (day == true) glColor3f(0.43, 0.64, 0);
        else glColor3ub(159, 173, 50);
    }

    circle(-.7, -.9, .15);
    circle(-.5, -.95, .1);
    circle(-.18, -.95, .08);
    circle(-.03, -.95, .13);
    circle(.52, -.95, .09);
    circle(.7, -.93, .13);
}

void treeFlower(float x, float y){
    glColor3ub(247, 183, 225);
    circle(0.025+x, .006+y, .013);
    circle(0.014+x, .025+y, .013);
    circle(0.0015+x, .005+y, .013);

    glColor3ub(255, 3, 3);
    circle(0.012+x, .012+y, .01);
}

void grassFlower(float x, float y, char color){
    if (color == 'r') glColor3ub(235, 29, 2);
    else if (color == 'y') glColor3ub(255, 242, 10);
    else if (color == 'p') glColor3ub(255, 186, 245); 
    circle(-.78+x, -.9+y, .02);
    circle(-.72+x, -.9+y, .02);
    circle(-.75+x, -.87+y, .02);
    circle(-.75+x, -.93+y, .02);
    //   center
    if (color == 'r') glColor3ub(255, 242, 10);
    else if (color == 'y') glColor3ub(235, 29, 2);
    else if (color == 'p') glColor3ub(235, 29, 2); 
    circle(-.75+x, -.9+y, .015);
}

void flower(){
    // tree
    treeFlower(-0.3, -0.05);
    treeFlower(-0.34, -0.03);
    treeFlower(-0.6, 0.15);
    treeFlower(-0.56, 0.19);
    treeFlower(-0.54, 0.13);
    treeFlower(-0.85, 0.11);

    // grass 
    grassFlower(0, 0, 'r');
    grassFlower(0.12, 0.08, 'y');
    grassFlower(.25, -.03, 'r');
    grassFlower(.56, -.04, 'p');
    grassFlower(.7, -.01, 'r');
    grassFlower(.87, .07, 'p');
    grassFlower(.97, -.02, 'p');
    grassFlower(1.12, -.03, 'r');
    grassFlower(1.26, -.04, 'r');
    grassFlower(1.5, .04, 'y');
    grassFlower(1.36, -.0, 'p');
}

void house(){
    glPushMatrix();
    glTranslated(0.44, -0.12, 0);

    // side wall
    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.37, 0.07);

    glVertex2f(0, 0);
    glVertex2f(-0.17, -0.03);
    glVertex2f(-0.17, -0.14);
    glVertex2f(0.17, -0.18);
    glVertex2f(0.17, -0.07);
    glEnd();

    // side window
    glColor3f(0.62, 0.32, 0.17);
    quad(-0.05, -0.05, -0.05, -0.11, 0.05, -0.12, 0.05, -0.06);

    // font wall
    glColor3f(0.62, 0.32, 0.17);
    quad(0.17, -0.07, 0.17, -0.18, 0.47, -0.18, 0.47, -0.07);

    // door
    glColor3f(0.25, 0.15, 0.07);
    quad(0.29, -0.07, 0.37, -0.07, 0.37, -0.18, 0.29, -0.18);

    // font roof
    if (ice_start == true){
        if (day == true) glColor3f(1.0, 1.0, 1.0);
        else glColor3f(0.83, 0.85, 0.88);
    }
    else glColor3f(0.55, 0.27, 0.07);
    quad(0, 0, 0.18, -0.09, 0.54, -0.09, 0.3, 0);

    // back roof
    glColor3f(0.36, 0.19, 0.07);
    triangle(-0.17, -0.03, -0.17, -0.05, -0.24, -0.048);
    quad(0, 0, -0.24, -0.048, -0.28, -0.043, 0.005, -0.005);

    glPopMatrix();
}  

void rain_cloud_update(int value){
    if (rain_start && !paused){
        if (rain_cloud_move < -0.0) rain_cloud_move = 1.0f;
        rain_cloud_move -= 0.02f;
    } 
    glutPostRedisplay();
     glutTimerFunc(100, rain_cloud_update, 0);
}

void rainCloud(){
    glColor3ub(158, 161, 163);
    glPushMatrix();
    glTranslatef(rain_cloud_move, 0.0f, 0.0f);

    circle(-2.03, .95, .1);
    circle(-1.84, .93, .15);
    circle(-1.54, .93, .18);
    circle(-1.28, .93, .15);
    circle(-1.0, .93, .17);
    circle(-.93, .95, .1);
    circle(-.72, .93, .15);
    circle(-.5, .93, .18);
    circle(-.28, .93, .15);
    circle(0.0, .95, .17);
    circle(.2, .93, .15);
    circle(.43, .93, .2);
    circle(.65, .93, .13);
    circle(.8, .95, .15);
    circle(.95, .95, .08);

    glPopMatrix();
}

void rain_update(int value){
    if (rain_start && !paused){
        if (rain_move < -1.0) rain_move = .50f;
        rain_move -= 0.2f;
    }
    glutPostRedisplay();
    glutTimerFunc(100, rain_update, 0);
}

void rain(){
    glPushMatrix();
    glTranslatef(0.0f, rain_move, 0.0f);
    glColor3ub(210, 226, 247);
    glLineWidth(2);

    glBegin(GL_LINES);

    glVertex2f(-.85, 1.9);
    glVertex2f(-.8, 1.8);
    glVertex2f(-.55, 1.9);
    glVertex2f(-.5, 1.8);
    glVertex2f(-.25, 1.9);
    glVertex2f(-.2, 1.8);
    glVertex2f(.05, 1.9);
    glVertex2f(.1, 1.8);
    glVertex2f(.35, 1.9);
    glVertex2f(.4, 1.8);
    glVertex2f(.65, 1.9);
    glVertex2f(.7, 1.8);
    glVertex2f(.95, 1.9);
    glVertex2f(1.0, 1.8);

    glVertex2f(-1.0, 1.6);
    glVertex2f(-.95, 1.5);
    glVertex2f(-.7, 1.6);
    glVertex2f(-.65, 1.5);
    glVertex2f(-.4, 1.6);
    glVertex2f(-.35, 1.5);
    glVertex2f(-.1, 1.6);
    glVertex2f(-.05, 1.5);
    glVertex2f(.2, 1.6);
    glVertex2f(.25, 1.5);
    glVertex2f(.5, 1.6);
    glVertex2f(.55, 1.5);
    glVertex2f(.8, 1.6);
    glVertex2f(.85, 1.5);

    glVertex2f(-.85, 1.3);
    glVertex2f(-.8, 1.2);
    glVertex2f(-.55, 1.3);
    glVertex2f(-.5, 1.2);
    glVertex2f(-.25, 1.3);
    glVertex2f(-.2, 1.2);
    glVertex2f(.05, 1.3);
    glVertex2f(.1, 1.2);
    glVertex2f(.35, 1.3);
    glVertex2f(.4, 1.2);
    glVertex2f(.65, 1.3);
    glVertex2f(.7, 1.2);
    glVertex2f(.95, 1.3);
    glVertex2f(1.0, 1.2);

    glVertex2f(-1.0, 1.0);
    glVertex2f(-.95, .9);
    glVertex2f(-.7, 1.0);
    glVertex2f(-.65, 0.9);
    glVertex2f(-.4, 1.0);
    glVertex2f(-.35, 0.9);
    glVertex2f(-.1, 1.0);
    glVertex2f(-.05, 0.9);
    glVertex2f(.2, 1.0);
    glVertex2f(.25, .9);
    glVertex2f(.5, 1.0);
    glVertex2f(.55, 0.9);
    glVertex2f(.8, 1.0);
    glVertex2f(.85, 0.9);

    glVertex2f(-.85, .7);
    glVertex2f(-.8, .6);
    glVertex2f(-.55, .7);
    glVertex2f(-.5, 0.6);
    glVertex2f(-.25, .7);
    glVertex2f(-.2, 0.6);
    glVertex2f(.05, .7);
    glVertex2f(.1, .6);
    glVertex2f(.35, .7);
    glVertex2f(.4, .6);
    glVertex2f(.65, .7);
    glVertex2f(.7, .6);
    glVertex2f(.95, .7);
    glVertex2f(1.0, .6);

    glVertex2f(-1.0, .4);
    glVertex2f(-.95, .3);
    glVertex2f(-.7, .4);
    glVertex2f(-.65, 0.3);
    glVertex2f(-.4, .4);
    glVertex2f(-.35, 0.3);
    glVertex2f(-.1, .4);
    glVertex2f(-.05, 0.3);
    glVertex2f(.2, .4);
    glVertex2f(.25, .3);
    glVertex2f(.5, .4);
    glVertex2f(.55, 0.3);
    glVertex2f(.8, .40);
    glVertex2f(.85, 0.3);

    glVertex2f(-.85, .1);
    glVertex2f(-.8, 0.0);
    glVertex2f(-.55, .1);
    glVertex2f(-.5, 0.0);
    glVertex2f(-.25, .1);
    glVertex2f(-.2, 0.0);
    glVertex2f(.05, .1);
    glVertex2f(.1, .0);
    glVertex2f(.35, .1);
    glVertex2f(.4, .0);
    glVertex2f(.65, .1);
    glVertex2f(.7, .0);
    glVertex2f(.95, .1);
    glVertex2f(1.0, .0);

    glVertex2f(-1.0, -.2);
    glVertex2f(-.95, -.3);
    glVertex2f(-.7, -.2);
    glVertex2f(-.65, -0.3);
    glVertex2f(-.4, -.2);
    glVertex2f(-.35, -0.3);
    glVertex2f(-.1, -.2);
    glVertex2f(-.05, -0.3);
    glVertex2f(.2, -.2);
    glVertex2f(.25, -.3);
    glVertex2f(.5, -.2);
    glVertex2f(.55, -.3);
    glVertex2f(.8, -.2);
    glVertex2f(.85, -.3);

    glVertex2f(-.85, -.5);
    glVertex2f(-.8, -.6);
    glVertex2f(-.55, -.5);
    glVertex2f(-.5, -.6);
    glVertex2f(-.25, -.5);
    glVertex2f(-.2, -.6);
    glVertex2f(.05, -.5);
    glVertex2f(.1, -.6);
    glVertex2f(.35, -.5);
    glVertex2f(.4, -.6);
    glVertex2f(.65, -.5);
    glVertex2f(.7, -.6);
    glVertex2f(.95, -.5);
    glVertex2f(1.0, -.6);

    glVertex2f(-1.0, -.8);
    glVertex2f(-.95, -.9);
    glVertex2f(-.7, -.8);
    glVertex2f(-.65, -0.9);
    glVertex2f(-.4, -.8);
    glVertex2f(-.35, -0.9);
    glVertex2f(-.1, -.8);
    glVertex2f(-.05, -0.9);
    glVertex2f(.2, -.8);
    glVertex2f(.25, -.9);
    glVertex2f(.5, -.8);
    glVertex2f(.55, -.9);
    glVertex2f(.8, -.8);
    glVertex2f(.85, -.9);

    glVertex2f(-.85, -1.1);
    glVertex2f(-.8, -1.2);
    glVertex2f(-.55, -1.1);
    glVertex2f(-.5, -1.2);
    glVertex2f(-.25, -1.1);
    glVertex2f(-.2, -1.2);
    glVertex2f(.05, -1.1);
    glVertex2f(.1, -1.2);
    glVertex2f(.35, -1.1);
    glVertex2f(.4, -1.2);
    glVertex2f(.65, -1.1);
    glVertex2f(.7, -1.2);
    glVertex2f(.95, -1.1);
    glVertex2f(1.0, -1.2);

    glVertex2f(-1.0, -1.4);
    glVertex2f(-.95, -1.5);
    glVertex2f(-.7, -1.4);
    glVertex2f(-.65, -1.5);
    glVertex2f(-.4, -1.4);
    glVertex2f(-.35, -1.5);
    glVertex2f(-.1, -1.4);
    glVertex2f(-.05, -1.5);
    glVertex2f(.2, -1.4);
    glVertex2f(.25, -1.5);
    glVertex2f(.5, -1.4);
    glVertex2f(.55, -1.5);
    glVertex2f(.8, -1.4);
    glVertex2f(.85, -1.5);

    glEnd();
    glPopMatrix();
}

void rainDay(){
    rainCloud();
    rain();
}

void snow_update(int value){
    if (snowfall_start && !paused){
        if (snow_move < -.05) snow_move = 1.5f;
        snow_move -= 0.05f;
    }
    glutPostRedisplay();
    glutTimerFunc(100, snow_update, 0);
}

void snowball(){
    glColor3ub(255, 255, 255);

    circle(-1.5, .95, .01);
    circle(-.95, .75, .01);
    circle(-.65, 0.55, .01);
    circle(-.35, 0.46, .01);
    circle(-.05, 0.648, .01);
    circle(.25, .83, .01);
    circle(.55, 0.8, .01);
    circle(.75, 0.35, .01);
    circle(1., 0.26, .01);
    circle(-.45, 0.148, .01);
}

void snowfall(){
    glPushMatrix();
    glLoadIdentity();
    glTranslated(0.0f, snow_move, 0.0f);
    
    snowball();
    glTranslated(0.2, -0.5, 0);
    snowball();
    glTranslated(-0.1, -0.45, 0);
    snowball();
    glTranslated(0.0, -0.5, 0);
    snowball();
    glTranslated(0.2, -0.5, 0);
    snowball();
    glTranslated(-0.1, -0.5, 0);
    snowball();

    glPopMatrix();
}




