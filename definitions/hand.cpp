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
    if (secondHighest == 5) { // Ace is low
      for (int i = 2; i >= 0; --i) { // check lower 3 cards
        if (hand[i]->getRank() != --secondHighest) {
          return -1;
        }
      }
      return 5; // Straight flush with Ace low
    }
    else { // Ace is high
      for (int i = 3; i >= 0; --i) { // check lower 4 cards
        if (hand[i]->getRank() != --decrementer) {
          return -1;
        }
      }
      return highestCard;
    }
  }
  else { // regular run of cards with Ace high
    for (int i = 3; i >= 0; --i) { // check lower 4 cards
      if (hand[i]->getRank() != --decrementer) {
        return -1;
      }
    }
    return highestCard;
  }
  return -1;
}

int Hand::FourOfAKind() {
  int rank[5];
  for (int i = 0; i < 5; ++i)
    rank[i] = hand[i]->getRank();
  if (rank[0] == rank[1] && rank[1] == rank[2] && rank[2] == rank[3]) {
    return rank[0];
  }
  else if (rank[1] == rank[2] && rank[2] == rank[3] && rank[3] == rank[4]) {
    return rank[1];
  }
  else {
    return -1;
  }

}
int Hand::FullHouse() {
  int rank[5];
  for (int i = 0; i < 5; ++i)
    rank[i] = hand[i]->getRank();
  if (rank[0] == rank[1]) {   // first pair the same
    if (rank[1] == rank[2]) { // first three the same
      if (rank[3] == rank[4]) // last two the same
        return rank[0];
      else
        return -1;
    }
    else {                    // first three not the same
      if (rank[2] == rank[3] && rank[3] == rank[4]) // last three the same
        return rank[4];
      else
        return -1;
    }
  }
  else
    return -1;
}

int Hand::Flush() {
  int suit[5];
  for (int i = 0; i < 5; ++i)
    suit[i] = hand[i]->getSuit();
  if (suit[0] == suit[1] && suit[1] == suit[2] && suit[2] == suit[3] && suit[3] == suit[4])
    return hand[4]->getRank();
  else {
    return -1;
  }

}

int Hand::Straight() {
  int highestCard = hand[4]->getRank();
  int secondHighest = hand[3]->getRank();
  int decrementer = highestCard;
  if (highestCard == 14) { // Ace
    if (secondHighest == 5) { // Ace is low
      for (int i = 2; i >= 0; --i) { // check lower 3 cards
        if (hand[i]->getRank() != --secondHighest) {
          return -1;
        }
      }
      return 5; // Straight flush with Ace low
    }
    else { // Ace is high
      for (int i = 3; i >= 0; --i) { // check lower 4 cards
        if (hand[i]->getRank() != --decrementer) {
          return -1;
        }
      }
      return highestCard;
    }
  }
  else { // regular run of cards with Ace high
    for (int i = 3; i >= 0; --i) { // check lower 4 cards
      if (hand[i]->getRank() != --decrementer) {
        return -1;
      }
    }
    return highestCard;
  }
  return -1;

}

int Hand::ThreeOfAKind() {
  int rank[5];
  for (int i = 0; i < 5; ++i)
    rank[i] = hand[i]->getRank();
  if (rank[0] == rank[1] && rank[1] == rank[2])
    return rank[0];
  else if (rank[1] == rank[2] && rank[2] == rank[3])
    return rank[1];
  else if (rank[2] == rank[3] && rank[3] == rank[4])
    return rank[2];
  else
    return -1;

}

int Hand::TwoPair() {
  int rank[5];
  for (int i = 0; i < 5; ++i)
    rank[i] = hand[i]->getRank();
  if (rank[0] == rank[1]) {
    if (rank[2] == rank[3])
      return rank[3];
    else if (rank[3] == rank[4])
      return rank[4];
  }
  else if (rank[1] == rank[2]) {
    if (rank[3] == rank[4])
      return rank[4];
  }
  else
    return -1;
  return -1;
}

int Hand::OnePair() {
  int rank[5];
  for (int i = 0; i < 5; ++i)
    rank[i] = hand[i]->getRank();
  if (rank[0] == rank[1])
    return rank[0];
  else if (rank[1] == rank[2])
    return rank[1];
  else if (rank[2] == rank[3])
    return rank[2];
  else if (rank[3] == rank[4])
    return rank[3];
  else
    return -1;

}

int Hand::HighCard() {

  return hand[4]->getRank();

}