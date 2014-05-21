#ifndef _MAINSCREEN_
#define _MAINSCREEN_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "screen.h"
#include "datacontroller.h"
#include "drawingfunctions.h"
#include "button.h"
#include "texture.h"

using namespace std;

enum Screens {MAIN, RULES};

class MainScreen : public Screen {

  Screens currentScreen;

 public:
  MainScreen(DataController *theDataController);
  void draw(bool shouldDrawButtons = true);

  //virtual functions
  void isOnButton(int x, int y);
  int didClickButton(int x, int y);
  void offButtons();
  static void drawText(string, int, int, float, float);

 private:
  void drawMainScreen();
  void drawRulesScreen();
  void drawNumbers(char s[], int, int, int, float, bool);
  void removeCurrentButtons();

};

#endif //_MAINSCREEN_
