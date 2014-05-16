#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

void drawBox(double x, double y, double width, double height);
void drawBox(double *pos);
void drawText(double x, double y, const char *text);
void drawTriangle(double x, double y, double width, double height);

void drawTriangle(double *pos);

void drawLeg(double x, double y, double width, double height);

void drawLeg(double *pos);

void drawLeg2(double x, double y, double width, double height);

void drawLeg2(double *pos);

void drawTriangle2(double x, double y, double width, double height);

void drawArm(double x, double y, double width, double height);

void drawArm(double *pos);

void drawArm2(double x, double y, double width, double height);

void drawArm2(double *pos);

void drawTriangle2(double *pos);


void drawCircle(double x, double y, double radius);

void drawCircle(double * pos);

void drawSemi(double x, double y, double radius);

void drawSemi(double * pos);

void drawText(string textVal, int positionX, int positionY);

void drawLargestText(string textVal, int positionX, int positionY);

void drawOtherSideSemi(double x, double y, double radius);

void drawOtherSideSemi(double * pos);

void drawHappyFace(int positionX, int positionY, int radius);

void drawSadFace(int positionX, int positionY, int radius);

void drawModerateFace(int positionX, int positionY, int radius);

string convertIntToString(int toConvert);

int getWidthOfString(string theString);
