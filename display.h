using namespace std;

#define XMIN 0
#define YMIN 0
#define XMAX 640
#define YMAX 480
#define COLORMAX 1.0
#define COLORMIN 0.0
#define DEFAULT_RED 1.0f
#define DEFAULT_GREEN 0.9f
#define DEFAULT_BLUE 0.0f
#define FILENAME "lines.in"

//Structure of a line, containing starting coordinates, ending coordinates, and RGB color
struct Line
{
    int x0;
    int y0;
    int x1;
    int y1;
    float red;
    float green;
    float blue;
};

//PURPOSE: Read lines from a file lines.in and plot them in an OpenGL window
//PRECONDITIONS: OpenGL Window already initialized
void display();

//PURPOSE: Check for invalid values in a line from lines.in and correct them or return false
//PARAMETERS: Line currentLine, passed by reference for corrections, int lineNum = current line number
bool checkForErrors(Line &currentLine, int lineNum);