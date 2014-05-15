#ifndef _BUTTON_
#define _BUTTON_

#include "texture.h"
#include <string>
#include <vector>

using namespace std;

class Button {

  string text;
  
  int height;
  int width;
  int oldOffset;
  int positionX;
  int positionY;
  // int textureId;
  vector<double> color;
  vector<double> colorChange;
  vector<double> colorClicked;
  double alpha;
  double alphaChange;
  double alphaClicked;
  bool isOnButton;
  bool isClick;

 public:
  
   //creates a button with both and image and text and the specified width and height
  Button(string, int, int, int, int, double, double, double, double, double, double);
  Button(string theText, int width, int height, int positionX, int positionY);
  Button();
  //will draw the buttons that you need from the index you specify as the start index up to the index you specify as the endIndex
  void draw(int leftScreenX = 0);
  bool isOverButton(int x, int y);
  bool isClicked(int x, int y);
  void offClick();
  void setChangeColor(double red, double green, double blue);
  void setColor(double red, double green, double blue);
  void setClickedColor(double red, double green, double blue);
  void setAlpha(double a);
  void setAlphaChange(double a);
  void setAlphaClicked(double a);
  void setPositionX(int thePositionX);
  int getPositionX();
  void drawText(string textVal, int leftScreenX);
  ~Button();

 private:
  void init(int theWidth, int theHeight, int thePositionX, int thePositionY);

};

#endif// _BUTTON_
