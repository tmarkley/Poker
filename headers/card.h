#ifndef _CARD_
#define _CARD_

#include <string>
using namespace std;

enum Suit {Clubs, Diamonds, Hearts, Spades};

class Card {

	Suit suit;
	int rank;
	string imageName;

public:
	Card(string);
	Suit getSuit();
	int getRank();
	string getImageName();
};


#endif //_CARD_