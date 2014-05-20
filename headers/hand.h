#ifndef _HAND_
#define _HAND_

#include <vector>
#include <iostream>
using namespace std;

#include "card.h"

class Hand {

	vector<Card *> hand;

	int handRank[6]; // keeps track of ranking order for each hand
	string bestHand;
	double percentage; // chance of winnning with the hand

public:
	vector<Card *> getCards();
	string getCard(int);
	void addCard(Card);
	void clearHand();

	void rigHand();
	void findPercentages(int);
	int getHandRank(int index = 5);
	string getBestHand();
	double getHandPercentage();

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

};

#endif //_HAND_