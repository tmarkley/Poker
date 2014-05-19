#include "../headers/hand.h"

vector<Card *> Hand::getCards() {
	
	return hand;

}

string Hand::getCard(int index) {

  return hand[index]->getImageName();

}

void Hand::addCard(Card c) {

  // sort as we add
  if (hand.size() == 0)
    hand.push_back(new Card(c.getImageName()));
  else {
    vector<Card *>::iterator it;
    it = hand.begin();
    int rank = c.getRank();
    int index = 0;
    while ((index < hand.size()) && (rank > hand[index]->getRank())) {
      index++;
      it++;
    }
    hand.insert(it, new Card(c.getImageName()));
  }

}

// FOR TESTING PURPOSES ONLY /////////////////////////////////////////////
extern Card card1;
extern Card card2;
extern Card card3;
extern Card card4;
extern Card card5;
void Hand::rigHand() {
  clearHand();
  addCard(card1);
  addCard(card2);
  addCard(card3);
  addCard(card4);
  addCard(card5);
}
// FOR TESTING PURPOSES ONLY /////////////////////////////////////////////

void Hand::clearHand() {

	int numCards = hand.size();
	for (int i = 0; i < numCards; i++)
    hand.erase(hand.begin());

}

int Hand::findBestHand() {

  // int rank = 0;
  if (StraightFlush()) {
    handRank[5] = 8;
    bestHand = "Straight Flush";
    return 8;
  }
  else if (FourOfAKind()) {
    handRank[5] = 7;
    bestHand = "Four Of A Kind";
    return 7;
  }
  else if (FullHouse()) {
    handRank[5] = 6;
    bestHand = "Full House";
    return 6;
  }
  else if (Flush()) {
    handRank[5] = 5;
    bestHand = "Flush";
    return 5;
  }
  else if (Straight()) {
    handRank[5] = 4;
    bestHand = "Straight";
    return 4;
  }
  else if (ThreeOfAKind()) {
    handRank[5] = 3;
    bestHand = "Three Of A Kind";
    return 3;
  }
  else if (TwoPair()) {
    handRank[5] = 2;
    bestHand = "Two Pair";
    return 2;
  }
  else if (OnePair()) {
    handRank[5] = 1;
    bestHand = "One Pair";
    return 1;
  }
  else {
    handRank[5] = 0;
    bestHand = "High Card";
    return 0;
  }

}


void Hand::printHand() {
  string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  string faceCards[] = {"Jack", "Queen", "King", "Ace"};
  for (int i = 0; i < hand.size(); ++i) {
    int rank = hand[i]->getRank();
    if (rank <= 10) {
      cout << rank;
    }
    else {
      cout << faceCards[rank-11];
    }
    cout << " of " << suits[hand[i]->getSuit()] << endl;
  }
}

int Hand::getHandRank(int index) {

  return handRank[index];

}

string Hand::getBestHand() {

  return bestHand;

}

