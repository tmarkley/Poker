#include <cmath>
#include "../headers/mainscreen.h"

extern int WIDTH;
extern int HEIGHT;
extern double pi;
extern double getCurrentTime();

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

  if (currentScreen == MAIN) {
    drawMainScreen();

  }
  else
    drawRulesScreen();

  Screen::draw(true);

}

// Globals for animation
bool changePlayers = false;
bool startDealing = false;
bool doneDealing = false;
bool doneSpreading = false;
bool closeCardFan = false;
bool returnCardsToDealer = false;
bool nextTurnEnabled = false;

double start_time;
double dealing_delay = 0.4;
double animation_duration = 1;
double dealing_duration = 0.25;
double spread_duration = 1;
double close_card_fan_duration = 1;
double return_cards_duration = 1;

double current_time;
double elapsed_time;
double table_orientation = 0;
int current_card = 0;
string tempCards[5];
float winPercentage;

void animateTexture(string card, double x_start, double y_start, double width_start, double height_start, double alpha_start, double rotation_start, double x_end, double y_end, double width_end, double height_end, double alpha_end, double rotation_end, double elapsed_time, double duration, double x_augment = 0, double y_augment = 0, double width_augment = 0, double height_augment = 0, double alpha_augment = 0, double rotation_augment = 0) {
  double x = (x_end-x_start)*(elapsed_time/duration) + x_start + x_augment;
  double y = (y_end-y_start)*(elapsed_time/duration) + y_start + y_augment;
  double width = (width_end-width_start)*(elapsed_time/duration) + width_start + width_augment;
  double height = (height_end-height_start)*(elapsed_time/duration) + height_start + height_augment;
  double alpha = (alpha_end-alpha_start)*(elapsed_time/duration) + alpha_start + alpha_augment;
  double rotation = (rotation_end-rotation_start)*(elapsed_time/duration) + rotation_start + rotation_augment;
  drawTexture(loadTexture(card.c_str()), x, y, width, height, alpha, rotation);
}

void dealCardsAnimation(DataController * dataController, double elapsed_time, int current_card) {
  if (current_card == 15) {
    doneDealing = true;
    doneSpreading = false;
    start_time = getCurrentTime();
    return;
  }
  switch (current_card % 3) {
    case 2: {
      animateTexture("images/cards/large/cardback.pam", 525, -300, 150, 210, 1.0, 0, 1300, 300, 150, 210, 1.0, pi/2, elapsed_time, dealing_duration);
      break;
    }
    case 0: {
      animateTexture("images/cards/large/cardback.pam", 525, -300, 150, 210, 1.0, 0, -200, 300, 150, 210, 1.0, -pi/2, elapsed_time, dealing_duration);
      break;
    }
    case 1: {
      animateTexture("images/cards/large/cardback.pam", 525, -300, 150, 210, 1.0, 0, 525, 850, 150, 210, 1.0, pi, elapsed_time, dealing_duration);
      break;
    }
  }
}

