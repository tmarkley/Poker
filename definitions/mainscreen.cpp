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
bool waitForDeal = true;
bool stillDealing = false;
bool openCardFan = false;
bool closeWinningCards = false;
bool returnCardsToDealer = false;
bool nextTurnEnabled = false;
bool rotateTable = false;
bool displayWinner = false;
bool waitForNextClick = false;

double start_time;
double dealing_delay = 0.4;
double animation_duration = 1.25;
double dealing_duration = 0.15;
double spread_duration = 1;
double close_winning_cards_duration = 0.75;
double return_cards_duration = 0.5;
double rotation_duration = 1;
double winning_hand_duration = 1;

double current_time;
double elapsed_time;
double table_orientation = 0;
int current_card = 0;
int player_num = 0;
string tempCards[5];
string tempCards2[5];
string cardBack = "images/cards/large/cardback.pam";
float winPercentage;
int winner;
// float winPercentage;

void animateTexture(string card, double x_start, double y_start, double width_start, double height_start, double alpha_start, double rotation_start, double x_end, double y_end, double width_end, double height_end, double alpha_end, double rotation_end, double duration, double x_augment = 0, double y_augment = 0, double width_augment = 0, double height_augment = 0, double alpha_augment = 0, double rotation_augment = 0) {
  double x = (x_end-x_start)*(elapsed_time/duration) + x_start + x_augment;
  double y = (y_end-y_start)*(elapsed_time/duration) + y_start + y_augment;
  double width = (width_end-width_start)*(elapsed_time/duration) + width_start + width_augment;
  double height = (height_end-height_start)*(elapsed_time/duration) + height_start + height_augment;
  double alpha = (alpha_end-alpha_start)*(elapsed_time/duration) + alpha_start + alpha_augment;
  double rotation = (rotation_end-rotation_start)*(elapsed_time/duration) + rotation_start + rotation_augment;
  drawTexture(loadTexture(card.c_str()), x, y, width, height, alpha, rotation);
}

void dealCardsAnimation(DataController * dataController, int current_card) {
  if (current_card == 15) {
    stillDealing = false;
    openCardFan = true;
    start_time = getCurrentTime();
    return;
  }
  switch (current_card % 3) {
    case 2: {
      animateTexture(cardBack, 525, -300, 150, 210, 1, 0, 1300, 300, 150, 210, 1, pi/2, dealing_duration);
      break;
    }
    case 0: {
      animateTexture(cardBack, 525, -300, 150, 210, 1, 0, -200, 300, 150, 210, 1, -pi/2, dealing_duration);
      break;
    }
    case 1: {
      animateTexture(cardBack, 525, -300, 150, 210, 1, 0, 525, 850, 150, 210, 1, pi, dealing_duration);
      break;
    }
  }
}

