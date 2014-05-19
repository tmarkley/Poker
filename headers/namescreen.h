#ifndef _NAMESCREEN_
#define _NAMESCREEN_
#include <iostream>
#include <string>

using namespace std;

#include "screen.h"
#include "button.h"
#include "texture.h"

class NameScreen : public Screen {

  vector<string> textInBox;
  vector<bool> isOverTextBox;
  vector<bool> textBoxIsClicked;
  bool nameError;
  
 public:
  NameScreen(DataController *theDataController);
  void draw(bool shouldDrawButtons = true);
  void drawTextBoxes(int);
  void isOnTextBoxes(int, int);
  void setTextBoxText(unsigned char);
  void nextTextBox();

  //virtual functions
  int didClickButton(int x, int y);
  void offButtons();
};

#endif //_NAMESCREEN_
