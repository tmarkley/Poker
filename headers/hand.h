#ifndef _HAND_
#define _HAND_

#include <vector>
#include <iostream>
using namespace std;

#include "card.h"

class Hand {

	vector<Card *> hand;

	int highRank; // keeps track of highest card in best hand
	string bestHand;

public:
	vector<Card *> getCards();
	string getCard(int index);
	void addCard(Card);
	void clearHand();

	void rigHand();
	int getHighRank();
	string getBestHand();

	void printHand();
	int findBestHand();
	int StraightFlush();
	int FourOfAKind();
	int FullHouse();
	int Flush();
	int Straight();
	int ThreeOfAKind();
	int TwoPair();
	int OnePair();
	int HighCard();

};

#endif //_HAND_