void changePlayersAnimation(DataController * dataController) {
  animateTexture("images/backgrounds/pam/maintable.pam", -125, -375, 1450, 1450, 1, table_orientation-pi/2, -125, -375, 1450, 1450, 1, table_orientation, animation_duration);
  
  animateTexture(cardBack, 58, 190, 150, 210, 1, -pi/2 + pi/8, 270, 430, 200, 280, 0, pi/8, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(0), 58, 190, 150, 210, 0, -pi/2 + pi/8, 270, 430, 200, 280, 1, pi/8, animation_duration);
  animateTexture(cardBack, 67, 220, 150, 210, 1, -pi/2 + pi/16, 385, 405, 200, 280, 0, pi/16, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(1), 67, 220, 150, 210, 0, -pi/2 + pi/16, 385, 405, 200, 280, 1, pi/16, animation_duration);
  animateTexture(cardBack, 70, 250, 150, 210, 1, -pi/2, 500, 400, 200, 280, 0, 0, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(2), 70, 250, 150, 210, 0, -pi/2, 500, 400, 200, 280, 1, 0, animation_duration);
  animateTexture(cardBack, 55, 280, 150, 210, 1, -pi/2 - pi/16, 615, 415, 200, 280, 0, -pi/16, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(3), 55, 280, 150, 210, 0, -pi/2 - pi/16, 615, 415, 200, 280, 1, -pi/16, animation_duration);
  animateTexture(cardBack, 40, 310, 150, 210, 1, -pi/2 - pi/8, 730, 450, 200, 280, 0, -pi/8, animation_duration);
  animateTexture(dataController->getCurrentPlayersCard(4), 40, 310, 150, 210, 0, -pi/2 - pi/8, 730, 450, 200, 280, 1, -pi/8, animation_duration);

  animateTexture(tempCards[0], 270, 430, 200, 280, 1, pi/8, 992, 310, 150, 210, 0, pi/2 + pi/8, animation_duration);
  animateTexture(cardBack, 270, 430, 200, 280, 0, pi/8, 992, 310, 150, 210, 1, pi/2 + pi/8, animation_duration);
  animateTexture(tempCards[1], 385, 405, 200, 280, 1, pi/16, 983, 280, 150, 210, 0, pi/2 + pi/16, animation_duration);
  animateTexture(cardBack, 385, 405, 200, 280, 0, pi/16, 983, 280, 150, 210, 1, pi/2 + pi/16, animation_duration);
  animateTexture(tempCards[2], 500, 400, 200, 280, 1, 0, 980, 250, 150, 210, 0, pi/2, animation_duration);
  animateTexture(cardBack, 500, 400, 200, 280, 0, 0, 980, 250, 150, 210, 1, pi/2, animation_duration);
  animateTexture(tempCards[3], 615, 415, 200, 280, 1, -pi/16, 995, 220, 150, 210, 0, pi/2 - pi/16, animation_duration);
  animateTexture(cardBack, 615, 415, 200, 280, 0, -pi/16, 995, 220, 150, 210, 1, pi/2 - pi/16, animation_duration);
  animateTexture(tempCards[4], 730, 450, 200, 280, 1, -pi/8, 1010, 190, 150, 210, 0, pi/2 - pi/8, animation_duration);
  animateTexture(cardBack, 730, 450, 200, 280, 0, -pi/8, 1010, 190, 150, 210, 1, pi/2 - pi/8, animation_duration);

  animateTexture(cardBack, 992, 310, 150, 210, 1, pi/2 + pi/8, 58, 190, 150, 210, 1, -pi/2 + pi/8, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));
  animateTexture(cardBack, 983, 280, 150, 210, 1, pi/2 + pi/16, 67, 220, 150, 210, 1, -pi/2 + pi/16, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));
  animateTexture(cardBack, 980, 250, 150, 210, 1, pi/2, 70, 250, 150, 210, 1, -pi/2, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));
  animateTexture(cardBack, 995, 220, 150, 210, 1, pi/2 - pi/16, 55, 280, 150, 210, 1, -pi/2 - pi/16, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));
  animateTexture(cardBack, 1010, 190, 150, 210, 1, pi/2 - pi/8, 40, 310, 150, 210, 1, -pi/2 - pi/8, animation_duration, 0, -250*sin((elapsed_time/animation_duration)*pi));
    drawTexture(loadTexture("images/backgrounds/pam/header.pam"), 0, 0, 1200, 750);
}

