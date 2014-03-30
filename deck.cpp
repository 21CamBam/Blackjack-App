#include "deck.h"

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// class Constructor
// Initialize random number generator.
// Set num_dealt to zero and set the values in the deck
// array to the integers between 0 to 51.
Deck::Deck(void) {
	int i;
	srand(time(NULL));
	num_dealt = 0;
	for (i = 0; i < 52; i++) {
		deck[i] = i;
	}
};

// Reset deck to new state (completely undealt).
void Deck::reset(void) {
	int i;
	num_dealt = 0;
	for (i = 0; i < 52; i++) {
		deck[i] = i;
	}
};

// Print all cards (undealt and dealt).
void Deck::print_all(void) {
	int i, pip, suit_num;

	for (i = 0; i < 52; i++) {

		pip = deck[i] % 13;
		suit_num = deck[i] / 13;

		if (suit_num == 0) { //Heart
			if (pip == 0) {
				cout << "Ace of Hearts" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Hearts" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Hearts" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Hearts" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Hearts" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Hearts" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Hearts" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Hearts" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Hearts" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Hearts" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Hearts" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Hearts" << endl;
			}
			else {
				cout << "King of Hearts" << endl;
			}
		}
		else if (suit_num == 1) { //Club
			if (pip == 0) {
				cout << "Ace of Clubs" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Clubs" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Clubs" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Clubs" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Clubs" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Clubs" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Clubs" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Clubs" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Clubs" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Clubs" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Clubs" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Clubs" << endl;
			}
			else {
				cout << "King of Clubs" << endl;
			}
		}
		else if (suit_num == 2) { //Diamond
			if (pip == 0) {
				cout << "Ace of Diamonds" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Diamonds" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Diamonds" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Diamonds" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Diamonds" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Diamonds" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Diamonds" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Diamonds" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Diamonds" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Diamonds" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Diamonds" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Diamonds" << endl;
			}
			else {
				cout << "King of Diamonds" << endl;
			}
		}
		else { //Spade
			if (pip == 0) {
				cout << "Ace of Spades" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Spades" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Spades" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Spades" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Spades" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Spades" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Spades" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Spades" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Spades" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Spades" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Spades" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Spades" << endl;
			}
			else {
				cout << "King of Spades" << endl;
			}
		}
	}
}

// Print undealt cards.
void Deck::print_undealt(void) {
	int i, pip, suit_num;

	for (i = 52 - num_dealt; i < 52; i++) {
		pip = deck[i] % 13;
		suit_num = deck[i] / 13;

		if (suit_num == 0) { //Heart
			if (pip == 0) {
				cout << "Ace of Hearts" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Hearts" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Hearts" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Hearts" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Hearts" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Hearts" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Hearts" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Hearts" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Hearts" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Hearts" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Hearts" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Hearts" << endl;
			}
			else {
				cout << "King of Hearts" << endl;
			}
		}
		else if (suit_num == 1) { //Club
			if (pip == 0) {
				cout << "Ace of Clubs" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Clubs" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Clubs" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Clubs" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Clubs" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Clubs" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Clubs" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Clubs" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Clubs" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Clubs" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Clubs" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Clubs" << endl;
			}
			else {
				cout << "King of Clubs" << endl;
			}
		}
		else if (suit_num == 2) { //Diamond
			if (pip == 0) {
				cout << "Ace of Diamonds" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Diamonds" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Diamonds" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Diamonds" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Diamonds" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Diamonds" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Diamonds" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Diamonds" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Diamonds" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Diamonds" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Diamonds" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Diamonds" << endl;
			}
			else {
				cout << "King of Diamonds" << endl;
			}
		}
		else { //Spade
			if (pip == 0) {
				cout << "Ace of Spades" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Spades" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Spades" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Spades" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Spades" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Spades" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Spades" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Spades" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Spades" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Spades" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Spades" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Spades" << endl;
			}
			else {
				cout << "King of Spades" << endl;
			}
		}
	}
}

// Print dealt cards.
void Deck::print_dealt(void) {
	int i, pip, suit_num;

	for (i = 0; i < 52 - num_dealt; i++) {
		pip = deck[i] % 13;
		suit_num = deck[i] / 13;

		if (suit_num == 0) { //Heart
			if (pip == 0) {
				cout << "Ace of Hearts" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Hearts" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Hearts" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Hearts" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Hearts" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Hearts" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Hearts" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Hearts" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Hearts" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Hearts" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Hearts" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Hearts" << endl;
			}
			else {
				cout << "King of Hearts" << endl;
			}
		}
		else if (suit_num == 1) { //Club
			if (pip == 0) {
				cout << "Ace of Clubs" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Clubs" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Clubs" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Clubs" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Clubs" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Clubs" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Clubs" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Clubs" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Clubs" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Clubs" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Clubs" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Clubs" << endl;
			}
			else {
				cout << "King of Clubs" << endl;
			}
		}
		else if (suit_num == 2) { //Diamond
			if (pip == 0) {
				cout << "Ace of Diamonds" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Diamonds" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Diamonds" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Diamonds" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Diamonds" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Diamonds" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Diamonds" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Diamonds" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Diamonds" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Diamonds" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Diamonds" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Diamonds" << endl;
			}
			else {
				cout << "King of Diamonds" << endl;
			}
		}
		else { //Spade
			if (pip == 0) {
				cout << "Ace of Spades" << endl;
			}
			else if (pip == 1) {
				cout << "2 of Spades" << endl;
			}
			else if (pip == 2) {
				cout << "3 of Spades" << endl;
			}
			else if (pip == 3) {
				cout << "4 of Spades" << endl;
			}
			else if (pip == 4) {
				cout << "5 of Spades" << endl;
			}
			else if (pip == 5) {
				cout << "6 of Spades" << endl;
			}
			else if (pip == 6) {
				cout << "7 of Spades" << endl;
			}
			else if (pip == 7) {
				cout << "8 of Spades" << endl;
			}
			else if (pip == 8) {
				cout << "9 of Spades" << endl;
			}
			else if (pip == 9) {
				cout << "10 of Spades" << endl;
			}
			else if (pip == 10) {
				cout << "Jack of Spades" << endl;
			}
			else if (pip == 11) {
				cout << "Queen of Spades" << endl;
			}
			else {
				cout << "King of Spades" << endl;
			}
		}
	}
}

// Deal a single card.
int Deck::deal_card(void) {
	int num, tmp, last;

	num = (rand() % 52) - num_dealt;
	last = 51 - num_dealt;

	tmp = deck[last];
	deck[last] = num;
	deck[num] = tmp;

	num_dealt++;

	return num;
}
