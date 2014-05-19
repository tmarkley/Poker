#include "../headers/button.h"

Button::~Button() {

}

void Button::init(int theWidth, int theHeight, int thePositionX, int thePositionY) {

  width = theWidth;
  height = theHeight;
  oldOffset = 0;
  positionX = thePositionX;
  positionY = thePositionY;
  text = "";

  //main color of the button
  color.push_back(1.0);
  color.push_back(.282);
  color.push_back(.302);

  colorChange.push_back(1.0);
  colorChange.push_back(.45);
  colorChange.push_back(.46);

  colorClicked.push_back(.8);
  colorClicked.push_back(.30);
  colorClicked.push_back(.31);

  alpha = 1.0;
  alphaChange = 1.0;
  alphaClicked = 1.0;

  isOnButton = false;
  isClick = false;
  
}

Button::Button() { 

  init(100, 100, 400, 400);

}

Button::Button(string theText, int theWidth, int theHeight, int thePositionX, int thePositionY) {
  
  init(theWidth, theHeight, thePositionX, thePositionY);
  text = theText;

}  

Button::Button(string theText, int theWidth, int theHeight, int thePositionX, int thePositionY, double red,
               double green, double blue, double a, double aCh, double aCl) {
  
  init(theWidth, theHeight, thePositionX, thePositionY);
  setColor(red, green, blue);
  setChangeColor(red, green, blue);
  setClickedColor(red, green, blue);
  alpha = a;
  alphaChange = aCh;
  alphaClicked = aCl;
  text = theText;

}

void Button::draw(int leftScreenX){

  glEnable(GL_BLEND);

  if (isOnButton) {
    if (isClick) {
      glColor4f(colorClicked[0], colorClicked[1], colorClicked[2], alphaClicked);
    }
    else {
      glColor4f(colorChange[0], colorChange[1], colorChange[2], alphaChange);
    }
  }
  else 
    glColor4f(color[0], color[1], color[2], alpha);

  if (leftScreenX != oldOffset) {
    int amountToMovePosition = (oldOffset - leftScreenX);
    positionX += amountToMovePosition;
    oldOffset = leftScreenX;
  }

  glBegin(GL_POLYGON);
  glVertex2f(positionX, positionY);  // upper left
  glVertex2f(positionX, positionY + height);  // lower left
  glVertex2f(positionX + width, positionY + height);  // lower right
  glVertex2f(positionX + width, positionY);  // upper right
  glEnd();

  if(text.length() > 0){//if there is text to draw
    // cout << "drawing text " << text << endl;
    glColor3f(0,0,0);
    drawText(text.c_str(), leftScreenX);
    }
}

void Button::setColor(double red, double green, double blue) {

  color[0] = red;
  color[1] = green;
  color[2] = blue;

}

void Button::setChangeColor(double red, double green, double blue) {

  colorChange[0] = red;
  colorChange[1] = green;
  colorChange[2] = blue;
  
}

void Button::setClickedColor(double red, double green, double blue) {

  colorClicked[0] = red;
  colorClicked[1] = green;
  colorClicked[2] = blue;

}

void Button::setAlpha(double a) {

  alpha = a;

}

void Button::setAlphaChange(double a) {

  alphaChange = a;
  
}

void Button::setAlphaClicked(double a) {

  alphaClicked = a;
  
}

bool Button::isOverButton(int x, int y) {
  if (x > positionX && x < (positionX + width) && y >= positionY && y <= (positionY + height)) {
    isOnButton = true;
  }
  else {
    isOnButton = false;
    isClick = false;
  }
  return isOnButton;

}

bool Button::isClicked(int x, int y) {

  if (x >= positionX && x <= (positionX + width) && y >= positionY && y <= (positionY + height))
    isClick = true;
  else
    isClick = false;

  return isClick;  

}

void Button::offClick() {

  isClick = false;

}

void Button::setPositionX(int thePositionX) {

  positionX = thePositionX;

}

int Button::getPositionX() {

  return positionX;

}

void Button::drawText(string textVal, int leftScreenX) {

  int length = textVal.length();
  int numPixelsOffset = getWidthOfString(textVal);
  int marginTop = 7;//needed in order to fully center vertically
  glRasterPos2f( positionX + (width/2) - (numPixelsOffset / 2), positionY + (height/2) + marginTop);
  const char *text = textVal.c_str();
  for (int i = 0; i < length; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

}
