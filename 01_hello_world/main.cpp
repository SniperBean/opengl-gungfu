#include <iostream>
#include <string>
// #include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;

void My_Display();

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    cout << "hello! freeglut!";
    #ifdef _MSC_VER
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    #else
        // glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    #endif

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("hello glut!");
    // glClearColor(backgroundGray, backgroundGray, backgroundGray, 1.0f);
    glutDisplayFunc(My_Display);
    glutMainLoop();
}

void My_Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutSwapBuffers();
}