void changePlayersAnimation(DataController * dataController, double elapsed_time) {
  animateTexture("images/backgrounds/pam/maintable.pam", -125, -375, 1450, 1450, 1.0, table_orientation-pi/2, -125, -375, 1450, 1450, 1.0, table_orientation, elapsed_time, spread_duration);
  
  animateTexture("images/cards/large/cardback.pam", 58, 190, 150, 210, 1.0, -pi/2 + pi/8, 270, 430, 200, 280, 0.0, pi/8, elapsed_time, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(0), 58, 190, 150, 210, 0.0, -pi/2 + pi/8, 270, 430, 200, 280, 1.0, pi/8, elapsed_time, animation_duration);
  animateTexture("images/cards/large/cardback.pam", 67, 220, 150, 210, 1.0, -pi/2 + pi/16, 385, 405, 200, 280, 0.0, pi/16, elapsed_time, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(1), 67, 220, 150, 210, 0.0, -pi/2 + pi/16, 385, 405, 200, 280, 1.0, pi/16, elapsed_time, animation_duration);
  animateTexture("images/cards/large/cardback.pam", 70, 250, 150, 210, 1.0, -pi/2, 500, 400, 200, 280, 0.0, 0, elapsed_time, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(2), 70, 250, 150, 210, 0.0, -pi/2, 500, 400, 200, 280, 1.0, 0, elapsed_time, animation_duration);
  animateTexture("images/cards/large/cardback.pam", 55, 280, 150, 210, 1.0, -pi/2 - pi/16, 615, 415, 200, 280, 0.0, -pi/16, elapsed_time, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(3), 55, 280, 150, 210, 0.0, -pi/2 - pi/16, 615, 415, 200, 280, 1.0, -pi/16, elapsed_time, animation_duration);
  animateTexture("images/cards/large/cardback.pam", 40, 310, 150, 210, 1.0, -pi/2 - pi/8, 730, 450, 200, 280, 0.0, -pi/8, elapsed_time, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(4), 40, 310, 150, 210, 0.0, -pi/2 - pi/8, 730, 450, 200, 280, 1.0, -pi/8, elapsed_time, animation_duration);

  animateTexture(tempCards[0], 270, 430, 200, 280, 1.0, pi/8, 992, 310, 150, 210, 0.0, pi/2 + pi/8, elapsed_time, animation_duration);
  animateTexture("images/cards/large/cardback.pam", 270, 430, 200, 280, 0.0, pi/8, 992, 310, 150, 210, 1.0, pi/2 + pi/8, elapsed_time, animation_duration);
  animateTexture(tempCards[1], 385, 405, 200, 280, 1.0, pi/16, 983, 280, 150, 210, 0.0, pi/2 + pi/16, elapsed_time, animation_duration);
  animateTexture("images/cards/large/cardback.pam", 385, 405, 200, 280, 0.0, pi/16, 983, 280, 150, 210, 1.0, pi/2 + pi/16, elapsed_time, animation_duration);
  animateTexture(tempCards[2], 500, 400, 200, 280, 1.0, 0, 980, 250, 150, 210, 0.0, pi/2, elapsed_time, animation_duration);
  animateTexture("images/cards/large/cardback.pam", 500, 400, 200, 280, 0.0, 0, 980, 250, 150, 210, 1.0, pi/2, elapsed_time, animation_duration);
  animateTexture(tempCards[3], 615, 415, 200, 280, 1.0, -pi/16, 995, 220, 150, 210, 0.0, pi/2 - pi/16, elapsed_time, animation_duration);
  animateTexture("images/cards/large/cardback.pam", 615, 415, 200, 280, 0.0, -pi/16, 995, 220, 150, 210, 1.0, pi/2 - pi/16, elapsed_time, animation_duration);
  animateTexture(tempCards[4], 730, 450, 200, 280, 1.0, -pi/8, 1010, 190, 150, 210, 0.0, pi/2 - pi/8, elapsed_time, animation_duration);
  animateTexture("images/cards/large/cardback.pam", 730, 450, 200, 280, 0.0, -pi/8, 1010, 190, 150, 210, 1.0, pi/2 - pi/8, elapsed_time, animation_duration);

  animateTexture("images/cards/large/cardback.pam", 992, 310, 150, 210, 1.0, pi/2 + pi/8, 58, 190, 150, 210, 1.0, -pi/2 + pi/8, elapsed_time, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));
  animateTexture("images/cards/large/cardback.pam", 983, 280, 150, 210, 1.0, pi/2 + pi/16, 67, 220, 150, 210, 1.0, -pi/2 + pi/16, elapsed_time, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));
  animateTexture("images/cards/large/cardback.pam", 980, 250, 150, 210, 1.0, pi/2, 70, 250, 150, 210, 1.0, -pi/2, elapsed_time, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));
  animateTexture("images/cards/large/cardback.pam", 995, 220, 150, 210, 1.0, pi/2 - pi/16, 55, 280, 150, 210, 1.0, -pi/2 - pi/16, elapsed_time, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));
  animateTexture("images/cards/large/cardback.pam", 1010, 190, 150, 210, 1.0, pi/2 - pi/8, 40, 310, 150, 210, 1.0, -pi/2 - pi/8, elapsed_time, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));

}

