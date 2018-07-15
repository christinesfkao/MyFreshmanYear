//HW5 10.10 Card Shuffling and Dealing
//Card.cpp

#include <iostream>
#include <cstdlib>
#include <string>

#include "Card.h"

using namespace std;

const string Card::arrayFace[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const string Card::arraySuit[4] = {"Spade(s)", "Heart(s)", "Diamond(s)", "Club(s)"};

Card::Card(int f, int s)
{
	setCard(f, s);
}

void Card::setCard(int f, int s)
{
	while (f > 13 && f <= 0 && s > 4 && s <= 0)
		cout << "The numbers you entered are invalid. Please try again.";
	
	face = f;
	suit = s;
}

string Card::toString()
{
	return arrayFace[face] + " of " + arraySuit[suit];
}
