#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <GL/freeglut.h>
using namespace std;

//PURPOSE: Determine how the passed in line should be plotted.
//PARAMETERS: ints x0 and y0 as starting x and y coords, ints x1 and y1 as ending x and y coords
void bresenhamDrawLine(int x0, int y0, int x1, int y1);
//PURPOSE: Set color before plotting line
//ADDITIONAL PARAMETERS: floats red, green, and blue are 0 to 1 values 
void bresenhamDrawLine(int x0, int y0, int x1, int y1, float red, float green, float blue);

//PURPOSE: Plot a horizontal line in an OpenGL window
//PARAMETERS: ints x0 and y0 as starting x and y coords, ints x1 and y1 as ending x and y coords
void plotLineHorizontal(int x0, int y0, int x1, int y1);

//PURPOSE: Plot a vertical line in an OpenGL window
//PARAMETERS: ints x0 and y0 as starting x and y coords, ints x1 and y1 as ending x and y coords
void plotLineVertical(int x0, int y0, int x1, int y1);

//PURPOSE: Utilize Bresenham's algorithm to plot line with shallow slope in an OpenGL window
//PARAMETERS: ints x0 and y0 as starting x and y coords, ints x1 and y1 as ending x and y coords
void bresenhamLow(int x0, int y0, int x1, int y1);

//PURPOSE: Utilize Bresenham's algorithm to plot line with shallow slope in an OpenGL window
//PARAMETERS: ints x0 and y0 as starting x and y coords, ints x1 and y1 as ending x and y coords
void bresenhamHigh(int x0, int y0, int x1, int y1);

//PURPOSE: Plot a single point in an OpenGL window
//PARAMETERS: ints x and y represent a coordinate in an OpenGL window
void plotPoint(int x, int y);