void spreadCardsAnimation(DataController * dataController, double elapsed_time) {
  animateTexture("images/cards/large/cardback.pam", -200, 300, 150, 210, 1.0, -pi/2, 58, 190, 150, 210, 1.0, -pi/2 + pi/8, elapsed_time, spread_duration);
  animateTexture("images/cards/large/cardback.pam", -200, 300, 150, 210, 1.0, -pi/2, 67, 220, 150, 210, 1.0, -pi/2 + pi/16, elapsed_time, spread_duration);
  animateTexture("images/cards/large/cardback.pam", -200, 300, 150, 210, 1.0, -pi/2, 70, 250, 150, 210, 1.0, -pi/2, elapsed_time, spread_duration);
  animateTexture("images/cards/large/cardback.pam", -200, 300, 150, 210, 1.0, -pi/2, 55, 280, 150, 210, 1.0, -pi/2 - pi/16, elapsed_time, spread_duration);
  animateTexture("images/cards/large/cardback.pam", -200, 300, 150, 210, 1.0, -pi/2, 40, 310, 150, 210, 1.0, -pi/2 - pi/8, elapsed_time, spread_duration);

  animateTexture(dataController->getCurrentPlayersCard(0), 600, 850, 200, 280, 1.0, 0, 270, 430, 200, 280, 1.0, pi/8, elapsed_time, spread_duration);
  animateTexture(dataController->getCurrentPlayersCard(1), 600, 850, 200, 280, 1.0, 0, 385, 405, 200, 280, 1.0, pi/16, elapsed_time, spread_duration);
  animateTexture(dataController->getCurrentPlayersCard(2), 600, 850, 200, 280, 1.0, 0, 500, 400, 200, 280, 1.0, 0, elapsed_time, spread_duration);
  animateTexture(dataController->getCurrentPlayersCard(3), 600, 850, 200, 280, 1.0, 0, 615, 415, 200, 280, 1.0, -pi/16, elapsed_time, spread_duration);
  animateTexture(dataController->getCurrentPlayersCard(4), 600, 850, 200, 280, 1.0, 0, 730, 450, 200, 280, 1.0, -pi/8, elapsed_time, spread_duration);

  animateTexture("images/cards/large/cardback.pam", 1300, 300, 150, 210, 1.0, pi/2, 992, 310, 150, 210, 1.0, pi/2 + pi/8, elapsed_time, spread_duration);
  animateTexture("images/cards/large/cardback.pam", 1300, 300, 150, 210, 1.0, pi/2, 983, 280, 150, 210, 1.0, pi/2 + pi/16, elapsed_time, spread_duration);
  animateTexture("images/cards/large/cardback.pam", 1300, 300, 150, 210, 1.0, pi/2, 980, 250, 150, 210, 1.0, pi/2, elapsed_time, spread_duration);
  animateTexture("images/cards/large/cardback.pam", 1300, 300, 150, 210, 1.0, pi/2, 995, 220, 150, 210, 1.0, pi/2 - pi/16, elapsed_time, spread_duration);
  animateTexture("images/cards/large/cardback.pam", 1300, 300, 150, 210, 1.0, pi/2, 1010, 190, 150, 210, 1.0, pi/2 - pi/8, elapsed_time, spread_duration);
}

