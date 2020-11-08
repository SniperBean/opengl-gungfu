#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;

void My_Display();
void My_Reshape(int, int);

float aspect;
float teapot_size = 1.0f;

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    cout << "Teapot";
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("First teapot? Huh?");
    glutDisplayFunc(My_Display);
    glutReshapeFunc(My_Reshape);
    glutMainLoop();
}

void My_Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0f);

    // Setup camera and draw teapot

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt ( 0.0, 2.0, 5.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0);
    glColor3b(125, 0, 0);
    glutWireTeapot(teapot_size);

    glutSwapBuffers();
}

void My_Reshape(int width, int height) {
    aspect = width * 1.0f / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(60.0f, aspect, 0.1f, 10.0f);
}

