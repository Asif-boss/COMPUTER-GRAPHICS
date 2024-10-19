//#include <windows.h>
//#include <GL/gl.h> // for MS Windows
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include<cstring>
using namespace std;

# define pi 3.1416

bool paused = false;
bool light = true;
bool day = true;
bool train_run = false;
bool train_paused = false;
float train_move = 3500.0f;
float cloud_move = 0.0f;
bool comet_start = false;
float comet_move = 0.0f;
float plane_move = 0.0f;
float rain_cloud_move = 800.0f;
float rain_move = 2.50f;
bool rain_start = false;
char key;

void myDisplay();
void myInit(void);
void mouse(int button, int state, int x, int y);
void keyboardFunc(unsigned char key, int x, int y);
void quad(float a, float b, float c, float d, float e, float f, float g, float h);
void triangle(float a, float b, float c, float d, float e, float f);
void line(float a, float b, float c, float d);
void draw_circle(float x1, float y1, float r);
void draw_object();
void traffic_light();
void sky();
void star();
void cloud_update(int value);
void cloud();
void sun_moon();
void grass();
void platform();
void tree(int x);
void table(int x);
void polygon(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j);
void hexa(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m);
void building();
void train();
void train_update(int value);
void comet();
void comet_update(int value);
void plane();
void plane_update(int value);
void rain_cloud_update(int value);
void rainDay();
void rain();
void rain_update(int value);
void lampPost();

int main(int argc, char** argv) {
    cout << "                      ARRIVAL AND DEPARTURE OF TRAIN" << endl;
    cout << "                                DEVELOPED BY: " << endl;
    cout << "                         TASLIM SARKER 22-49038-3" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Press 'r' or 'R' to change the signal light to red. \n\n";
    cout << "Press 'g' or 'G' to change the signal light to green. \n\n";
    cout << "Press 'd' or 'D' to make it day. \n\n";
    cout << "Press 'n' or 'N' to make it night. \n\n";
    cout << "Press 't' or 'T' Train arrive at station.\n\n";
    cout << "Press 's' or 'S' to see comet.\n\n";
    cout << "Press 'r' or 'R' to start or stop rain. \n\n";
    cout << "Press RIGHT MOUSE BUTTON to display menu. \n\n";
    cout << "Press LEFT MOUSE BUTTON to quit the program. \n\n\n";
	cout << "Press to procceed[D/N]: ";
	cin >> key;
    
    bool check = true;

    while (check){
        switch (key){
            case 'd':
            case 'D':       
                day = true;
                check = false;
                break;

            case 'n':
            case 'N':
                day = false;
                check = false;
                break;

            default:   
                cout << "Give currect input[D/N]: ";
                cin >> key;
        }
    }

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1100, 700);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1100)/2, (glutGet(GLUT_SCREEN_HEIGHT)-700)/2);
	glutCreateWindow("Railway Station Scenario");

	glutDisplayFunc(myDisplay); //Set handler functions
    myInit();
    //glutSpecialFunc(specialKeys); //Special Key Handler
	glutKeyboardFunc(keyboardFunc);   //Basic keyboard key handler
	glutMouseFunc(mouse);         //Mouse Handler
	//glutReshapeFunc(handleResize);

    glutTimerFunc(40, train_update, 0); //Notify GLUT to call update again in 40 milliseconds
	glutTimerFunc(100, cloud_update, 0);
    glutTimerFunc(80, comet_update, 0);
    glutTimerFunc(50, plane_update, 0);
    glutTimerFunc(100, rain_cloud_update, 0);
    glutTimerFunc(100, rain_update, 0);

    glutMainLoop();
	return 0;
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) exit(0);
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // Pause/resume
        paused = !paused;         // Toggle state
   }
}

void keyboardFunc(unsigned char key, int x, int y){
    switch (key){
        case 'd':
        case 'D':       
            day = true;
            break;

        case 'n':
        case 'N':
            day = false;
            break;

        case 't':
        case 'T':
            train_run = true;
            break;

        case 'g':
        case 'G':
            light = 1;
            train_paused = false;
            break;

        case 'r':
        case 'R':
            light = 0;
            train_paused = true;
            break;

        case 'c':
        case 'C':
            if (light = true)
            comet_start = true;
            break;

        case 's':
        case 'S':
            rain_start = !rain_start;
            break;
    }
    glutPostRedisplay();
}

