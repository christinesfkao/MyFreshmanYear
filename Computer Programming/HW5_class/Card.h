//HW5 10.10 Card Shuffling and Dealing
//Card.h

#include <string>

using namespace std;

//prevent multiple inclusions of header file
#ifndef CARD_H
#define CARD_H

class Card
{
public:
	Card(int, int); //constructor
	void setCard(int, int); //set function
		
	string toString();
	
private:
	int face;
	int suit;	
	static const string arrayFace[13];
	static const string arraySuit[4];
};

#endif
