#include <algorithm>
#include "../headers/datacontroller.h"

#define DEV_TEST false
#define pi 3.1415926535

extern bool displayWinner;
extern bool changePlayers;
extern double start_time;
extern double getCurrentTime();
extern double table_orientation;

DataController::DataController() {

  turns = 0;

  createDeck(true);
  
  Hand first, second, third;
  hands.push_back(first);
  hands.push_back(second);
  hands.push_back(third);

  dealHands();

  srand(time(0));
  // currentPlayer = rand() % 3;
  currentPlayer = 0;
  
  chip.push_back("redchip.pam");
  chip.push_back("blackchip.pam");
  chip.push_back("bluechip.pam");

  chipRotation = 2;

  moneyPool = 0;

  moneys.push_back(500);
  moneys.push_back(500);
  moneys.push_back(500);

}

DataController::~DataController(){
  // for(int i = 0; i < buildings.size(); i++){
  //   delete buildings[i];
  // }
}

void DataController::createDeck(bool loadTextures = false) {

  ifstream f("txt/cardlist.txt");
  if (!f.good()) {
    cerr << "Error! Could not open cardlist.txt!" << endl;
    exit(0);
  }

  for (int i=0; i < 52; i++) {
    string name;
    getline(f, name);
    deck.push_back(new Card(name));
  }

  f.close();

  shuffleDeck();

}

void DataController::loadTextures() {

  for (int i=0; i < deck.size(); i++) {
    string dir = "images/cards/large/" + deck[i]->getImageName();
    loadTexture(dir.c_str());
  }

}

void DataController::dealHands() {

  for (int i=0; i < 5; i++) {
    for (int j=0; j < 3; j++) {
      hands[j].addCard(*deck[deck.size()-1]);
      deck.pop_back();
    }
  }
  if (DEV_TEST) {
    for (int i = 0; i < 3; ++i) {
      cout << "Player " << i+1 << "'s Hand" << endl;
      // hands[i].findBestHand();
      cout << "~~~~~~~~~~~~~~" << endl;
      hands[i].printHand();
      cout << "~~~~~~~~~~~~~~" << endl;
      cout << hands[i].getBestHand() << endl;
      cout << "~~~~~~~~~~~~~~" << endl;
      for (int j = 0; j < 6; ++j) {
        cout << hands[i].getHandRank(j) << " ";
      }
      cout << endl << endl;
    }
    // getWinningHand();
    // cout << endl << "Best Hand: Player " << getWinningHand() << endl;
  }
  if (!DEV_TEST) {
    // hands[currentPlayer].rigHand();
    // for (int i = 0; i < 3; ++i) {
    //   hands[i].findBestHand();
    //   cout << playerNames[i] << "'s percentage: " << hands[i].getHandPercentage() << endl;
    // }
    // cout << endl << "Best Hand: Player " << getWinningHand() << endl;
  }
}

string DataController::getCurrentPlayersCard(int index) {

  return "images/cards/medium/" + hands[currentPlayer].getCard(index);

}

int downToOne(bool player[]) {
  int num_players_remaining = 0;
  int last_player;
  for (int i = 0; i < 3; ++i) {
    if (player[i]) {
      last_player = i;
      num_players_remaining++;
    }
  }
  if (num_players_remaining > 1)
    return -1;
  else if (num_players_remaining == 1) {
    return last_player;
  }
  else
    cout << "What the heck is going on?" << endl;
  return -1;
}

int DataController::getWinningHand() {
  for (int i = 0; i < 3; ++i) {
    hands[i].findBestHand();
  }

  bool player[3] = {true, true, true};

  for (int i = 5; i >= 0; --i) {
    int maximum;
    if (player[0] && player[1] && player[2])
      maximum = max(hands[0].getHandRank(i), max(hands[1].getHandRank(i), hands[2].getHandRank()));
    else {
      if (player[0] && player[1])
        maximum = max(hands[0].getHandRank(i), hands[1].getHandRank(i));
      else if (player[1] && player[2])
        maximum = max(hands[1].getHandRank(i), hands[2].getHandRank(i));
      else // player[0] && player[2]
        maximum = max(hands[0].getHandRank(i), hands[2].getHandRank(i));
    }
    // cout << "sherl" << endl;
    for (int j = 0; j < 3; ++j) {
      if (hands[j].getHandRank(i) < maximum)
        player[j] = false;
    }
    if (downToOne(player) != -1) {
      winningPlayer = downToOne(player);
      handWinner = playerNames[winningPlayer];
      return winningPlayer;
    }
  }

  // CHANGE THIS EVENTUALLY ///////////////
  // Will reach this point if there is a complete tie.
  // I don't know what actually happens in a poker game.
  cerr << "Tie: MIGHT CAUSE SEG FAULT CURRENTLY" << endl;
  return -1;
  // CHANGE THIS EVENTUALLY ///////////////

}

void DataController::addToPool(long sum) {

  for (int i = 0; i < 3; ++i) {
    moneys[i] -= sum;
    moneyPool += sum;
  }

}

void DataController::claimPool(int player) {

  moneys[player] += moneyPool;
  moneyPool = 0;

}

int DataController::getTurns() {

  return turns;

}

void DataController::setTurns(int t) {

  turns = t;

}

int DataController::getWinner() {

  return winningPlayer;

}

Hand & DataController::getCurrentPlayersHand() {

  return hands[currentPlayer];

}

string DataController::getPlayersCard(int player, int card) {

  return "images/cards/medium/" + hands[player].getCard(card);

}

int DataController::getCurrentPlayer() {

  return currentPlayer;

}

string DataController::getCurrentChip() {

  return "images/backgrounds/pam/" + chip[currentPlayer];

}

int DataController::getChipRotation() {

  return chipRotation;

}

int DataController::getCurrentPlayersCurrencyMoneysAndShit() {

  return moneys[currentPlayer];

}

void DataController::nextPlayer() {

  currentPlayer = (currentPlayer + 1) % 3;
  if (++turns == 3) {
    getWinningHand();
    // cout << "Winner: " << handWinner << endl;
    for (int i=0; i < 3; i++)
      hands[i].clearHand();
    clearDeck();
    createDeck();
    dealHands();
    table_orientation -= pi/2;
    changePlayers = false;
    // displayWinner = true;
    start_time = getCurrentTime();
    // turns = -1;
    turns = 0;
  }
  srand(time(0));
  chipRotation = rand() % 5 + (currentPlayer+1);
  // moneys[currentPlayer] += chipRotation;
}

string DataController::getCurrentPlayersName() {

  return playerNames[currentPlayer];

}

string DataController::getPlayersName(int player) {

  return playerNames[player];

}

string DataController::getPlayersBestHand(int player) {

  return hands[player].getBestHand();
  
}

void DataController::setPlayerNames(vector<string> names) {

  for (int i=0; i < names.size(); i++) {
    playerNames.push_back(names[i]);
  }

}

int myrandom(int i) { return rand()%i;}

void DataController::shuffleDeck() {

  srand(time(0));
  random_shuffle(deck.begin(), deck.end(), myrandom);

}

void DataController::clearDeck() {

  int numCards = deck.size();
  for (int i = 0; i < numCards; i++)
    deck.erase(deck.begin());

}