void closeCardFanAnimation(DataController * dataController, double elapsed_time) {
  animateTexture("images/cards/large/cardback.pam", 58, 190, 150, 210, 1.0, -pi/2 + pi/8, 70, 250, 150, 210, 1, -pi/2, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 67, 220, 150, 210, 1.0, -pi/2 + pi/16, 70, 250, 150, 210, 1, -pi/2, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 70, 250, 150, 210, 1.0, -pi/2, 70, 250, 150, 210, 1, -pi/2, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 55, 280, 150, 210, 1.0, -pi/2 - pi/16, 70, 250, 150, 210, 1, -pi/2, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 40, 310, 150, 210, 1.0, -pi/2 - pi/8, 70, 250, 150, 210, 1, -pi/2, elapsed_time, close_card_fan_duration);

  animateTexture(tempCards[0], 270, 430, 200, 280, 1, pi/8, 500, 400, 200, 280, 0, 0, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 270, 430, 200, 280, 0, pi/8, 500, 400, 200, 280, 1, 0, elapsed_time, close_card_fan_duration);
  animateTexture(tempCards[1], 385, 405, 200, 280, 1, pi/16, 500, 400, 200, 280, 0, 0, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 385, 405, 200, 280, 0, pi/16, 500, 400, 200, 280, 1, 0, elapsed_time, close_card_fan_duration);
  animateTexture(tempCards[2], 500, 400, 200, 280, 1, 0, 500, 400, 200, 280, 0, 0, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 500, 400, 200, 280, 0, 0, 500, 400, 200, 280, 1, 0, elapsed_time, close_card_fan_duration);
  animateTexture(tempCards[3], 615, 415, 200, 280, 1, -pi/16, 500, 400, 200, 280, 0, 0, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 615, 415, 200, 280, 0, -pi/16, 500, 400, 200, 280, 1, 0, elapsed_time, close_card_fan_duration);
  animateTexture(tempCards[4], 730, 450, 200, 280, 1, -pi/8, 500, 400, 200, 280, 0, 0, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 730, 450, 200, 280, 0, -pi/8, 500, 400, 200, 280, 1, 0, elapsed_time, close_card_fan_duration);

  animateTexture("images/cards/large/cardback.pam", 992, 310, 150, 210, 1.0, pi/2 + pi/8, 980, 250, 150, 210, 1, pi/2, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 983, 280, 150, 210, 1.0, pi/2 + pi/16, 980, 250, 150, 210, 1, pi/2, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 980, 250, 150, 210, 1.0, pi/2, 980, 250, 150, 210, 1, pi/2, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 995, 220, 150, 210, 1.0, pi/2 - pi/16, 980, 250, 150, 210, 1, pi/2, elapsed_time, close_card_fan_duration);
  animateTexture("images/cards/large/cardback.pam", 1010, 190, 150, 210, 1.0, pi/2 - pi/8, 980, 250, 150, 210, 1, pi/2, elapsed_time, close_card_fan_duration);
}

void returnCardsAnimation(DataController * dataController, double elapsed_time) {
  animateTexture("images/cards/large/cardback.pam", 70, 250, 150, 210, 1, -pi/2, 525, -300, 150, 210, 1, 0, elapsed_time, close_card_fan_duration);

  animateTexture("images/cards/large/cardback.pam", 500, 400, 200, 280, 1, 0, 525, -300, 150, 210, 1, 0, elapsed_time, close_card_fan_duration);

  animateTexture("images/cards/large/cardback.pam", 980, 250, 150, 210, 1, pi/2, 525, -300, 150, 210, 1, 0, elapsed_time, close_card_fan_duration);
}

void drawCardsToScreen(DataController * dataController) {
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
}

void setTime() {
  current_time = getCurrentTime();
  elapsed_time = current_time - start_time;
}

void storeCards(DataController * dataController) {
  for (int i = 0; i < 5; ++i) {
    tempCards[i] = dataController->getCurrentPlayersCard(i);
  }
}

