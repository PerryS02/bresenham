#include "bresenham.h"

void bresenhamDrawLine(int x0, int y0, int x1, int y1)
{
    //check if line is horizontal or vertical, else use bresenham's algorithm to plot line
    if (y0 == y1)
    {
        plotLineHorizontal(x0, y0, x1, y1);
    }
    else if (x0 == x1)
    {
        plotLineVertical(x0, y0, x1, y1);
    }
    else if (abs(y1 - y0) < abs(x1 - x0))
    {
        if (x1 < x0)
        {
            bresenhamLow(x1, y1, x0, y0);
            
        }
        else
        {
            bresenhamLow(x0, y0, x1, y1);
        }
    }
    else
    {
        if (y1 < y0)
        {
            bresenhamHigh(x1, y1, x0, y0);
        }
        else
        {
            bresenhamHigh(x0, y0, x1, y1);
        }
    }
}


void bresenhamDrawLine(int x0, int y0, int x1, int y1, float red, float green, float blue)
{
    //set color of line based on input values and plot them
    glColor3f(red, green, blue);
    bresenhamDrawLine(x0, y0, x1, y1);
}


void plotLineHorizontal(int x0, int y0, int x1, int y1)
{
    if (x0 < x1)
    {
        for (int x=x0; x<=x1; x++)
        {
            plotPoint(x,y0);
        }
    }
    else
    {
        for (int x=x1; x<=x0; x++)
        {
            plotPoint(x,y0);
        }
    } 
}


void plotLineVertical(int x0, int y0, int x1, int y1)
{
    if (y0 < y1)
    {
        for (int y=y0; y<=y1; y++)
        {
            plotPoint(x0,y);
        }
    }
    else
    {
        for (int y=y1; y<=y0; y++)
        {
            plotPoint(x0,y);
        }
    } 
}


void bresenhamLow(int x0, int y0, int x1, int y1)
{
    int deltaX = x1 - x0;
    int deltaY = y1 - y0;
    int D = 2*deltaY - deltaX;
    int y = y0;
    int incrementY = 1;
    if (deltaY < 0)
    {
        incrementY = -1;
        deltaY = -1*deltaY;
    }
    for (int x=x0; x<=x1; x++)
    {
        plotPoint(x,y);
        if (D > 0)
        {
            y = y + incrementY;
            D = D - 2*deltaX;
        }
        D = D + 2*deltaY;
    }
}


void bresenhamHigh(int x0, int y0, int x1, int y1)
{
    int deltaX = x1 - x0;
    int deltaY = y1 - y0;
    int D = 2*deltaX - deltaY;
    int x = x0;
    int incrementX = 1;
    if (deltaX < 0)
    {
        incrementX = -1;
        deltaX = -1*deltaX;
    }
    for (int y=y0; y<=y1; y++)
    {
        plotPoint(x,y);
        if (D > 0)
        {
            x = x + incrementX;
            D = D - 2*deltaY;
        }
        D = D + 2*deltaX;
    }
}


void plotPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}