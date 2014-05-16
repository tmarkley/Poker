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

int Hand::StraightFlush() {

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