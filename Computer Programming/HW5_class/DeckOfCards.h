//HW5 10.10 Card Shuffling and Dealing
//DeckOfCards.h

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include <vector>
using namespace std;

class DeckOfCards
{
public:
	DeckOfCards(); //constructor
	void shuffle(); //randomly select a card and swap
	Card dealCard(); //returns the next card from the deck
	bool moreCards(); //whether there are more cards to deal
	
private:
	vector< Card > deck; //to store the cards
	int currentCard;  //representing the next card to deal
};

#endif
