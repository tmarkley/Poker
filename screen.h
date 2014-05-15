#ifndef _SCREEN_
#define _SCREEN_

#include "button.h"
#include "drawingfunctions.h"
#include "datacontroller.h"

class Screen {
  
 // bool alertButtonIsAdded;//used to make sure the button for the alert button is only added once
 // bool textBoxButtonIsAdded;
 // bool isOverTextBox;

 protected:
  vector<Button> buttons;
  vector<double> backgroundColor;
  // bool hasTycoonLogo;
  DataController *dataController;
  // bool alertDialogShouldShow;
  // string alertDialogMessage;
  // bool textBoxShouldShow;
  // string textBoxMessage;
  // string textInBox;
  // string lastTextInBox;
  // double currentTime;
  
 public:
  Screen(DataController *theDataController);//creates a screen with the default background color (blue) and either a tycoon logo or not depending
  Screen(double red, double green, double blue, DataController *theDataController);//creates a screen with specified background color and defaults to no tycoon logo on top
  virtual void draw(bool shouldDrawButtons=true);
  virtual void isOnButton(int x, int y);
  virtual int didClickButton(int x, int y);
  void offButtons();
  // void setTextBoxText(unsigned char theChar);
  // void setCurrentTime(double theCurrentTime);

 protected:
  void drawButtons(int startIndex, int endIndexint, int leftScreenX = 0);
  // void drawAlertDialog();//put this at the end of the subclass draw method if want alerts enabled - then make alertDialogShouldShow true when want it to display whatever you put in alertDialogMessage
  // void drawTextBox();
  // string getLastTextInBox();

 private:
  void init(double red, double green, double blue, DataController *theDataController);

};

#endif
