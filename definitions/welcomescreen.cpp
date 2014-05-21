#include "../headers/welcomescreen.h"

extern int WIDTH;
extern int HEIGHT;


WelcomeScreen::WelcomeScreen(DataController *theDataController) : Screen(theDataController) {

  currentScreen = DEFAULT_SCREEN;
  

}

void WelcomeScreen::draw(bool shouldDrawButtons) {
 
  if (currentScreen == DEFAULT_SCREEN) {
    drawDefaultScreen();

  }
  else if (currentScreen == ABOUT_SCREEN) {
    drawAboutScreen();

  }
  else {
    drawRulesScreen();

  }

  Screen::draw(true);
  
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

  // gluPerspective(60.0, 4.0/3.0, 0, 40);
  // glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
  // gluLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);


  if (buttons.size() == 0) {
  Button startGame ("", 310, 112, 75, 375, 1.0, 1.0, 1.0, 0.0, 0.2, 0.3),
    about ("", 305, 112, 830, 195, 1.0, 1.0, 1.0, 0.0, 0.2, 0.3),
    rules ("", 305, 112, 830, 375, 1.0, 1.0, 1.0, 0.0, 0.2, 0.3);
    
    buttons.push_back(startGame);
    buttons.push_back(about);
    buttons.push_back(rules);
  }

  drawTexture(loadTexture("images/backgrounds/pam/welcomescreen.pam"), 0, 0, WIDTH, HEIGHT);

}

void WelcomeScreen::drawAboutScreen() {


  if (buttons.size() == 0)
    buttons.push_back(Button("", 144, 55, 39, 674, 0.0, 0.0, 0.0, 0.0, 0.25, 0.3));

  drawTexture(loadTexture("images/backgrounds/pam/aboutscreen.pam"), 0, 0, WIDTH, HEIGHT);

}

void WelcomeScreen::drawRulesScreen() {

  if (buttons.size() == 0)
    buttons.push_back(Button("", 144, 55, 39, 674, 0.0, 0.0, 0.0, 0.0, 0.25, 0.3));

  drawTexture(loadTexture("images/backgrounds/pam/rulesscreen.pam"), 0, 0, WIDTH, HEIGHT);
  
}

void WelcomeScreen::removeCurrentButtons() {

  int numButtons = buttons.size();
  for (int z = 0; z < numButtons; z++)
    buttons.erase(buttons.begin());

}

void WelcomeScreen::offButtons() {

  Screen::offButtons();

}

