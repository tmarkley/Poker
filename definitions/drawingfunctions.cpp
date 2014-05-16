#include "../headers/drawingfunctions.h"

// const float DEG2RAD = 3.14159/180;

void drawBox(double x, double y, double width, double height) {

  glBegin(GL_POLYGON);
    glVertex2f(x, y);  // upper left
    glVertex2f(x, y + height);  // lower left
    glVertex2f(x + width, y + height);  // lower right
    glVertex2f(x + width, y);  // upper right
  glEnd();

}

void drawBox(double *pos) {
  drawBox(pos[0], pos[1], pos[2], pos[3]);
}

void drawText(double x, double y, const char *text) {
  glRasterPos2f( x, y );
  int length = strlen(text);
  for (int i = 0; i < length; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
}


void drawTriangle(double x, double y, double width, double height)
{
  glBegin(GL_POLYGON);
    glVertex2f(x, y);  // upper left
    glVertex2f(x + width, y);  // lower left
    glVertex2f(x + (width/2), y - height);  // lower right
  glEnd();
}

void drawTriangle(double *pos){
  drawTriangle(pos[0], pos[1], pos[2], pos[3]);
}

void drawLeg(double x, double y, double width, double height)
{
  glBegin(GL_POLYGON);
 glVertex2f(x, y);  // upper left
 glVertex2f(x + width, y + (height));  // lower left
 glVertex2f(x + (2*width), y + (height));  // lower right
 glVertex2f(x + width, y);  // upper right
  glEnd();
}

void drawLeg(double *pos)
{
  drawLeg(pos[0], pos[1], pos[2], pos[3]);
}

void drawLeg2(double x, double y, double width, double height)
{
  glBegin(GL_POLYGON);
 glVertex2f(x, y);  // upper left
 glVertex2f(x - width, y + (height));  // lower left
 glVertex2f(x - (2*width), y + (height));  // lower right
 glVertex2f(x - width, y);  // upper right
  glEnd();
}

void drawLeg2(double *pos)
{
  drawLeg2(pos[0], pos[1], pos[2], pos[3]);
}

void drawTriangle2(double x, double y, double width, double height)
{
  glBegin(GL_POLYGON);
    glVertex2f(x, y);  // upper left
    glVertex2f(x + (width/2), y+height);  // lower left
    glVertex2f(x + width, y);  // lower right
  glEnd();
}


void drawArm(double x, double y, double width, double height)
{
  glBegin(GL_POLYGON);
 glVertex2f(x, y);  // upper left
 glVertex2f(x + width, y + (height));  // lower left
 glVertex2f(x + (2*width), y + (height));  // lower right
 glVertex2f(x + width, y);  // upper right
  glEnd();
}

void drawArm(double *pos)
{
  drawArm(pos[0], pos[1], pos[2], pos[3]);
}

void drawArm2(double x, double y, double width, double height)
{
  glBegin(GL_POLYGON);
 glVertex2f(x, y);  // upper left
 glVertex2f(x - width, y + (height));  // lower left
 glVertex2f(x - (2*width), y + (height));  // lower right
 glVertex2f(x - width, y);  // upper right
  glEnd();
}

void drawArm2(double *pos)
{
  drawArm2(pos[0], pos[1], pos[2], pos[3]);
}

/*void Screen::drawCircle(float radius)
{
   glBegin(GL_LINE_LOOP);
   glVertex2f( 100,100);
   for (int i=0; i < 360; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
   }
 
   glEnd();
}
*/



/*void Screen::drawBox(double *pos)
{
  drawBox(pos[0], pos[1], pos[2], pos[3]);
  }*/

/*void Screen::drawTriangle(double *pos){
  drawTriangle(pos[0], pos[1], pos[2], pos[3]);
  }*/

void drawTriangle2(double *pos){
  drawTriangle2(pos[0], pos[1], pos[2], pos[3]);
}


void drawCircle(double x, double y, double radius){
  const int NUM_DIVS = 50;
  glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y);
    for ( int i = 0; i < NUM_DIVS; ++i )
      glVertex2d( x + radius*cos(i*2*M_PI/(NUM_DIVS-1)),
                 y + radius*sin(i*2*M_PI/(NUM_DIVS-1)));
  glEnd();
}

