#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

#define Red "Red"
#define Green "Green"
#define Blue "Blue"
#define SIZE_1 1
#define SIZE_2 2
#define MENU_EXIT 3

using namespace std;

void My_Display();
void My_Menu(int);
void My_Reshape(int, int);
void My_KeyBoard(unsigned char, int, int);
void My_SpecialKeys(int, int, int);
void My_Timer(int);
void My_Mouse(int, int, int, int);
void Mouse_Moving(int, int);

string myColor = Red;
float aspect;
float teapot_size = 1.0f;
float teapot_posX = 0.0f;
float teapot_posY = 0.0f;

float timer_interval = 0.0f;
float rotateAngle = 0.0f;
float rotateSpeed = 0.0f;

float			oldbackGray;
float			backgroundGray = 0.0f;
float			clickPt_x;


int main (int argc, char* argv[]) {
    glutInit(&argc, argv);
    cout << "Transform";
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    // Create Window
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Transformer!!!");

    // Create Menu
    int menu_main = glutCreateMenu(My_Menu);
    int menu_entry = glutCreateMenu(My_Menu);
    glutSetMenu(menu_main);
    glutAddSubMenu("Teapot size", menu_entry);
    glutAddMenuEntry("Exit", MENU_EXIT);
    glutSetMenu(menu_entry);
    glutAddMenuEntry("1.0", SIZE_1);
    glutAddMenuEntry("2.0", SIZE_2);
    glutSetMenu(menu_main);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    

    // Render View
    glutDisplayFunc(My_Display);
    glutReshapeFunc(My_Reshape);
    glutKeyboardFunc(My_KeyBoard);
    glutSpecialFunc(My_SpecialKeys);
    glutTimerFunc(timer_interval, My_Timer, 0);
    glutMouseFunc(My_Mouse);
    glutMotionFunc(Mouse_Moving);
    glutMainLoop();
}

void My_Display () {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(backgroundGray, backgroundGray, backgroundGray, 1.0f);

    // Setup camera

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt ( 0.0, 2.0, 5.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0);
    glColor3b(125, 0, 0);

    // Rerender teapot
    glTranslatef(teapot_posX, teapot_posY, 0.0f);
    
    if (myColor ==  Red)
        glColor3b(125, 0, 0);
    else if (myColor ==  Green)
        glColor3b(0, 125, 0);
    else if (myColor == Blue)
        glColor3b(0, 0, 125);

    glutWireTeapot(teapot_size);

    glutSwapBuffers();
}

void My_Reshape (int width, int height) {
    aspect = width * 1.0f / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(60.0f, aspect, 0.1f, 10.0f);
}

void My_KeyBoard (unsigned char key, int x, int y) {
    if (key == 'W' || key == 'w')
        teapot_posY += 0.05f;
    else if (key == 'S' || key == 's')
        teapot_posY -= 0.05f;
    else if (key == 'A' || key == 'a')
        teapot_posX -= 0.05f;
    else if (key == 'D' || key == 'd')
        teapot_posX += 0.05f;
}

void My_SpecialKeys (int key, int x, int y) {
    if (key == GLUT_KEY_F1)
        myColor = Red;
    else if (key == GLUT_KEY_F2)
        myColor = Green;
    else if (key == GLUT_KEY_F3)
        myColor = Blue;
}

void My_Timer (int val) {
    glutPostRedisplay();
    glutTimerFunc(timer_interval, My_Timer, val);
    rotateAngle += rotateSpeed * timer_interval * 0.001;
}

void My_Mouse (int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            oldbackGray = backgroundGray;
            clickPt_x = x;
        }
    }
}

void Mouse_Moving (int x, int y) {
    backgroundGray = (x - clickPt_x) * 0.005f + oldbackGray;
    backgroundGray = clamp(backgroundGray, 0.0f, 1.0f);
}

void My_Menu (int id) {
    switch (id) {
        case SIZE_1:
            teapot_size = 1.0f;
            break;
        case (SIZE_2):
            teapot_size = 2.0f;
            break;
        case (MENU_EXIT):
            exit(0);
    }
}