void myInit(void){
    glClearColor(0, 0, 0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1100.0, 0.0, 700.0);
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    glFlush();
}

void line(float a, float b, float c, float d){
    glBegin(GL_LINES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glEnd();
}

void quad(float a, float b, float c, float d, float e, float f, float g, float h){
    glBegin(GL_QUADS);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glEnd();
}

void draw_circle(float x1, float y1, float r){
    glBegin(GL_POLYGON);
	for(int i=0;i<180;i++){
		float A=(i*2*pi)/180 ;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+x1, y+y1);
	}
    glEnd();
}

void triangle(float a, float b, float c, float d, float e, float f){
    glBegin(GL_TRIANGLES);

    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);

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

void hexa(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l){
    glBegin(GL_POLYGON);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glVertex2f(i, j);
    glVertex2f(k, l);
    glEnd();
}

void draw_object(){
    sky();
    if (!rain_start) sun_moon();
    if (day == true && !rain_start) plane();
    if (day == true && !rain_start) cloud();
    grass();
    lampPost();
    platform();
    traffic_light();
    train();
    if (day == false && comet_start == true && !rain_start) comet();
    if (rain_start == true) rainDay();
}

void sky(){
    if (day == true){
        if (rain_start == true) glColor3ub(171, 183, 191);
        else glColor3f(0.0, 0.9, 0.9);
        quad(0, 380, 0, 700, 1100, 700, 1100, 380);
    }else{
        glColor3f(0.0, 0.0, 0.0);
        quad(0, 380, 0, 700, 1100, 700, 1100, 380); // sky
        if (rain_start == false) star();
    } 
}

void star(){
    glColor3f(1.0, 1.0, 1.0);
    // star1       
    triangle(575, 653, 570, 645, 580, 645);
    triangle(575, 642, 570, 650, 580, 650);
    // star2
    triangle(975, 643, 970, 635, 980, 635);
    triangle(975, 632, 970, 640, 980, 640);
    // star3
    triangle(875, 543, 870, 535, 880, 535);
    triangle(875, 532, 870, 540, 880, 540);
    // star4
    triangle(375, 598, 370, 590, 380, 590);
    triangle(375, 587, 370, 595, 380, 595);
    //star 5
    triangle(750, 628, 745, 620, 755, 620);
    triangle(750, 618, 745, 625, 755, 625);
    //star 7
    triangle(100, 528, 95, 520,105, 520);
    triangle(100, 518, 95, 525, 105, 525);
    //star 8
    triangle(300, 468,295, 460, 305, 460);
    triangle(300, 458,295, 465, 305, 465);
    //star 9
    triangle(500, 543,495, 535, 505, 535);
    triangle(500, 532,495, 540, 505, 540);
}

void sun_moon(){
    if (day == true)glColor3f(1.0, 0.9, 0.0);
    else glColor3f(1.0, 1.0, 1.0);
    draw_circle(100, 625, 35);
}

