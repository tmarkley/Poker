#ifndef _MAINSCREEN_
#define _MAINSCREEN_
#include "screen.h"
#include "datacontroller.h"
#include "drawingfunctions.h"

// enum Menus {NONE, MONEY_MENU, BUILDINGS_MENU, PROFESSORS_MENU, ENTERTAINMENT_MENU, FOOD_MENU, BUILDING_OPTIONS_MENU, SETTINGS_MENU};

class MainScreen : public Screen {
  
  int numButtons;//total number of buttons that are always there
  int numButtonsAddedForMenu;//temp number of buttons that are added for each menu
  int leftScreenPositionX;
  // Menus currentMenu;
  // int currentBuildingOptionsIndex;
  // double totalTime;
  // int currentWarningMessageIndex;

 public:
  MainScreen(DataController *theDataController);
  void draw(bool shouldDrawButtons = false);

  //virtual functions
  void isOnButton(int x, int y);
  int didClickButton(int x, int y);
  void offButtons();

  // void generateDetailButtonsForLoadGame();


 private:
  // void drawIconBar();
  // void drawStatusBox();

  // void drawMoneyMenu();
  // void drawBuildingMenu();
  // void drawProfessorsMenu();
  // void drawEntertainmentMenu();
  // void drawFoodMenu();
  // void drawBuildingOptionsMenu();
  // void drawSettingsMenu();
  // void drawWarningBox(string theMessage);
  // void removeCurrentMenu();

  // void addDetailButton(int buildingWidth, int topLimit);

};

#endif //_MAINSCREEN_