int Hand::StraightFlush() {
  for (int i = 0; i < 5; ++i)
    handRank[i] = hand[i]->getRank();

  int suit = hand[4]->getSuit();
  int decrementer = handRank[4];

  for (int i = 0; i < 4; ++i) {
    if (hand[i]->getSuit() != suit) {
      return 0;
    }
  }
  
  if (handRank[4] == 14) { // Ace
    if (handRank[3] == 5) { // Assume Ace low
      decrementer = handRank[3];
      for (int i = 2; i >= 0; --i) { // check lower 3 cards
        if (handRank[i] != --decrementer) {
          return 0;
        }
      }
      return 1; // Straight flush with Ace low
    }
    else { // Ace is high
      for (int i = 3; i >= 0; --i) { // check lower 4 cards
        if (handRank[i] != --decrementer) {
          return 0;
        }
      }
      return 1;
    }
  }
  else { // regular run of cards without Ace
    for (int i = 3; i >= 0; --i) { // check lower 4 cards
      if (handRank[i] != --decrementer) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

int Hand::FourOfAKind() {
  if (handRank[0] == handRank[1] && handRank[1] == handRank[2] && handRank[2] == handRank[3]) { // first 4 are same
    // EXAMPLE: 2 2 2 2 3
    handRank[0] = handRank[4]; // 3 2 2 2 3
    handRank[4] = handRank[3]; // 3 2 2 2 2
    return 1;
  }
  else if (handRank[1] == handRank[2] && handRank[2] == handRank[3] && handRank[3] == handRank[4]) { // last 4 are same
    // EXAMPLE: 2 3 3 3 3
    return 1;
  }
  else {
    return 0;
  }

}
int Hand::FullHouse() {
  if (handRank[0] == handRank[1]) {     // first pair the same
    if (handRank[1] == handRank[2]) {   // first three the same
      if (handRank[3] == handRank[4]) { // last two the same
        // EXAMPLE: 2 2 2 3 3
        handRank[0] = handRank[1] = handRank[4]; // 3 3 2 3 3
        handRank[3] = handRank[4] = handRank[2]; // 3 3 2 2 2
        return 1;
      }
      else
        return 0;
    }
    else {                              // first pair the same
      if (handRank[2] == handRank[3] && handRank[3] == handRank[4]) { // last three the same
        // EXAMPLE: 2 2 3 3 3
        return 1;
      }
      else
        return 0;
    }
  }
  else
    return 0;
}

int Hand::Flush() {
  int suit[5];
  for (int i = 0; i < 5; ++i)
    suit[i] = hand[i]->getSuit();
  if (suit[0] == suit[1] && suit[1] == suit[2] && suit[2] == suit[3] && suit[3] == suit[4])
    return 1;
  else {
    return 0;
  }
}

int Hand::Straight() {
  int decrementer = handRank[4];

  if (handRank[4] == 14) { // Ace
    if (handRank[3] == 5) { // Assume Ace low
      decrementer = handRank[3];
      for (int i = 2; i >= 0; --i) { // check lower 3 cards
        if (handRank[i] != --decrementer) {
          return 0;
        }
      }
      return 1; // Straight flush with Ace low
    }
    else { // Ace is high
      for (int i = 3; i >= 0; --i) { // check lower 4 cards
        if (handRank[i] != --decrementer) {
          return 0;
        }
      }
      return 1;
    }
  }
  else { // regular run of cards without Ace
    for (int i = 3; i >= 0; --i) { // check lower 4 cards
      if (handRank[i] != --decrementer) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

int Hand::ThreeOfAKind() {
  if (handRank[0] == handRank[1] && handRank[1] == handRank[2]) {       // first 3 same
    // EXAMPLE: 2 2 2 3 4
    handRank[0] = handRank[4];                // 4 2 2 3 4
    handRank[1] = handRank[3];                // 4 3 2 3 4
    handRank[3] = handRank[4] = handRank[2];  // 4 3 2 2 2
    return 1;
  }
  else if (handRank[1] == handRank[2] && handRank[2] == handRank[3]) {  // middle 3 same
    // EXAMPLE: 2 3 3 3 4
    handRank[1] = handRank[4];  // 2 4 3 3 4
    handRank[4] = handRank[3];  // 2 4 3 3 3
    return 1;
  }
  else if (handRank[2] == handRank[3] && handRank[3] == handRank[4])    // last 3 same
    return 1;
  else
    return 0;

}

int Hand::TwoPair() {
  if (handRank[0] == handRank[1]) {     // 1 and 2 are a pair
    if (handRank[2] == handRank[3]) {       // 3 and 4 are a pair
      // EXAMPLE: 2 2 3 3 4
      handRank[0] = handRank[4];  // 4 2 3 3 4
      handRank[4] = handRank[3];  // 4 2 3 3 3
      handRank[2] = handRank[1];  // 4 2 2 3 3
      return 1;
    }
    else if (handRank[3] == handRank[4]) {  // 4 and 5 are a pair
      // EXAMPLE: 2 2 3 4 4
      handRank[0] = handRank[2];  // 3 2 3 4 4
      handRank[2] = handRank[1];  // 3 2 2 4 4
      return 1;
    }
  }
  else if (handRank[1] == handRank[2]) {  // 2 and 3 are a pair
    if (handRank[3] == handRank[4])           // 4 and 5 are a pair
      return 1;
  }
  else
    return 0;
  return 0;
}

int Hand::OnePair() {
  if (handRank[0] == handRank[1]) {       // 1 and 2 are a pair
    // EXAMPLE: 2 2 3 4 5
    int temp = handRank[0];   // handRank[0] == 2;
    handRank[0] = handRank[2];        // 3 2 3 4 5
    handRank[1] = handRank[3];        // 3 4 3 4 5
    handRank[2] = handRank[4];        // 3 4 5 4 5
    handRank[3] = handRank[4] = temp; // 3 4 5 2 2
    return 1;
  }
  else if (handRank[1] == handRank[2]) {  // 2 and 3 are a pair
    // EXAMPLE: 2 3 3 4 5
    int temp = handRank[1];   // handRank[1] = 3;
    handRank[1] = handRank[3];        // 2 4 3 4 5
    handRank[2] = handRank[4];        // 2 4 5 4 5
    handRank[3] = handRank[4] = temp; // 2 4 5 3 3
    return 1;
  }
  else if (handRank[2] == handRank[3]) {  // 3 and 4 are a pair
    // EXAMPLE: 2 3 4 4 5
    handRank[2] = handRank[4];  // 2 3 5 4 5
    handRank[4] = handRank[3];  // 2 3 5 4 4
    return 1;
  }
  else if (handRank[3] == handRank[4]) {  // 4 and 5 are a pair
    // EXAMPLE: 2 3 4 5 5
    return 1;
  }
  else
    return 0;

}