void spreadCardsAnimation(DataController * dataController) {
  animateTexture(cardBack, -200, 300, 150, 210, 1, -pi/2, 58, 190, 150, 210, 1, -pi/2 + pi/8, spread_duration);
  animateTexture(cardBack, -200, 300, 150, 210, 1, -pi/2, 67, 220, 150, 210, 1, -pi/2 + pi/16, spread_duration);
  animateTexture(cardBack, -200, 300, 150, 210, 1, -pi/2, 70, 250, 150, 210, 1, -pi/2, spread_duration);
  animateTexture(cardBack, -200, 300, 150, 210, 1, -pi/2, 55, 280, 150, 210, 1, -pi/2 - pi/16, spread_duration);
  animateTexture(cardBack, -200, 300, 150, 210, 1, -pi/2, 40, 310, 150, 210, 1, -pi/2 - pi/8, spread_duration);

  animateTexture(dataController->getCurrentPlayersCard(0), 600, 850, 200, 280, 1, 0, 270, 430, 200, 280, 1, pi/8, spread_duration);
  animateTexture(dataController->getCurrentPlayersCard(1), 600, 850, 200, 280, 1, 0, 385, 405, 200, 280, 1, pi/16, spread_duration);
  animateTexture(dataController->getCurrentPlayersCard(2), 600, 850, 200, 280, 1, 0, 500, 400, 200, 280, 1, 0, spread_duration);
  animateTexture(dataController->getCurrentPlayersCard(3), 600, 850, 200, 280, 1, 0, 615, 415, 200, 280, 1, -pi/16, spread_duration);
  animateTexture(dataController->getCurrentPlayersCard(4), 600, 850, 200, 280, 1, 0, 730, 450, 200, 280, 1, -pi/8, spread_duration);

  animateTexture(cardBack, 1300, 300, 150, 210, 1, pi/2, 992, 310, 150, 210, 1, pi/2 + pi/8, spread_duration);
  animateTexture(cardBack, 1300, 300, 150, 210, 1, pi/2, 983, 280, 150, 210, 1, pi/2 + pi/16, spread_duration);
  animateTexture(cardBack, 1300, 300, 150, 210, 1, pi/2, 980, 250, 150, 210, 1, pi/2, spread_duration);
  animateTexture(cardBack, 1300, 300, 150, 210, 1, pi/2, 995, 220, 150, 210, 1, pi/2 - pi/16, spread_duration);
  animateTexture(cardBack, 1300, 300, 150, 210, 1, pi/2, 1010, 190, 150, 210, 1, pi/2 - pi/8, spread_duration);
}

