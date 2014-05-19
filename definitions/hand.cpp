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

  int rank = 0;
  if ((rank = StraightFlush()) != -1) {
    highRank = rank;
    bestHand = "Straight Flush";
    return 8;
  }
  else if ((rank = FourOfAKind()) != -1) {
    highRank = rank;
    bestHand = "Four Of A Kind";
    return 7;
  }
  else if ((rank = FullHouse()) != -1) {
    highRank = rank;
    bestHand = "Full House";
    return 6;
  }
  else if ((rank = Flush()) != -1) {
    highRank = rank;
    bestHand = "Flush";
    return 5;
  }
  else if ((rank = Straight()) != -1) {
    highRank = rank;
    bestHand = "Straight";
    return 4;
  }
  else if ((rank = ThreeOfAKind()) != -1) {
    highRank = rank;
    bestHand = "Three Of A Kind";
    return 3;
  }
  else if ((rank = TwoPair()) != -1) {
    highRank = rank;
    bestHand = "Two Pair";
    return 2;
  }
  else if ((rank = OnePair()) != -1) {
    highRank = rank;
    bestHand = "One Pair";
    return 1;
  }
  else {
    highRank = HighCard();
    bestHand = "High Card";
    return 0;
  }

}

string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
string faceCards[] = {"Jack", "Queen", "King", "Ace"};

void Hand::printHand() {
  cout << endl;
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

int Hand::getHighRank() {

  return highRank;

}

string Hand::getBestHand() {

  return bestHand;

}

int Hand::StraightFlush() {
  int highestCard = hand[4]->getRank();
  int secondHighest = hand[3]->getRank();
  int suit = hand[4]->getSuit();
  int decrementer = highestCard;
  for (int i = 0; i < 4; ++i) {
    if (hand[i]->getSuit() != suit) {
      // cout << "Wrong suit" << endl;
      return -1;
    }
  }
  if (highestCard == 14) { // Ace
    // cout << "Ace ";
    if (secondHighest == 5) { // Ace is low
      // cout << "low ";
      for (int i = 2; i >= 0; --i) { // check lower 3 cards
        if (hand[i]->getRank() != --secondHighest) {
          // cout << hand[i]->getRank() << endl;
          // cout << "not flush" << endl;
          return -1;
        }
      }
      // cout << "flush" << endl;
      return 5; // Straight flush with Ace low
    }
    else { // Ace is high
      // cout << "high ";
      for (int i = 3; i >= 0; --i) { // check lower 4 cards
        if (hand[i]->getRank() != --decrementer) {
          // cout << "not flush" << endl;
          return -1;
        }
      }
      // cout << "royal flush" << endl;
      return highestCard;
    }
  }
  else { // regular run of cards with Ace high
    // cout << "No ace ";
    for (int i = 3; i >= 0; --i) { // check lower 4 cards
      if (hand[i]->getRank() != --decrementer) {
        // cout << "not flush" << endl;
        return -1;
      }
    }
    // cout << "flush" << endl;
    return highestCard;
  }
  return -1;
}

int Hand::FourOfAKind() {

  return -1;

}
int Hand::FullHouse() {

  return -1;

}

int Hand::Flush() {

  return -1;

}

int Hand::Straight() {

  return -1;

}

int Hand::ThreeOfAKind() {

  return -1;

}

int Hand::TwoPair() {

  return -1;

}

int Hand::OnePair() {

  return -1;

}

int Hand::HighCard() {

  return -1;

}