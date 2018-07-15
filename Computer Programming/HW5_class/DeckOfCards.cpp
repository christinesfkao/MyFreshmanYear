//HW5 10.10 Card Shuffling and Dealing
//DeckOfCards.cpp

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

DeckOfCards::DeckOfCards()
	:currentCard(0)
{
	for (int f = 0; f < 13; f++)
	{
		for (int s = 0; s < 4; s++){
			Card card(f, s);
			deck.push_back( card );
		}
	}

	shuffle();
	
	cout << setw (6) << "Number" << setw(20) << "Card" << setw(15) << "More cards?" << endl;
	while (currentCard <= 51)
		cout << setw(6) << currentCard << setw(20) << dealCard().toString() << setw(10) << moreCards() << endl;
}

void DeckOfCards::shuffle()
{
	srand( time(NULL) );
	
	int randomPick = rand() % 52;
	
	for (int seq = 0; seq < 52; seq++)
	{
		randomPick = rand() % 52;

		//swap the two cards
		Card hold = deck[seq];
		deck[seq] = deck[randomPick];
		deck[randomPick] = hold;
	} 
}

Card DeckOfCards::dealCard()
{
	currentCard++;

	return deck[currentCard-1];
}

bool DeckOfCards::moreCards()
{
	if (currentCard != 51)
		return true;
	else
		return false;	
}