void drawCircle(double * pos){
   drawCircle(pos[0], pos[1], pos[2]);
}

void drawSemi(double x, double y, double radius){
  const int NUM_DIVS = 50;
  glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y);
    for ( int i = 0; i < NUM_DIVS; ++i )
      glVertex2d( x - radius*cos(i*M_PI/(NUM_DIVS-1)),
                 y - radius*sin(i*M_PI/(NUM_DIVS-1)));
  glEnd();
}

void drawSemi(double * pos){
   drawSemi(pos[0], pos[1], pos[2]);
}

void drawText(string textVal, int positionX, int positionY) {

  int length = textVal.length();
  // int numPixels = length * 4;
  glRasterPos2f( positionX, positionY );
  const char *text = textVal.c_str();
  for (int i = 0; i < length; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

}

void drawLargestText(string textVal, int positionX, int positionY) {

  int length = textVal.length();
  // int numPixels = length * 4;
  glRasterPos2f( positionX, positionY );
  const char *text = textVal.c_str();
  for (int i = 0; i < length; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);

}

void drawOtherSideSemi(double x, double y, double radius){
  const int NUM_DIVS = 50;
  glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y);
    for ( int i = 0; i < NUM_DIVS; ++i )
      glVertex2d( x + radius*cos(i*M_PI/(NUM_DIVS-1)),
                 y + radius*sin(i*M_PI/(NUM_DIVS-1)));
  glEnd();
}
void drawOtherSideSemi(double * pos){
   drawOtherSideSemi(pos[0], pos[1], pos[2]);
}

void drawHappyFace(int positionX, int positionY, int radius){
  double background[] = {positionX, positionY,radius+2};
  double face[] = {positionX,positionY,radius};
  double eye1[] = {positionX -  5,positionY - 5, radius -12};
  double eye2[] = {positionX + 5,positionY - 5, radius - 12};
  double smile[] = {positionX, positionY + 4, radius - 8};
  glColor3f(0,0,0);
  drawCircle(background);
  glColor3f(0,1,0);
  drawCircle(face);
  glColor3f(0,0,0);
  drawCircle(eye1);
  drawCircle(eye2);
  drawOtherSideSemi(smile);
}

void drawSadFace(int positionX, int positionY, int radius){
  double background[] = {positionX, positionY,radius+2};
  double face[] = {positionX,positionY,radius};
  double eye1[] = {positionX -  5,positionY - 5, radius -12};
  double eye2[] = {positionX + 5,positionY - 5, radius - 12};
  double smile[] = {positionX, positionY + 8, radius - 8};
  glColor3f(0,0,0);
  drawCircle(background);
  glColor3f(1,0,0);
  drawCircle(face);
  glColor3f(0,0,0);
  drawCircle(eye1);
  drawCircle(eye2);
  drawSemi(smile);
}

void drawModerateFace(int positionX, int positionY, int radius){
  double background[] = {positionX, positionY,radius+2};
  double face[] = {positionX,positionY,radius};
  double eye1[] = {positionX -  5,positionY - 5, radius -12};
  double eye2[] = {positionX + 5,positionY - 5, radius - 12};
  double smile[] = {positionX - 5, positionY + 5, radius / 3 + 5, 4};
  /*
  double background[] = {100,100,35};
  double face[] = {100,100,30};
  double eye1[] = {90,90, 5};
  double eye2[] = {110,90, 5};
  double smile[] = {83, 105, 35, 8};*/
  glColor3f(0,0,0);
  drawCircle(background);
  glColor3f(.90,.96,.11);
  drawCircle(face);
  glColor3f(0,0,0);
  drawCircle(eye1);
  drawCircle(eye2);
  drawBox(smile);
}

string convertIntToString(int toConvert) {

  ostringstream converter;
  converter << toConvert;
  return converter.str();

}


int convertStringToInt(string toConvert){
  istringstream convert(toConvert);
  int convertedVal;
  convert >> convertedVal;
  return convertedVal;
}

int getWidthOfString(string theString) {

  int width = 0;
  for (int z = 0; z < theString.size(); z ++) {
    width += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, theString[z]);
  }
  return width;

}
