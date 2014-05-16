#include "../headers/mainscreen.h"

extern int WIDTH;
extern int HEIGHT;
extern double pi;

MainScreen::MainScreen(DataController *theDataController) : Screen(theDataController) {

  currentScreen = MAIN;

  // currentBuildingOptionsIndex = 0;
  // numButtonsAddedForMenu = 0;
  // leftScreenPositionX = 0;
  // currentMenu = NONE;
  // totalTime = 0;
  // currentWarningMessageIndex = 0;

  // int iconBarButtonWidth = 120;
  // int iconBarButtonHeight = 100;
  // int leftX =(850 - (5 * iconBarButtonWidth)) / 2;//this is created by centering the icon bar assuming five buttons

  // numButtons = 0;
  // Button money("", iconBarButtonWidth, iconBarButtonHeight, leftX, 650 - iconBarButtonHeight),
  //   building("", iconBarButtonWidth, iconBarButtonHeight, leftX + iconBarButtonWidth, 650 - iconBarButtonHeight),
  //   professor("", iconBarButtonWidth, iconBarButtonHeight, leftX + (2*iconBarButtonWidth), 650 - iconBarButtonHeight),
  //   entertainment("", iconBarButtonWidth, iconBarButtonHeight, leftX + (3*iconBarButtonWidth), 650 - iconBarButtonHeight),
  //   food("", iconBarButtonWidth, iconBarButtonHeight, leftX + (4*iconBarButtonWidth), 650 - iconBarButtonHeight);

  // buttons.push_back(money);
  // buttons.push_back(building);
  // buttons.push_back(professor);
  // buttons.push_back(entertainment);
  // buttons.push_back(food);

    //change the color of the buttons so it looks like a background bar
  // for (int x = 0; x < numButtons; x ++) {

  //   buttons[x].setColor(.7, .7, .7);
  //   buttons[x].setChangeColor(.8, .8, .8);
  //   buttons[x].setClickedColor(.5, .5, .5);

  // }

}

void MainScreen::draw(bool shouldDrawButtons) {

  Screen::draw(false);

  if (currentScreen == MAIN) {
    drawMainScreen();

  }
  else
    drawRulesScreen();

  if (buttons.size() != 0)
    Screen::drawButtons(0, buttons.size() - 1);

}

void MainScreen::drawMainScreen() {

  if (buttons.size() == 0) {
    buttons.push_back(Button("", 230, 85, 20, 19, 0.098, 0.694, 0.173, 0.0, 0.2, 0.3));
    buttons.push_back(Button("", 230, 85, 952, 19, 0.098, 0.694, 0.173, 0.0, 0.2, 0.3));
  }

  drawTexture(loadTexture("images/backgrounds/pam/mainscreen.pam"), 0, 0, 1200, 750);

  drawTexture(loadTexture("images/cards/large/cardback.pam"), 58, 190, 150, 210, 1.0, -pi/2 + pi/8);
  drawTexture(loadTexture("images/cards/large/cardback.pam"), 67, 220, 150, 210, 1.0, -pi/2 + pi/16);
  drawTexture(loadTexture("images/cards/large/cardback.pam"), 70, 250, 150, 210, 1.0, -pi/2);
  drawTexture(loadTexture("images/cards/large/cardback.pam"), 55, 280, 150, 210, 1.0, -pi/2 - pi/16);
  drawTexture(loadTexture("images/cards/large/cardback.pam"), 40, 310, 150, 210, 1.0, -pi/2 - pi/8);

  drawTexture(loadTexture(dataController->getCurrentPlayersCard(0).c_str()), 270, 430, 200, 280, 1.0, pi/8);
  drawTexture(loadTexture(dataController->getCurrentPlayersCard(1).c_str()), 385, 405, 200, 280, 1.0, pi/16);
  drawTexture(loadTexture(dataController->getCurrentPlayersCard(2).c_str()), 500, 400, 200, 280);
  drawTexture(loadTexture(dataController->getCurrentPlayersCard(3).c_str()), 615, 415, 200, 280, 1.0, -pi/16);
  drawTexture(loadTexture(dataController->getCurrentPlayersCard(4).c_str()), 730, 450, 200, 280, 1.0, -pi/8);

  drawTexture(loadTexture("images/cards/large/cardback.pam"), 992, 310, 150, 210, 1.0, pi/2 + pi/8);
  drawTexture(loadTexture("images/cards/large/cardback.pam"), 983, 280, 150, 210, 1.0, pi/2 + pi/16);
  drawTexture(loadTexture("images/cards/large/cardback.pam"), 980, 250, 150, 210, 1.0, pi/2);
  drawTexture(loadTexture("images/cards/large/cardback.pam"), 995, 220, 150, 210, 1.0, pi/2 - pi/16);
  drawTexture(loadTexture("images/cards/large/cardback.pam"), 1010, 190, 150, 210, 1.0, pi/2 - pi/8);

  drawTexture(loadTexture(dataController->getCurrentChip().c_str()), 990, 610, 140, 140, 1.0, pi/dataController->getChipRotation());

  char buff[20];
  long money = dataController->getCurrentPlayersCurrencyMoneysAndShit();
  sprintf(buff, "%ld", money);
  drawNumbers(buff, strlen(buff), 1020, 570, 0.6, false);

  char buff2[10];
  float number = 6.91;
  sprintf(buff2, "%.2f", number);
  drawNumbers(buff2, strlen(buff2), 552, 300, 1, true);

}

