#include "display.h"
#include "bresenham.h"

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(XMAX, YMAX);
    glutCreateWindow("Bresenham");
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}