void MainScreen::drawMainScreen() {

  if (buttons.size() == 0) {
    buttons.push_back(Button("", 230, 85, 20, 19, 0.098, 0.694, 0.173, 0.0, 0.2, 0.3));
    buttons.push_back(Button("", 230, 85, 952, 19, 0.098, 0.694, 0.173, 0.0, 0.2, 0.3));
  }

  drawTexture(loadTexture("images/backgrounds/pam/maintable.pam"), -125, -375, 1450, 1450, 1, table_orientation);
  
  if (!startDealing) {
    setTime();
    if (elapsed_time < dealing_delay) {
    }
    else {
      startDealing = true;
      doneDealing = false;
      start_time = getCurrentTime();
    }
    glutPostRedisplay();
  }
  else if (!doneDealing) {
    setTime();
    if ((elapsed_time < dealing_duration) && !doneDealing) {
      dealCardsAnimation(dataController, elapsed_time, current_card);
    }
    else {
      ++current_card; 
      start_time = getCurrentTime();
      setTime();
      dealCardsAnimation(dataController, elapsed_time, current_card);
    }
    glutPostRedisplay();
  }
  else if (!doneSpreading) {
    setTime();
    if (elapsed_time < spread_duration) {
      spreadCardsAnimation(dataController, elapsed_time);
    }
    else {
      doneSpreading = true;
      nextTurnEnabled = true;
      spreadCardsAnimation(dataController, elapsed_time);
      winPercentage = rand() % 100000;
      winPercentage /= 1000.0;
      // dataController->getCurrentPlayersHand().printHand();
      // dataController->getCurrentPlayersHand().findBestHand();
      // cout << dataController->getCurrentPlayersHand().getBestHand() << ", with rank " << dataController->getCurrentPlayersHand().getHandRank(4) << endl;
    }
    glutPostRedisplay();
  }
  else if (closeCardFan) {
    setTime();
    if (elapsed_time < close_card_fan_duration) {
      closeCardFanAnimation(dataController, elapsed_time);
    }
    else {
      closeCardFan = false;
      closeCardFanAnimation(dataController, elapsed_time);
      returnCardsToDealer = true;
      start_time = getCurrentTime();
    }
    glutPostRedisplay();
  }
  else if (returnCardsToDealer) {
    setTime();
    if (elapsed_time < return_cards_duration) {
      returnCardsAnimation(dataController, elapsed_time);
    }
    else {
      changePlayers = false;
      returnCardsToDealer = false;
      startDealing = false;
      current_card = 0;
      start_time = getCurrentTime();
      returnCardsAnimation(dataController, elapsed_time);
    }
    glutPostRedisplay();
  }
  else if (changePlayers) {
    setTime();
    if (elapsed_time < animation_duration) {
      changePlayersAnimation(dataController, elapsed_time);
    }
    else {
      nextTurnEnabled = true;
      changePlayers = false;
      drawCardsToScreen(dataController);
    }
    glutPostRedisplay();
  }
  else {

    drawCardsToScreen(dataController);

    drawTexture(loadTexture(dataController->getCurrentChip().c_str()), 990, 610, 140, 140, 1.0, pi/dataController->getChipRotation());

    drawLargestText(dataController->getCurrentPlayersName(), 1010, 550);

    char buff[20];
    long money = dataController->getCurrentPlayersCurrencyMoneysAndShit();
    sprintf(buff, "%ld", money);
    drawNumbers(buff, strlen(buff), 1020, 570, 0.6, false);

    char buff2[10];
    // float winPercentage = rand() % 100000;
    // winPercentage /= 1000.0;
    sprintf(buff2, "%.2f", winPercentage);
    drawNumbers(buff2, strlen(buff2), 552, 300, 1, true);
  }
  drawTexture(loadTexture("images/backgrounds/pam/mainoverlay.pam"), 0, 0, 1200, 750);
      
  // glutPostRedisplay();

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
      if (nextTurnEnabled) {
        
        dataController->getCurrentPlayersHand().findBestHand();
        storeCards(dataController);
        dataController->nextPlayer();
        start_time = getCurrentTime();
        table_orientation += pi/2;
        changePlayers = true;
        nextTurnEnabled = false;
        winPercentage = rand() % 100000;
        winPercentage /= 1000.0;
        // dataController->getCurrentPlayersHand().printHand();
        // cout << dataController->getCurrentPlayersHand().getBestHand() << ", with rank " << dataController->getCurrentPlayersHand().getHandRank(4) << endl;
      }
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