void MainScreen::drawNumbers(char s[], int length, int x, int y, float scale, bool drawPercent) {

  int xLocation = x - (28*scale)*(length+1)/2;
  int spacing = 33*scale;

  int i = 0;
  if (!drawPercent) {
    drawTexture(loadTexture("images/numbers/pam/dolla.pam"), xLocation+spacing, y+1, 42*scale, 70*scale);
    xLocation += spacing+10;
  }

  while(s[i] != '\0') {
    string temp = "images/numbers/pam/";
    xLocation = xLocation + spacing;
    if (s[i] == '.') {
      temp += "period.pam";
      drawTexture(loadTexture(temp.c_str()), xLocation, y, 16*scale, 70*scale);
      i++;
      spacing = 19*scale;
      continue;
    }
    else if (s[i] == '1') { // damn 1
      temp += s[i];
      temp += ".pam";
      drawTexture(loadTexture(temp.c_str()), xLocation, y+(11*scale), 22*scale, 70*scale);
      i++;
      spacing = 28*scale;
    }
    else if (s[i] == '6') { // fuck
      temp += s[i];
      temp += ".pam";
      drawTexture(loadTexture(temp.c_str()), xLocation, y+(3*scale), 30*scale, 70*scale);
      i++;
      spacing = 33*scale;
    }
    else {
      temp += s[i];
      temp += ".pam";

      drawTexture(loadTexture(temp.c_str()), xLocation, y, 30*scale, 70*scale);
      i++;
      spacing = 33*scale;
    }
  }
  
  if (drawPercent)
    drawTexture(loadTexture("images/numbers/pam/percent.pam"), xLocation+spacing, y, 42*scale, 70*scale);

}

void MainScreen::drawRulesScreen() {

  if (buttons.size() == 0)
    buttons.push_back(Button("", 285, 85, 40, 650, 0.0, 0.0, 0.0, 0.0, 0.2, 0.3));

  drawTexture(loadTexture("images/backgrounds/pam/rulesscreen.pam"), 0, 0, WIDTH, HEIGHT);
  
}

int MainScreen::didClickButton(int x, int y) {

  int buttonClicked =  Screen::didClickButton(x, y);
  Screens theCurrentScreen = currentScreen;

  if (currentScreen == MAIN) {

    if (buttonClicked == 0) {
      currentScreen = RULES;
    }
    if (buttonClicked == 1) {
      dataController->nextPlayer();
    }
  }
  else {
 
    if (buttonClicked == 0) {
      currentScreen = MAIN;
    }

  }

  if (currentScreen != theCurrentScreen)
    removeCurrentButtons();

  return -1;
}

void MainScreen::removeCurrentButtons() {

  int numButtons = buttons.size();
  for (int z = 0; z < numButtons; z++)
    buttons.erase(buttons.begin());

}

void MainScreen::isOnButton(int x, int y) {

  Screen::isOnButton(x, y);
  
  //get the position of the right side of the most right building the user has
  // vector<Building*> theBuildings = dataController->getBuildings();
  
  // int mostRightBuildingPosition;
  // if (theBuildings.empty())
  //   mostRightBuildingPosition = 0;
  // else
  //   mostRightBuildingPosition = theBuildings[theBuildings.size() - 1]->getPositionX() + theBuildings[theBuildings.size() - 1]->getWidth();

  // //if the screen can go to the right anymore without going past the last building, move it
  // if (x > 800 && leftScreenPositionX + 850 < mostRightBuildingPosition) {
  //   leftScreenPositionX += 5;
  // }
  // //if the screen can go to the left anymore without going past the last building, move it
  // if (x < 50 && leftScreenPositionX > 0) {
  //   leftScreenPositionX -= 5;
  //   }
}

void MainScreen::offButtons() {

  Screen::offButtons();

}
