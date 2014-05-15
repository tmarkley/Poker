#include <string.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "welcomescreen.h"
#include "button.h"
#include "texture.h"
#include <iostream>

using namespace std;

WelcomeScreen::WelcomeScreen(DataController *theDataController) : Screen(theDataController) {

  currentScreen = DEFAULT_SCREEN;
  

}

void WelcomeScreen::draw(bool shouldDrawButtons) {
 
  Screen::draw(false);

  if (currentScreen == DEFAULT_SCREEN) {
    drawDefaultScreen();

  }
  else if (currentScreen == ABOUT_SCREEN) {
    drawAboutScreen();

  }
  else {
    drawRulesScreen();

  }

  
  if (buttons.size() != 0)
    Screen::drawButtons(0, buttons.size() - 1);
  
}

int WelcomeScreen::didClickButton(int x, int y) {
  int buttonClicked =  Screen::didClickButton(x, y);
  AlternateScreens theCurrentScreen = currentScreen;

  if (currentScreen == DEFAULT_SCREEN) {

    if (buttonClicked == 0) {
      return 1;//return one cause want to advance to next screen in main class
    }
    else if (buttonClicked == 1) {
      currentScreen = ABOUT_SCREEN;
    }
    else if (buttonClicked == 2) {
      currentScreen = RULES_SCREEN;
    }

  }
  else if (currentScreen == ABOUT_SCREEN) {
    if (buttonClicked == 0)
      currentScreen = DEFAULT_SCREEN;
  }
  else {
 
    if (buttonClicked == 0) {
      currentScreen = DEFAULT_SCREEN;
    }

  }

  if (currentScreen != theCurrentScreen)
    removeCurrentButtons();


  return -1; //else return negative one because nothing was clicked that the main class needs to be concerned with

}

void WelcomeScreen::drawDefaultScreen() {

  if (buttons.size() == 0) {
  Button startGame ("", 310, 112, 75, 375, 1.0, 1.0, 1.0, 0.0, 0.2, 0.3),
    about ("", 305, 112, 830, 195, 1.0, 1.0, 1.0, 0.0, 0.2, 0.3),
    rules ("", 305, 112, 830, 375, 1.0, 1.0, 1.0, 0.0, 0.2, 0.3);
    
    buttons.push_back(startGame);
    buttons.push_back(about);
    buttons.push_back(rules);
  }

  drawTexture(loadTexture("backgrounds/welcomescreen.pam"), 0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

}

void WelcomeScreen::drawAboutScreen() {


  if (buttons.size() == 0)
    buttons.push_back(Button("", 285, 85, 40, 650, 0.0, 0.0, 0.0, 0.0, 0.2, 0.3));

  drawTexture(loadTexture("backgrounds/aboutscreen.pam"), 0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

}

void WelcomeScreen::drawRulesScreen() {

  if (buttons.size() == 0)
    buttons.push_back(Button("", 285, 85, 40, 650, 0.0, 0.0, 0.0, 0.0, 0.2, 0.3));

  drawTexture(loadTexture("backgrounds/rulesscreen.pam"), 0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
  
}

void WelcomeScreen::removeCurrentButtons() {

  int numButtons = buttons.size();
  for (int z = 0; z < numButtons; z++)
    buttons.erase(buttons.begin());

}

void WelcomeScreen::offButtons() {

  Screen::offButtons();

}