void displayWinnerAnimation(DataController * dataController) {
  // cout << "winnerfunc: " << winner << endl;
  if (winner == 0) { 
    animateTexture(dataController->getPlayersCard(2, 0), 270, 430, 200, 280, 1, pi/8, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 270, 430, 200, 280, 0, pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(2, 1), 385, 405, 200, 280, 1, pi/16, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 385, 405, 200, 280, 0, pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(2, 2), 500, 400, 200, 280, 1, 0, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 500, 400, 200, 280, 0, 0, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(2, 3), 615, 415, 200, 280, 1, -pi/16, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 615, 415, 200, 280, 0, -pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(2, 4), 730, 450, 200, 280, 1, -pi/8, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 730, 450, 200, 280, 0, -pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);

    animateTexture(cardBack, 992, 310, 150, 210, 1, pi/2 + pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 983, 280, 150, 210, 1, pi/2 + pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 980, 250, 150, 210, 1, pi/2, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 995, 220, 150, 210, 1, pi/2 - pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 1010, 190, 150, 210, 1, pi/2 - pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    
    animateTexture(cardBack, 58, 190, 150, 210, 1, -pi/2 + pi/8, 100, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 0), 58, 190, 150, 210, 0, -pi/2 + pi/8, 100, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 67, 220, 150, 210, 1, -pi/2 + pi/16, 300, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 1), 67, 220, 150, 210, 1, -pi/2 + pi/16, 300, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 70, 250, 150, 210, 1, -pi/2, 500, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 2), 70, 250, 150, 210, 1, -pi/2, 500, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 55, 280, 150, 210, 1, -pi/2 - pi/16, 700, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 3), 55, 280, 150, 210, 1, -pi/2 - pi/16, 700, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 40, 310, 150, 210, 1, -pi/2 - pi/8, 900, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 4), 40, 310, 150, 210, 1, -pi/2 - pi/8, 900, 275, 200, 280, 1, 0, winning_hand_duration);
  }
  else if (winner == 1) {
    animateTexture(cardBack, 58, 190, 150, 210, 1, -pi/2 + pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 67, 220, 150, 210, 1, -pi/2 + pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 70, 250, 150, 210, 1, -pi/2, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 55, 280, 150, 210, 1, -pi/2 - pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 40, 310, 150, 210, 1, -pi/2 - pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);

    animateTexture(dataController->getPlayersCard(2, 0), 270, 430, 200, 280, 1, pi/8, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 270, 430, 200, 280, 0, pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(2, 1), 385, 405, 200, 280, 1, pi/16, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 385, 405, 200, 280, 0, pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(2, 2), 500, 400, 200, 280, 1, 0, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 500, 400, 200, 280, 0, 0, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(2, 3), 615, 415, 200, 280, 1, -pi/16, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 615, 415, 200, 280, 0, -pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(2, 4), 730, 450, 200, 280, 1, -pi/8, 525, 310, 150, 210, 0, 0, winning_hand_duration);
    animateTexture(cardBack, 730, 450, 200, 280, 0, -pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);

    animateTexture(cardBack, 992, 310, 150, 210, 1, pi/2 + pi/8, 100, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 0).c_str(), 992, 310, 150, 210, 0, pi/2 + pi/8, 100, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 983, 280, 150, 210, 1, pi/2 + pi/16, 300, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 1).c_str(), 983, 280, 150, 210, 0, pi/2 + pi/16, 300, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 980, 250, 150, 210, 1, pi/2, 500, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 2).c_str(), 980, 250, 150, 210, 0, pi/2, 500, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 995, 220, 150, 210, 1, pi/2 - pi/16, 700, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 3).c_str(), 995, 220, 150, 210, 0, pi/2 - pi/16, 700, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 1010, 190, 150, 210, 1, pi/2 - pi/8, 900, 275, 200, 280, 0, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 4).c_str(), 1010, 190, 150, 210, 0, pi/2 - pi/8, 900, 275, 200, 280, 1, 0, winning_hand_duration);
  }
  else { // (winner == 2)
    animateTexture(cardBack, 58, 190, 150, 210, 1, -pi/2 + pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 67, 220, 150, 210, 1, -pi/2 + pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 70, 250, 150, 210, 1, -pi/2, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 55, 280, 150, 210, 1, -pi/2 - pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 40, 310, 150, 210, 1, -pi/2 - pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);

    animateTexture(cardBack, 992, 310, 150, 210, 1, pi/2 + pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 983, 280, 150, 210, 1, pi/2 + pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 980, 250, 150, 210, 1, pi/2, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 995, 220, 150, 210, 1, pi/2 - pi/16, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    animateTexture(cardBack, 1010, 190, 150, 210, 1, pi/2 - pi/8, 525, 310, 150, 210, 1, 0, winning_hand_duration);
    
    animateTexture(dataController->getPlayersCard(winner, 0).c_str(), 270, 430, 200, 280, 1, pi/8, 100, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 1).c_str(), 385, 405, 200, 280, 1, pi/16, 300, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 2).c_str(), 500, 400, 200, 280, 1, 0, 500, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 3).c_str(), 615, 415, 200, 280, 1, -pi/16, 700, 275, 200, 280, 1, 0, winning_hand_duration);
    animateTexture(dataController->getPlayersCard(winner, 4).c_str(), 730, 450, 200, 280, 1, -pi/8, 900, 275, 200, 280, 1, 0, winning_hand_duration);
  }
}

void returnCardsAnimation(DataController * dataController) {
  animateTexture(cardBack, 525, 275, 150, 210, 1, 0, 525, -300, 150, 210, 1, 0, return_cards_duration);

  // animateTexture(cardBack, 500, 400, 200, 280, 1, 0, 525, -300, 150, 210, 1, 0, return_cards_duration);

  // animateTexture(cardBack, 980, 250, 150, 210, 1, pi/2, 525, -300, 150, 210, 1, 0, return_cards_duration);
}

void rotateTableAnimation(DataController * dataController) {
  animateTexture("images/backgrounds/pam/maintable.pam", -125, -375, 1450, 1450, 1, table_orientation, -125, -375, 1450, 1450, 1, table_orientation+pi/2, rotation_duration, 0, 0, 0, 0, 0, sin((elapsed_time/rotation_duration)*pi));
  // cout << sin((elapsed_time/rotation_duration)*pi) << endl;
  drawTexture(loadTexture("images/backgrounds/pam/header.pam"), 0, 0, 1200, 750);
}

