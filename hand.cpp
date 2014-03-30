#include "hand.h"

#include <iostream>
#include <string>

// Get all new cards.
void Hand::new_hand(Deck &deck) {
	int i, card;
	num_cards = 0;
	for (i = 0; i < 2; i++) {
		card = deck.deal_card();
		hand[i].set(card);
		num_cards++;
	}
}

/*// Determine cards to exchange and exchange them.
void Hand::exchange_cards(Deck &deck) {
	int i, num_cards, card, num;

	cout << "How many cards would you like to exchange <0 - 5>?" << endl;
	cin >> num_cards;

	if (num_cards <= 5) {
		for (i = 0; i < num_cards; i++) {
			cout << "Enter position in hand of card [1 - 5]" << endl;
			cin >> num;

			new_card(deck, num - 1);
		}
	}
	else {
		exchange_cards(deck);
		return;
	}
	return;
}*/

// Put new card from deck into given location.
void Hand::new_card(Deck &deck, int location) {
	int i, num_cards, card, num;

	card = deck.deal_card();
	hand[location].set(card);
}

// Print the hand.
void Hand::print(void) {
	int i, pip, suit_num;

	for (i = 0; i < num_cards; i++) {
		pip = hand[i].get() % 13;
		suit_num = hand[i].get() / 13;

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

void Hand::print_dealer(void)
{
	int pip, suit_num;
	pip = hand[0].get() % 13;
	suit_num = hand[0].get() / 13;

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

	cout << "???" << endl;
}
