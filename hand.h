#ifndef __HAND_H_
#define __HAND_H_

#include "deck.h"
#include "card.h"

class Hand {
public:
	// Get all new cards.
	void new_hand(Deck &deck);

	// Determine cards to exchange and exchange them.
	//void exchange_cards(Deck &deck);

	// Put new card from deck into given location.
	void new_card(Deck &deck, int location);

	// Print the player hand.
	void print(void);

	// Print the dealer hand.
	void print_dealer(void);

	int size(void);


	Card hand[10];  // A Hand consists of 2 Cards.
	int num_cards = -2;
}; // end class Hand

#endif // __HAND_H__
