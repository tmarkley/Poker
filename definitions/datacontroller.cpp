#include "../headers/datacontroller.h"

DataController::DataController() {

  turns = 0;

  createDeck(true);
  
  Hand first, second, third;
  hands.push_back(first);
  hands.push_back(second);
  hands.push_back(third);

  dealHands();

  srand(time(0));
  currentPlayer = rand() % 3;
  
  chip.push_back("redchip.pam");
  chip.push_back("blackchip.pam");
  chip.push_back("bluechip.pam");

  chipRotation = 2;

  moneys.push_back(20000);
  moneys.push_back(1232340);
  moneys.push_back(4340);

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

}

string DataController::getCurrentPlayersCard(int index) {

  return "images/cards/medium/" + hands[currentPlayer].getCard(index);

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
    for (int i=0; i < 3; i++)
      hands[i].clearHand();
    clearDeck();
    createDeck();
    dealHands();
    turns = 0;
  }
  srand(time(0));
  chipRotation = rand() % 5 + (currentPlayer+1);
  moneys[currentPlayer] += chipRotation;
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