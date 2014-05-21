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
  string handWinner;
  int winningPlayer;
  int turns;
  vector<string> chip;
  int chipRotation; // this is very necessary.
  vector<int> moneys;
  double moneyPool;

public:

  DataController();
  ~DataController();

  // deck functions
  void createDeck(bool);
  void dealHands();
  void shuffleDeck();
  void clearDeck();
  
  // getter functions
  int getWinningHand();
  int getWinner();
  int getTurns();
  void setTurns(int t);
  void addToPool(double sum);
  void claimPool(int player);
  string getCurrentPlayersCard(int index);
  Hand & getCurrentPlayersHand();
  string getPlayersCard(int player, int card);
  int getCurrentPlayer();
  string getCurrentPlayersName();
  string getCurrentChip();
  int getChipRotation();
  int getCurrentPlayersCurrencyMoneysAndShit();

  void setPlayerNames(vector<string>);  
  void nextPlayer();
  void loadTextures();

  void addMoney(int);
  void subtractMoney(int);

};

#endif //_DATACONTROLLER_