void showWinningHand(DataController * dataController) {
  drawTexture(loadTexture(dataController->getPlayersCard(winner, 0).c_str()), 100, 275, 200, 280, 1, 0);
  drawTexture(loadTexture(dataController->getPlayersCard(winner, 1).c_str()), 300, 275, 200, 280, 1, 0);
  drawTexture(loadTexture(dataController->getPlayersCard(winner, 2).c_str()), 500, 275, 200, 280, 1, 0);
  drawTexture(loadTexture(dataController->getPlayersCard(winner, 3).c_str()), 700, 275, 200, 280, 1, 0);
  drawTexture(loadTexture(dataController->getPlayersCard(winner, 4).c_str()), 900, 275, 200, 280, 1, 0);
}

void closeWinningCardsAnimation(DataController * dataController) {
  animateTexture(tempCards2[0], 100, 275, 200, 280, 1, 0, 525, 275, 150, 210, 0, 0, close_winning_cards_duration);
  animateTexture(cardBack, 100, 275, 200, 280, 0, 0, 525, 275, 150, 210, 1, 0, close_winning_cards_duration);
  animateTexture(tempCards2[1], 300, 275, 200, 280, 1, 0, 525, 275, 150, 210, 0, 0, close_winning_cards_duration);
  animateTexture(cardBack, 300, 275, 200, 280, 0, 0, 525, 275, 150, 210, 1, 0, close_winning_cards_duration);
  animateTexture(tempCards2[2], 500, 275, 200, 280, 1, 0, 525, 275, 150, 210, 0, 0, close_winning_cards_duration);
  animateTexture(cardBack, 500, 275, 200, 280, 0, 0, 525, 275, 150, 210, 1, 0, close_winning_cards_duration);
  animateTexture(tempCards2[3], 700, 275, 200, 280, 1, 0, 525, 275, 150, 210, 0, 0, close_winning_cards_duration);
  animateTexture(cardBack, 700, 275, 200, 280, 0, 0, 525, 275, 150, 210, 1, 0, close_winning_cards_duration);
  animateTexture(tempCards2[4], 900, 275, 200, 280, 1, 0, 525, 275, 150, 210, 0, 0, close_winning_cards_duration);
  animateTexture(cardBack, 900, 275, 200, 280, 0, 0, 525, 275, 150, 210, 1, 0, close_winning_cards_duration);
}

