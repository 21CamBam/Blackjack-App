#ifndef BJ_MAIN_H
#define BJ_MAIN_H

#include "deck.h"
#include "card.h"
#include "hand.h"

typedef enum Status
{
	BUST, WIN, GOOD, BLACKJACK, PUSH // Note: DOUBLE and SPLIT are both GOOD
};

typedef enum DoubSplit
{
	NOTHING, DOUBLE
};

Deck deck;
Status status;
DoubSplit doubsplit;

int player_sum = 0, dealer_sum = 0;

class Blackjack : public Hand
{
public:
	Blackjack(void);

	void play_game(void)
	{
		string reply;
		do
		{
			status = GOOD;
			player_sum = 0;
			dealer_sum = 0;

			player.new_hand(deck);
			dealer.new_hand(deck);

			cout << "\nDealer" << endl;
			dealer.print_dealer();
			cout << "\nPlayer" << endl;
			player.print();

			evaluate_player();
			if (status != BLACKJACK)
				evaluate_dealer();

			if (status != BUST)
				next_move();

			cout << "Play again? [yes or no]: ";
			cin >> reply;
		} while (reply[0] == 'y' || reply[0] == 'Y');

	}

	void next_move(void)
	{
		string answer;
		if (status == BLACKJACK)
		{
			cout << "\nDealer" << endl;
			dealer.print();
			cout << "Total: " << dealer_sum << endl;
			cout << "\nPlayer" << endl;
			player.print();
			cout << "Total: " << player_sum << endl;
			cout << "\n\nBLACKJACK!!!" << endl;
			return;
		}

		if (status == WIN)
		{
			cout << "\nDealer" << endl;
			dealer.print();
			cout << "Total: " << dealer_sum << endl;
			cout << "\nPlayer" << endl;
			player.print();
			cout << "Total: " << player_sum << endl;
			cout << "\n\nWINNER!!!" << endl;
			return;
		}

		if (status == BUST)
		{
			cout << "\nDealer" << endl;
			dealer.print();
			cout << "Total: " << dealer_sum << endl;
			cout << "\nPlayer" << endl;
			player.print();
			cout << "Total: " << player_sum << endl;
			cout << "\n\nLOSER!!!" << endl;
			return;
		}

		if (status == PUSH)
		{
			cout << "\n--PUSH--" << endl;
			return;
		}
		
		if (status == GOOD)
		{			
			check_hand_for_double();
			if (doubsplit == DOUBLE)
			{
				cout << "Hit, Double Down or Stay" << endl;
				cin >> answer;
				if (answer[0] == 'H' || answer[0] == 'h')
				{
					player_sum = hit();
					return;
				}
				else if (answer[0] == 'S' || answer[0] == 's')
				{
					cout << "\nDealer" << endl;
					dealer.print();
					cout << "Total: " << dealer_sum << endl;
					cout << "\nPlayer" << endl;
					player.print();
					cout << "Total: " << player_sum << endl;
					compare_hands();
					return;
				}
				else
				{
					/////////////////////////////////////////////////////////////////////Double Down
					return;
				}
			}
			else
			{
				cout << "Hit or Stay" << endl;
				cin >> answer;
				if (answer[0] == 'H' || answer[0] == 'h')
				{
					player_sum = hit();
					return;
				}
				else if (answer[0] == 'S' || answer[0] == 's')
				{
					cout << "\nDealer" << endl;
					dealer.print();
					cout << "Total: " << dealer_sum << endl;
					cout << "\nPlayer" << endl;
					player.print();
					cout << "Total: " << player_sum << endl;
					compare_hands();
					return;
				}
			}
		}
	}

	int hit(void)
	{
		int sum = 0;
		player.new_card(deck, player.num_cards);
		player.num_cards++;
		player.print();

		for (int i = 0; i <= player.num_cards; i++)
		{
			sum += card_value((player.hand)[i]);
		}

		cout << "Total: " << sum << endl;

		if (sum > 21)
		{
			status = BUST;
			next_move();
			return sum;
		}
		else
		{
			status = GOOD;
			next_move();
			return sum;
		}
	}

	int draw(void)
	{
		int sum = 0;
		dealer.new_card(deck, dealer.num_cards);
		dealer.num_cards++;
		dealer.print();

		for (int i = 0; i <= dealer.num_cards; i++)
		{
			sum += card_value((dealer.hand)[i]);
		}

		cout << "Total: " << sum << endl;

		if (sum > 21)
		{
			status = WIN;
			next_move();
			return sum;
		}
		else
		{
			status = GOOD;
			next_move();
			return sum;
		}
	}

	int card_value(Card &duece)
	{
		int val = duece.get() % 13;

		if (val > 0 && val < 10) // If the card is 2 - 10
			return val++;

		if (val >= 10)
			return 10;

		if (val == 0)
			return 11;
	}

	void check_hand_for_double(void)
	{
		int card1 = card_value((player.hand)[0]), card2 = card_value((player.hand)[1]);
		if (card1 == 10 || card2 == 10)
		{
			doubsplit = DOUBLE;
			return;
		}
		doubsplit = NOTHING;
		return;
	}

	void evaluate_dealer(void)
	{
		for (int i = 0; i < dealer.num_cards; i++)
		{
			dealer_sum += card_value((dealer.hand)[i]);
		}

		if (dealer_sum == 21)
		{
			status = BUST;
			next_move();
		}

		while (dealer_sum < 17)
		{
			draw();
			cout << "Dealer" << endl;
			dealer.print();
			cout << "Total: " << dealer_sum << endl;
			for (int i = 0; i <= dealer.num_cards; i++)
			{
				dealer_sum += card_value((dealer.hand)[i]);
			}
		}
		if (dealer_sum > 21)
		{
			status = WIN;
			return;
		}
		return;
	}

	void evaluate_player(void)
	{
		int sumd = 0, i;
		for (i = 0; i < player.num_cards; i++)
		{
			sumd += card_value((player.hand)[i]);
		}

		if (sumd == 21)
		{
			status = BLACKJACK;
		}
		return;
	}

	void compare_hands(void)
	{
		int sumd = 0, sump = 0;
		for (int i = 0; i <= card_value((dealer.hand)[i]); i++)
		{
			sumd += card_value((dealer.hand)[i]);
		}
		for (int i = 0; i <= card_value((player.hand)[i]); i++)
		{
			sump += card_value((player.hand)[i]);
		}

		if (sumd == sump)
		{
			status = PUSH;
			return;
		}
		else if (sumd > sump)
		{
			status = BUST;
			return;
		}
		else
		{
			status = WIN;
			return;
		}
	}

	Hand player;
	Hand dealer;
};

#endif
