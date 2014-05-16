#include "../headers/card.h"

Card::Card(string image) {

  imageName = image;

  if (imageName[0] == 'A')
    rank = 14;
  else if (imageName[0] == 'T')
    rank = 10;
  else if (imageName[0] == 'J')
    rank = 11;
  else if (imageName[0] == 'Q')
    rank = 12;
  else if (imageName[0] == 'K')
    rank = 13;
  else
    rank = (int)imageName[0] - (int)'0';

  if (imageName[2] == 'c')
    suit = Clubs;
  else if (imageName[2] == 'd')
    suit = Diamonds;
  else if (imageName[2] == 'h')
    suit = Hearts;
  else
    suit = Spades;
    
}

Suit Card::getSuit() {

  return suit;

}

int Card::getRank() {

  return rank;

}

string Card::getImageName() {

  return imageName;

}