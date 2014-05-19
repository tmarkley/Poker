#ifndef _DATACONTROLLER_
#define _DATACONTROLLER_

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include "hand.h"
#include "texture.h"
using namespace std;

class DataController {

  vector<Card *> deck;
  vector<Hand> hands;
  int currentPlayer;
  vector<string> playerNames;
  int turns;
  vector<string> chip;
  int chipRotation; // this is very necessary.
  vector<int> moneys;

public:

  DataController();
  ~DataController();

  // deck functions
  void createDeck(bool);
  void dealHands();
  void shuffleDeck();
  void clearDeck();
  
  // getter functions
  string getCurrentPlayersCard(int index);
  Hand & getCurrentPlayersHand();
  int getCurrentPlayer();
  string getCurrentChip();
  int getChipRotation();
  int getCurrentPlayersCurrencyMoneysAndShit();
  
  void nextPlayer();
  void loadTextures();

  void addMoney(int);

};

#endif //_DATACONTROLLER_