void cloud_update(int value){
    if( !paused ){
        cloud_move -= 3;
        if(cloud_move+500 < 0){
            cloud_move = 1000; //when object goes out of display while incrementing its position, set the coordinate to the opposite position so that it feels like the object is continuously moving
        }
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(100, cloud_update, 0); //Notify GLUT to call update again in 25 milliseconds
}

void cloud(){
    glPushMatrix(); //Save the current state of transformations //Move to the center of the triangle
    glTranslatef(cloud_move, 0.0f, 0.0f); //moving along x-axis

    // cloud1
    glColor3f(1.0, 1.0, 1.0);
    draw_circle(160, 625, 20);
    draw_circle(200, 625, 35);
    draw_circle(225, 625, 35);
    draw_circle(265, 625, 20);

    // cloud2
    glColor3f(1.0, 1.0, 1.0);
    draw_circle(370, 615, 20);
    draw_circle(410, 615, 35);
    draw_circle(435, 615, 35);
    draw_circle(470, 615, 35);
    draw_circle(500, 615, 20);

    glPopMatrix();
}

void grass(){
    if (day == true)glColor3f(0.0, 0.9, 0.0);
    else glColor3f(0.0, 0.3, 0.0);
    quad(0, 160, 0, 380, 1100, 380, 1100, 160);
}

void platform(){
    // basw
    if (day == true) glColor3f(0.560784, 0.560784, 0.737255);
    else glColor3f(0.2196, 0.2196, 0.2823);
    quad(0, 160, 0, 250, 1100, 250, 1100, 160);

    // side wall
    if (day == true) glColor3f(0.647059, 0.164706, 0.164706);
    else glColor3f(0.4431, 0.14509, 0.14509);
    quad(-100, 100, -100, 150, 1100, 150, 1100, 100);   

    // railway station boundary
    // vertical
    polygon(0, 250, 0, 310, 5, 320,10, 310, 10, 250);
    polygon(90, 250, 90, 310,95, 320, 100, 310,100, 250);
    polygon(140, 250, 140, 310, 145, 320, 150, 310, 150, 250);
    polygon(190, 250, 190, 310, 195, 320, 200, 310, 200, 250);
    polygon(240, 250, 240, 310, 245, 320, 250, 310, 250, 250);
    polygon(340, 250, 340, 310, 345, 320, 350, 310, 350, 250);
    polygon(390, 250, 390, 310, 395, 320, 400, 310, 400, 250);
    polygon(950, 250, 950, 310,955, 320, 960, 310, 960, 250);
    polygon(1000, 250, 1000, 310,1005, 320, 1010, 310, 1010, 250);
    polygon(1050, 250, 1050, 310,1055, 320, 1060, 310, 1060, 250);
    //horizontal
    quad(0, 295, 0, 305, 1100, 305, 1100, 295);
    quad(0, 265, 0, 275, 1100, 275, 1100, 265);

    building();
    
    // track boundary
    if (day == true){
        glColor3f(1.0, 1.0, 1.0);
        quad(0, 150, 0, 160, 1100, 160, 1100, 150);
    }

    // below track
    glColor3f(0.623529, 0.623529, 0.372549);
    for (int i = 0; i < 14; i++){
        quad(10+i*90, 0, 10+i*90, 80, 90+i*90, 80, 90+i*90, 0);
    }
    
    tree(0);
    tree(250);
    tree(960);

    table(0);
    table(250);
    table(450);
}

void table(int x){
    if (day == true) glColor3f(1.0, 0.498039, 0.0);
    else glColor3f(0.568, 0.317, 0.066);
    quad(140+x, 190,140+x, 210,155+x, 210,155+x, 190);
    quad(200+x, 190,200+x, 210,215+x, 210,215+x, 190);

    glColor3f(0.2, 0.2, 0.2);
    quad(130+x, 210,130+x, 215,225+x, 215,225+x, 210);    
}

void tree(int x){
    if (day == true) glColor3f(0.9, 0.2, 0.0);
    else glColor3f(0.27, 0.12, 0.05);
    quad(50+x, 185,50+x, 255,65+x, 255,65+x, 185);
    
    if (day == true) glColor3f(0.0, 0.5, 0.0);
    else glColor3f(0.12, 0.29, 0.06);
    draw_circle(40+x, 250, 30);
    draw_circle(80+x, 250, 30);
    draw_circle(50+x, 290, 25);
    draw_circle(70+x, 290, 25);
    draw_circle(60+x, 315, 20);
}

void building(){
    quad(400, 250, 400, 450, 950, 450, 950, 250);

    // font design
    if (day == true) glColor3f(0.847059, 0.847059, 0.74902);
    else glColor3f(0.6117, 0.6117, 0.6117);
    hexa(425, 250, 425, 400, 450, 425, 550, 425, 575, 400, 575, 250);
    hexa(600, 250, 600, 400, 625, 425, 725, 425, 750, 400, 750, 250);
    hexa(775, 250, 775, 400, 800, 425, 900, 425, 925, 400, 925, 250);

    //font window 
    glColor3f(0.196078, 0.6, 0.8);
    quad(450, 300,450, 375,550, 375,550, 300); // window 1
    quad(800, 300,800, 375,900, 375,900, 300);// window 2

    glColor3f(0.0, 0.0, 0.0);
    line(450, 337.5, 550, 337.5); // window 1
    line(500, 375, 500, 300);

    line(800, 337.5, 900, 337.5); // window 2
    line(850, 375, 850, 300);

    //roof
    if (day == true) glColor3f(0.556863, 0.419608, 0.137255);
    else glColor3f(0.349019608, 0.235294118, 0.003921569);
    quad(350, 450, 450, 500, 900, 500, 1000, 450);

    // side window
    triangle(400, 400, 350, 350, 400, 350); // window 1
    triangle(950, 400, 1000, 350, 950, 350); // window 2
    
    //  door
    glColor3f(0.329412, 0.329412, 0.329412);
    quad(625, 250,625, 375,725, 375,725, 250);

    // board stand
    glColor3f(0.5, 0.5, 0.5);
    quad(580, 500,580, 520,590, 520,590, 500);

    glColor3f(0.5, 0.5, 0.5);
    quad(770, 500,770, 520,780, 520,780, 500);

    // board 
    glColor3f(0.435294, 0.258824, 0.258824);
    hexa(560, 510,560, 540,580, 550,780, 550,800, 540,800, 510);

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(570, 520);
    char board[] = "RAILWAY STATION";    
    for( int i=0, l=strlen(board); i < l; i++){
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, board[i]);
    }
}

