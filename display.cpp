#include "bresenham.h"
#include "display.h"

void display()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(XMIN, XMAX, YMIN, YMAX);
    //plot a point for runnability in case infile exists but is empty
    glColor3f(0.0f, 0.0f, 0.0f);
    plotPoint(0, 0);

    ifstream inFile(FILENAME);
    if (!inFile)
    {
        cout <<"ERROR: INPUT FILE " <<FILENAME <<" NOT FOUND.\n";
        exit(1);
    }

    Line currentLine;
    int currentLineNum = 0;
    bool invalidLine = false;
    //grab values from the input file and plot the lines until the eof is reached
    inFile >> currentLine.x0;
    while (!inFile.eof())
    {
        inFile >> currentLine.y0;
        inFile >> currentLine.x1;
        inFile >> currentLine.y1;
        inFile >> currentLine.red;
        inFile >> currentLine.green;
        inFile >> currentLine.blue;
        currentLineNum++;

        //check for invalid values on the line and set invalidLine flag accordingly
        invalidLine = checkForErrors(currentLine, currentLineNum);

        //if not invalid, plot the line
        if (!invalidLine)
        {
            if (currentLine.red == 0.0 && currentLine.green == 0.0 && currentLine.blue == 0.0)
            {
                glColor3f(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
                bresenhamDrawLine(currentLine.x0, currentLine.y0, currentLine.x1, currentLine.y1);
            }
            else
            {
                bresenhamDrawLine(currentLine.x0, currentLine.y0, currentLine.x1, currentLine.y1, currentLine.red, currentLine.green, currentLine.blue);
            }
        }
        //reset invalidLine flag and read in next line
        invalidLine = false;
        inFile >> currentLine.x0;
    } 
    inFile.close();
}


bool checkForErrors(Line &currentLine, int lineNum)
{
    bool invalid = false;
    //check the starting point is out of range of the window, if so skip
    if (currentLine.x0 < XMIN || currentLine.x0 > XMAX || currentLine.y0 < YMIN || currentLine.y0 > YMAX)
    {
        cout <<"ERROR: Starting position out of window range " <<XMAX <<" by " <<YMAX <<" on line " <<lineNum <<" of " <<FILENAME;
        invalid = true;
        cout <<", line " <<lineNum <<" skipped.\n";
    }

    //check the ending point is out of range of the window, if so skip
    if (currentLine.x1 < XMIN || currentLine.x1 > XMAX ||currentLine.y1 < YMIN || currentLine.y1 > YMAX)
    {
        cout <<"ERROR: Ending position out of window range " <<XMAX <<" by " <<YMAX <<" on line " <<lineNum <<" of " <<FILENAME;
        invalid = true;
        cout <<", line " <<lineNum <<" skipped.\n";
    }

    //check if any color values are out of range if still valid, if so set color to default
    if (!invalid)
    {
        if (currentLine.red < COLORMIN || currentLine.red > COLORMAX || currentLine.green < COLORMIN || currentLine.green > COLORMAX || currentLine.blue < COLORMIN || currentLine.blue > COLORMAX)
        {
            cout <<"ERROR: Color value not between " <<COLORMIN <<" and " <<COLORMAX <<" on line " <<lineNum <<" of " <<FILENAME;
            currentLine.red = DEFAULT_RED;
            currentLine.green = DEFAULT_GREEN;
            currentLine.blue = DEFAULT_BLUE;
            cout <<", line color set to default.\n";
        }
    }
    return invalid;
}