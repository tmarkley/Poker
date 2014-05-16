#ifndef _WELCOMESCREEN_
#define _WELCOMESCREEN_

#include <iostream>
#include <string>

using namespace std;

#include "screen.h"
#include "button.h"
#include "texture.h"

enum AlternateScreens {DEFAULT_SCREEN, ABOUT_SCREEN, RULES_SCREEN};

class WelcomeScreen : public Screen {

  AlternateScreens currentScreen;

 public:
  WelcomeScreen(DataController *theDataController);
  void draw(bool shoulDrawButtons = true);

  //virtual functions
  int didClickButton(int x, int y);
  void offButtons();

 private:
  void drawDefaultScreen();
  void drawAboutScreen();
  void drawRulesScreen();
  void removeCurrentButtons();
};

#endif //_WELCOMESCREEN_
