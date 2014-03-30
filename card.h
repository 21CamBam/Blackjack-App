#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>
#include <string>
using namespace std;

class Card {
public:
	// Get card value.
	int get(void);

	// Set card value.
	void set(int the_value);

	// Print card value.
	void print(void);

private:
	int value;
}; // end class Card

#endif // __CARD_H__