void drawCardsToScreen(DataController * dataController) {
    drawTexture(loadTexture(cardBack.c_str()), 58, 190, 150, 210, 1, -pi/2 + pi/8);
    drawTexture(loadTexture(cardBack.c_str()), 67, 220, 150, 210, 1, -pi/2 + pi/16);
    drawTexture(loadTexture(cardBack.c_str()), 70, 250, 150, 210, 1, -pi/2);
    drawTexture(loadTexture(cardBack.c_str()), 55, 280, 150, 210, 1, -pi/2 - pi/16);
    drawTexture(loadTexture(cardBack.c_str()), 40, 310, 150, 210, 1, -pi/2 - pi/8);

    drawTexture(loadTexture(dataController->getCurrentPlayersCard(0).c_str()), 270, 430, 200, 280, 1, pi/8);
    drawTexture(loadTexture(dataController->getCurrentPlayersCard(1).c_str()), 385, 405, 200, 280, 1, pi/16);
    drawTexture(loadTexture(dataController->getCurrentPlayersCard(2).c_str()), 500, 400, 200, 280);
    drawTexture(loadTexture(dataController->getCurrentPlayersCard(3).c_str()), 615, 415, 200, 280, 1, -pi/16);
    drawTexture(loadTexture(dataController->getCurrentPlayersCard(4).c_str()), 730, 450, 200, 280, 1, -pi/8);

    drawTexture(loadTexture(cardBack.c_str()), 992, 310, 150, 210, 1, pi/2 + pi/8);
    drawTexture(loadTexture(cardBack.c_str()), 983, 280, 150, 210, 1, pi/2 + pi/16);
    drawTexture(loadTexture(cardBack.c_str()), 980, 250, 150, 210, 1, pi/2);
    drawTexture(loadTexture(cardBack.c_str()), 995, 220, 150, 210, 1, pi/2 - pi/16);
    drawTexture(loadTexture(cardBack.c_str()), 1010, 190, 150, 210, 1, pi/2 - pi/8);
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

void storeCards2(DataController * dataController, int p_num) {
  for (int i = 0; i < 5; ++i) {
    tempCards2[i] = dataController->getPlayersCard(p_num, i);
  }
}

void MainScreen::drawMainScreen() {
  if (buttons.size() == 0) {
    buttons.push_back(Button("", 230, 85, 20, 19, 0.098, 0.694, 0.173, 0.0, 0.25, 0.3));
    buttons.push_back(Button("", 230, 85, 952, 19, 0.098, 0.694, 0.173, 0.0, 0.25, 0.3));
  }

  drawTexture(loadTexture("images/backgrounds/pam/maintable.pam"), -125, -375, 1450, 1450, 1, table_orientation);
  drawTexture(loadTexture("images/backgrounds/pam/header.pam"), 0, 0, 1200, 750);

  
  // THE FOLLOWING ARE ALL ANIMATIONS /////////////////////////////////////////
  // IT IS A HORRIBLY DESIGNED, YET FINELY TUNED SYSTEM. DON'T FUCK WITH IT.

  // DELAY BEFORE DEALING CARDS
  if (waitForDeal) {
    setTime();
    if (elapsed_time < dealing_delay) {
    }
    else {
      waitForDeal = false;
      stillDealing = true;
      start_time = getCurrentTime();
    }
    glutPostRedisplay();
  }
  // ROTATE TABLE BEFORE REDEALING CARDS
  else if (rotateTable) {
    setTime();
    if (elapsed_time < rotation_duration) {
      rotateTableAnimation(dataController);
    }
    else {
      rotateTable = false;
      drawTexture(loadTexture("images/backgrounds/pam/maintable.pam"), -125, -375, 1450, 1450, 1, table_orientation);
      // rotateTableAnimation(dataController);
      table_orientation += pi/2;
      start_time = getCurrentTime();
    }
    glutPostRedisplay();
  }
  // DEAL THE CARDS OUT
  else if (stillDealing) {
    setTime();
    // cout << "elapsed_time < dealing_duration: " << (elapsed_time < dealing_duration) << endl;
    // cout << "dealing_duration: " << dealing_duration << endl;
    if ((elapsed_time < dealing_duration) && stillDealing) {
      dealCardsAnimation(dataController, current_card);
    }
    else {
      ++current_card; 
      start_time = getCurrentTime();
      setTime();
      dealCardsAnimation(dataController, current_card);
    }
    glutPostRedisplay();
  }
  // FAN THE CARDS FOR AESTHETIC VANITY
  else if (openCardFan) {
    setTime();
    if (elapsed_time < spread_duration) {
      spreadCardsAnimation(dataController);
    }
    else {
      dataController->addToPool(50);
      openCardFan = false;
      nextTurnEnabled = true;
      spreadCardsAnimation(dataController);
      // winPercentage = rand() % 100000;
      // winPercentage /= 1000.0;
      dataController->getWinningHand();
      winner = dataController->getWinner();
      storeCards2(dataController, winner);
      // cout << "winner: " << winner+1 << endl;
      // winPercentage = rand() % 100000;
      // winPercentage /= 1000.0;
      // dataController->getCurrentPlayersHand().printHand();
      // dataController->getCurrentPlayersHand().findBestHand();
      // cout << dataController->getCurrentPlayersHand().getBestHand() << ", with rank " << dataController->getCurrentPlayersHand().getHandRank(4) << endl;
    }
    glutPostRedisplay();
  }
  // DISPLAY WHO WON THE HAND BEFORE REDEALING
  else if (displayWinner) {
    setTime();
    if (elapsed_time < winning_hand_duration) {
      displayWinnerAnimation(dataController);
    }
    else {
      displayWinner = false;
      waitForNextClick = true;
      nextTurnEnabled = true;
      displayWinnerAnimation(dataController);
    }
    glutPostRedisplay();
  }
  else if (waitForNextClick) {
    showWinningHand(dataController);
    string win_text = dataController->getPlayersName(winner);
    win_text += " Wins";
    drawText(win_text, 600, 180, 28, 1.25);
    drawText(dataController->getPlayersBestHand(winner), 600, 570, 28, 1.05);
  }

  // CLOSE CARD FAN BEFORE SENDING CARDS BACK TO DEALER
  else if (closeWinningCards) {
    setTime();
    if (elapsed_time < close_winning_cards_duration) {
      closeWinningCardsAnimation(dataController);
      glutPostRedisplay();
    }
    else {
      closeWinningCards = false;
      returnCardsToDealer = true;
      closeWinningCardsAnimation(dataController);
      start_time = getCurrentTime();
      // returnCardsToDealer = true;
      // start_time = getCurrentTime();
    }
    glutPostRedisplay();
  }

  // SEND CARDS BACK TO DEALER TO BE REDEALT
  else if (returnCardsToDealer) {
    setTime();
    if (elapsed_time < return_cards_duration) {
      returnCardsAnimation(dataController);
    }
    else {
      rotateTable = true;
      changePlayers = false;
      returnCardsToDealer = false;
      waitForDeal = true;
      current_card = 0;
      start_time = getCurrentTime();
      returnCardsAnimation(dataController);
      // table_orientation += pi/2;
    }
    glutPostRedisplay();
  }
  // CHANGE PLAYERS BETWEEN TURNS
  else if (changePlayers) {
    setTime();
    if (elapsed_time < animation_duration) {
      changePlayersAnimation(dataController);
    }
    else {
      nextTurnEnabled = true;
      changePlayers = false;
      drawCardsToScreen(dataController);
    }
    glutPostRedisplay();
  }
  // NO FANCY ANIMATIONS HERE /////////////////////////////
  else {

    drawCardsToScreen(dataController);
    drawTexture(loadTexture("images/backgrounds/pam/chanceofwinning.pam"), 400, 150, 400, 100);

    drawTexture(loadTexture(dataController->getCurrentChip().c_str()), 990, 610, 140, 140, 1.0, pi/dataController->getChipRotation());

    // drawLargestText(dataController->getCurrentPlayersName(), 1010, 550);
    // drawText(dataController->getCurrentPlayersName(), 150, 620, 28, 1);
    drawText(dataController->getCurrentPlayersName(), 600, 685, 28, 1);
    drawText(dataController->getPlayersName((dataController->getCurrentPlayer()+1)%3), 125, 130, 26, 0.75);
    drawText(dataController->getPlayersName((dataController->getCurrentPlayer()+2)%3), 1075, 130, 26, 0.75);

    char buff[20];
    long money = dataController->getCurrentPlayersCurrencyMoneysAndShit();
    sprintf(buff, "%ld", money);
    drawNumbers(buff, strlen(buff), 1020, 570, 0.6, false);

    char buff2[10];
    // float winPercentage = rand() % 100000;
    // winPercentage /= 1000.0;
    sprintf(buff2, "%.2f", dataController->getCurrentPlayersHand().getHandPercentage());
    drawNumbers(buff2, strlen(buff2), 552, 275, 1, true);
  }
  // drawTexture(loadTexture("images/backgrounds/pam/mainoverlay.pam"), 0, 0, 1200, 750);
      
  // glutPostRedisplay();

}

void MainScreen::drawText(string text, int x_location, int y_location, float kerning, float scale) {
  
  x_location -= (kerning*scale)*(text.size())/2;
  int temp_y = y_location;

  for (int i = 0; i < text.size(); ++i) {
    string pathname = "images/";
    if (text[i] >= 96)
      pathname+="letters/lower/pam/";
    else if (text[i] <= 57) {
      pathname+="numbers/pam/";
      y_location -= (8*scale);
    }
    else // text[i] >= 65 && text[i] <= 90
      pathname+="letters/upper/pam/";
    pathname+=text[i];
    pathname+=".pam";
    switch (text[i]) {
      case '1':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location+(10*scale), 22*scale, 70*scale);
        x_location-=(5*scale);
        break;
      case '6':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location+(3*scale), 30*scale, 70*scale);
        break;
      case 'B':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(1*scale), 30*scale, 70*scale);
        break;
      case 'a':
        drawTexture(loadTexture(pathname.c_str()), x_location-(1*scale), y_location-(1*scale), 30*scale, 70*scale);
        break;
      case 'b':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(1*scale), 30*scale, 70*scale);
        break;
      case 'E':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(1*scale), 30*scale, 70*scale);
        break;
      case 'F':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(2*scale), 30*scale, 70*scale);
        break;
      case 'g':
        drawTexture(loadTexture(pathname.c_str()), x_location-(2*scale), y_location, 34*scale, 70*scale);
        break;
      case 'I':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location, 25*scale, 70*scale);
        x_location-=(5*scale);
        break;
      case 'i':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location, 24*scale, 70*scale);
        x_location-=(6*scale);
        break;
      case 'j':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location, 24*scale, 70*scale);
        x_location-=(6*scale);
        break;
      case 'k':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(1*scale), 30*scale, 70*scale);
        break;
      case 'l':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location+(1*scale), 21*scale, 70*scale);
        x_location-=(7*scale);
        break;
      case 'M':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(1*scale), 30*scale, 70*scale);
        break;
      case 'n':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location+(1*scale), 30*scale, 70*scale);
        break;
      case 'S':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(1*scale), 30*scale, 70*scale);
        break;
      case 'T':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(1*scale), 30*scale, 70*scale);
        break;
      case 't':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(1*scale), 30*scale, 70*scale);
        x_location-=(6*scale);
        break;
      case 'U':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location+(2*scale), 30*scale, 70*scale);
        break;
      case 'r':
        drawTexture(loadTexture(pathname.c_str()), x_location-(12*scale), y_location+(1*scale), 50*scale, 70*scale);
        x_location-=(4*scale);
        break;
      case 'W':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(4*scale), 40*scale, 74*scale);
        x_location+=(8*scale);
        break;
      case 'w':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location, 38*scale, 70*scale);
        x_location+=(5*scale);
      case 'y':
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location-(2*scale), 30*scale, 70*scale);
        break;
      case ' ':
        break;
      default:
        drawTexture(loadTexture(pathname.c_str()), x_location, y_location, 30*scale, 70*scale);
        break;
    }
    x_location+=(kerning*scale);
    y_location = temp_y;
  }
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
    buttons.push_back(Button("", 144, 55, 39, 674, 0.0, 0.0, 0.0, 0.0, 0.25, 0.3));

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
        if (waitForNextClick) {
          waitForNextClick = false;
          closeWinningCards = true;
          // cout << "winner: " << winner+1 << endl;
          dataController->claimPool(winner);
          start_time = getCurrentTime();
        }
        if (++player_num == 3) {
          // cout << "pausing" << endl;
          // dataController->getCurrentPlayersHand().findBestHand();
          // winner = dataController->getWinner();
          // cout << "winner: " << winner+1 << endl;
          displayWinner = true;
          nextTurnEnabled = false;
          start_time = getCurrentTime();
          player_num = -1;
        }
        else {
          // cout << "changing players" << endl;
          storeCards(dataController);
            
          changePlayers = true;
          dataController->nextPlayer();
          // if (++player_num != 3) {
          //   cout << "player_num: " << player_num << endl;
          //   dataController->nextPlayer();
          // }
          // else {
          //   changePlayers = false;
          //   displayWinner = true;
          //   // dataController->setTurns(-1);
          //   cout << "resetting player num" << endl;
          //   player_num = 0;
          // }
          start_time = getCurrentTime();
          table_orientation += pi/2;
          nextTurnEnabled = false;
        }
        // winPercentage = rand() % 100000;
        // winPercentage /= 1000.0;
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
