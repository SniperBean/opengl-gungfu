#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;

void My_Display();

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    cout << "hello! freeglut!";
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("hello glut!");
    glutDisplayFunc(My_Display);
    glutMainLoop();
}

void My_Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0f);
    glutSwapBuffers();
}

