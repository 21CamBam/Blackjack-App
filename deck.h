#ifndef __DECK_H__
#define __DECK_H__

#include <time.h>

class Deck {
public:
	// class Constructor
	// Initialize random number generator.
	// Set num_dealt to zero and set the values in the deck
	// array to the integers between 0 to 51.
	Deck(void);

	// Reset deck to new state (completely undealt).
	void reset(void);

	// Print all cards (undealt and dealt).
	void print_all(void);

	// Print undealt cards.
	void print_undealt(void);

	// Print dealt cards.
	void print_dealt(void);

	// Deal a single card.
	int deal_card(void);

private:
	int deck[52];   // Cards are represented as ints.
	int num_dealt;  // Number of cards that have been dealt.
}; // end class Deck

#endif // __DECK_H__