void train_update(int value){
    if(train_run == true && !paused && !train_paused){
        train_move += 10;
        if(train_move-1200 > 1100){
            train_move = -600; //when object goes out of display while incrementing its position, set the coordinate to the opposite position so that it feels like the object is continuously moving
        }
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(40, train_update, 0); //Notify GLUT to call update again in 25 milliseconds
}

void train(){
    if (train_run == true)    {
        glPushMatrix(); //Save the current state of transformations //Move to the center of the triangle
        glTranslatef(train_move, 0.0f, 0.0f);

        // train carrier
        if (day == true) glColor3f(0.258824, 0.435294, 0.258824);
        else glColor3f(0, 0.176, 0);

        quad(300, 50,300, 300,-100, 300,-100, 50); //1
        quad(-150, 50,-150, 300,-550, 300,-550, 50);// 2
        quad(-600, 50,-600, 300,-1000, 300,-1000, 50); //3

        // top
        glColor3f(0.309804, 0.184314, 0.184314);

        quad(310, 300,310, 310,-110, 310,-110, 300); // 1
        quad(-140, 300,-140, 310,-560, 310,-560, 300); //2
        quad(-590, 300,-590, 310,-1010, 310,-1010, 300); //3

        // Windows
        glColor3f(1.0, 1.0, 1.0);

        quad(75, 175,75, 285,-85, 285,-85, 175); // 1
        quad(285, 175,285, 285,125, 285,125, 175);

        quad(-375, 175,-375, 285,-535, 285,-535, 175); //2
        quad(-165, 175,-165, 285,-325, 285,-325, 175); 

        quad(-825, 175,-825, 285,-985, 285,-985, 175); //3
        quad(-615, 175,-615, 285,-775, 285,-775, 175);

        // carrier 3 Wheels
        glColor3f(0.35, 0.16, 0.14);

        draw_circle(-25, 50, 50); //1
        draw_circle(225, 50, 50);

        draw_circle(-225, 50, 50); //2
        draw_circle(-475, 50, 50); 

        draw_circle(-675, 50, 50); //3
        draw_circle(-925, 50, 50);

        // pull
        glColor3f(0.309804, 0.184314, 0.184314);

        quad(350, 75,350, 95,300, 95,300, 75); //1
        quad(-100, 75,-100, 95,-150, 95,-150, 75); //2
        quad(-550, 75,-550, 95,-600, 95,-600, 75); //3
   
        // engine 
        // train base
        if (day == true) glColor3f(0.196078, 0.6, 0.8);
        else glColor3f(0, 0.16, 0.239);
        quad(350, 50,350, 125,755, 125,820, 50);

        // train control chamber
        if (day == true) glColor3f(1.0, 0.25, 0.0);
        else glColor3f(0.635, 0.258, 0.133);
        quad(360, 125,360, 325,560, 325,560, 125);

        // window
        glColor3f(1.0, 1.0, 1.0);
        quad(375, 175,375, 315,545, 315,545, 175);

        // train top
        glColor3f(0.309804, 0.184314, 0.184314);
        quad(350, 325,350, 350,570, 350,570, 325);

        // tain engine
        glColor3f(1.0, 0.5, 0.0);
        quad(560, 125,560, 225,755, 225,755, 125);

        glColor3f(0.0, 0.0, 0.0);
        quad(580, 125,580, 225,590, 225,590, 125);
        quad(600, 125,600, 225,610, 225,610, 125);
        quad(735, 125,735, 225,745, 225,745, 125);

        // tain smoke
        glColor3f(0.196078, 0.6, 0.9);
        quad(650, 225,650, 275,700, 275,700, 225);
        
        glColor3f(0.309804, 0.184314, 0.184314);
        quad(640, 275,640, 300,710, 300,710, 275);

        // train head-light
        glColor3f(1.0, 1.0, 0.0);
        quad(755, 225,765, 225,765, 185,755, 185);

        glColor3f(0.0, 0.0, 0.0);
        triangle(755, 225,785, 225,755, 205);
        
        // train wheels
        glColor3f(0.35, 0.16, 0.14);
        draw_circle(425, 50, 50);
        draw_circle(700, 50, 50);

        glPopMatrix();
    }
}

void traffic_light(){
    if (day == true) glColor3f(1.0, 0.0, 0.0);
    else glColor3f(0.5529, 0.1529, 0.1450);
    quad(1060, 160,1060, 350,1070, 350,1070, 160);

    if (day == true) glColor3f(0.7, 0.7, 0.7);
    else glColor3f(0.329412, 0.329412, 0.329412);
    quad(1040, 350,1040, 500,1090, 500,1090, 350);

    glColor3f(1.0, 1.0, 0.0);
    draw_circle(1065, 425, 20);

    if (light == true){
        glColor3f(0.0, 0.0, 0.0);
        draw_circle(1065, 475, 20);

        glColor3f(0.0, 0.7, 0.0);
        draw_circle(1065, 375, 20);
    }else{
        glColor3f(1.0, 0.0, 0.0);
        draw_circle(1065, 475, 20);

        glColor3f(0.0, 0.0, 0.0);
        draw_circle(1065, 375, 20);
    }
}

void comet_update(int value){
    if( !paused && comet_start == true){
        comet_move += 10;
        if(comet_move > 700){
            comet_start = false;
            comet_move = 0.0; //when object goes out of display while incrementing its position, set the coordinate to the opposite position so that it feels like the object is continuously moving
        }
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(40, comet_update, 0); //Notify GLUT to call update again in 25 milliseconds
}

void comet(){
    glPushMatrix(); //Save the current state of transformations //Move to the center of the triangle
    glTranslatef(comet_move, 0.0f, 0.0f);

	glColor3f(1.0, 1.0, 1.0);
	draw_circle(300, 675, 7);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(200, 675);
	glVertex2f(300, 682);
	glVertex2f(300, 668);
	glEnd();

    glPopMatrix();
}

void plane_update(int value){
    if( !paused ){
        plane_move -= 10;
        if(plane_move+1000< 0){
            plane_move = 350; //when object goes out of display while incrementing its position, set the coordinate to the opposite position so that it feels like the object is continuously moving
        }
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(50, plane_update, 0); //Notify GLUT to call update again in 25 milliseconds
}

void plane(){
    glPushMatrix(); //Save the current state of transformations //Move to the center of the triangle
    glTranslatef(plane_move, 0.0f, 0.0f);

    glColor3ub(234, 234, 234);
    glBegin(GL_POLYGON);

    glVertex2f( 805, 615);
    glVertex2f( 815, 650);
    glVertex2f( 800, 640);
    glVertex2f( 725, 640);
    glVertex2f( 710, 630);
    glVertex2f( 701, 630);
    glVertex2f( 701, 615);

    glEnd();

    draw_circle(700, 622, 7);

    glColor3ub(186, 187, 189);
    triangle(726, 625, 764, 625, 791, 600);

    glColor3ub(0, 0, 0);
    for (int i = 0; i < 6; i++){
        draw_circle(730+i*10, 632, 3);
    }
    
    glPopMatrix();
}

void rain_cloud_update(int value){
    if (rain_start && !paused){
        if (rain_cloud_move < -1000) rain_cloud_move = -400.0f;
        rain_cloud_move -= 5.0f;
    } 
    glutPostRedisplay();
    glutTimerFunc(30, rain_cloud_update, 0);
}

void rainCloud(){
    glColor3ub(158, 161, 163);
    glPushMatrix();
    glTranslatef(rain_cloud_move, 0.0f, 0.0f);

    draw_circle(350, 690, 30);
    draw_circle(400, 690, 40);
    draw_circle(470, 690, 50);
    draw_circle(550, 690, 45);
    draw_circle(610, 690, 35);
    draw_circle(670, 690, 40);
    draw_circle(730, 690, 30);
    draw_circle(800, 690, 50);
    draw_circle(880, 690, 35);
    draw_circle(950, 690, 50);
    draw_circle(1010, 690, 55);
    draw_circle(1100, 690, 40);
    draw_circle(1150, 690, 45);
    draw_circle(1200, 690, 40);
    draw_circle(1250, 690, 35);

    draw_circle(1300, 690, 50);
    draw_circle(1350, 690, 45);
    draw_circle(1400, 690, 35);
    draw_circle(1450, 690, 45);
    draw_circle(1500, 690, 55);
    draw_circle(1580, 690, 40);
    draw_circle(1630, 690, 30);
    draw_circle(1700, 690, 50);
    draw_circle(1780, 690, 35);
    draw_circle(1850, 690, 50);
    draw_circle(1910, 690, 55);
    draw_circle(2000, 690, 40);
    draw_circle(2050, 690, 45);
    draw_circle(2100, 690, 40);
    draw_circle(2150, 690, 35);

    glPopMatrix();
}

void rain_update(int value){
    if (rain_start && !paused){
        if (rain_move < -350.0) rain_move = 0.0f;
        rain_move -= 10.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(30, rain_update, 0);
}

void rain(){
    glPushMatrix();
    glTranslatef(0.0f, rain_move, 0.0f);
    glColor3ub(210, 226, 247);
    glLineWidth(3);

    glBegin(GL_LINES);

    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 18; j+=2){
            glVertex2f(0+i*70, 1070-j*90);
            glVertex2f(25+i*70, 1045-j*90);
        }
    }
    
    for (int i = 0; i < 18; i++){
        for (int j = 1; j < 18; j+=2){
            glVertex2f(20+i*70, 1070-j*90);
            glVertex2f(45+i*70, 1045-j*90);
        }
    }

    glEnd();
    glPopMatrix();
}

void rainDay(){
    rain();
    rainCloud();
}

void lampPost(){
    glColor3f(0.7, 0.7, 0.7);
    quad(80, 250, 80, 450, 90, 450, 90, 250);
    quad(220, 250, 220, 450, 230, 450, 230, 250);
    quad(1000, 250, 1000, 450, 1010, 450, 1010, 250);

    if (day == true && rain_start == false) glColor3f(1, 1, 1);
    else glColor3f(1, 1, 0.0);
    polygon(75, 450, 95, 450, 100, 480, 85, 485, 70, 480);
    polygon(215, 450, 235, 450, 240, 480, 225, 485, 210, 480);
    polygon(995, 450, 1015, 450, 1020, 480, 1005, 485, 990, 480);
}