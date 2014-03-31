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

class Blackjack : public Hand
{
public:
	Blackjack(void);

	void play_game(void)
	{
		string reply;
		int player_sum = 0, dealer_sum = 0;

		do
		{
			status = GOOD;
			player_sum = 0;
			dealer_sum = 0;
			deck.reset();

			player.new_hand(deck);
			dealer.new_hand(deck);

			cout << "\nDealer" << endl;
			dealer.print_dealer();
			cout << "\nPlayer" << endl;
			player.print();

			evaluate_player(&dealer_sum, &player_sum);
			if (status != BLACKJACK)
			{
				evaluate_dealer(&dealer_sum, &player_sum);
			}
			else
			{
				next_move(&dealer_sum, &player_sum);
				continue;
			}

			if (status == WIN)
			{
				next_move(&dealer_sum, &player_sum);
				continue;
			}
			if (status == PUSH)
			{
				next_move(&dealer_sum, &player_sum);
				continue;
			}

			if (status != BUST)
			{
				next_move(&dealer_sum, &player_sum);
			}
			else
			{
				next_move(&dealer_sum, &player_sum);
				continue;
			}

			cout << "Play again? [yes or no]: ";
			cin >> reply;
		} while (reply[0] == 'y' || reply[0] == 'Y');

	}

	void next_move(int *dealer_sum, int *player_sum)
	{
		string answer;
		if (status == BLACKJACK)
		{
			cout << "\nDealer" << endl;
			dealer.print();
			cout << "Total: " << *dealer_sum << endl;

			cout << "\nPlayer" << endl;
			player.print();
			cout << "Total: " << *player_sum << endl;
			cout << "\n\nBLACKJACK!!!" << endl;
			return;
		}

		if (status == WIN)
		{
			cout << "\nDealer" << endl;
			dealer.print();
			cout << "Total: " << *dealer_sum << endl;
			cout << "\nPlayer" << endl;
			player.print();
			cout << "Total: " << *player_sum << endl;
			cout << "\n\nWINNER!!!" << endl;
			return;
		}

		if (status == BUST)
		{
			cout << "\nDealer" << endl;
			dealer.print();
			cout << "Total: " << *dealer_sum << endl;
			cout << "\nPlayer" << endl;
			player.print();
			cout << "Total: " << *player_sum << endl;
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
				cout << "\n\nHit, Double Down or Stay" << endl;
				cin >> answer;
				if (answer[0] == 'H' || answer[0] == 'h')
				{
					*player_sum = hit(dealer_sum, player_sum);
					return;
				}
				else if (answer[0] == 'S' || answer[0] == 's')
				{
					cout << "\nDealer" << endl;
					dealer.print();
					cout << "Total: " << *dealer_sum << endl;
					cout << "\nPlayer" << endl;
					player.print();
					cout << "Total: " << player_sum << endl;
					compare_hands(dealer_sum, player_sum);
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
				cout << "\n\nHit or Stay" << endl;
				cin >> answer;
				if (answer[0] == 'H' || answer[0] == 'h')
				{
					*player_sum = hit(dealer_sum, player_sum);
					return;
				}
				else if (answer[0] == 'S' || answer[0] == 's')
				{
					cout << "\nDealer" << endl;
					dealer.print();
					cout << "Total: " << *dealer_sum << endl;
					cout << "\nPlayer" << endl;
					player.print();
					cout << "Total: " << player_sum << endl;
					compare_hands(dealer_sum, player_sum);
					return;
				}
			}
		}
	}

	int hit(int *dealer_sum, int *player_sum)
	{
		int sum = 0;
		player.new_card(deck, player.num_cards);
		player.num_cards++;
		player.print();

		for (int i = 0; i < player.num_cards; i++)
		{
			sum += card_value((player.hand)[i]);
		}
		*player_sum = sum;
		cout << "Total: " << sum << endl;

		if (sum > 21)
		{
			status = BUST;
			next_move(dealer_sum, player_sum);
			return sum;
		}
		else
		{
			status = GOOD;
			next_move(dealer_sum, player_sum);
			return sum;
		}
	}

	int draw(int *dealer_sum, int *player_sum)
	{
		int sum = 0;
		dealer.new_card(deck, dealer.num_cards);
		dealer.num_cards++;

		for (int i = 0; i < dealer.num_cards; i++)
		{
			sum += card_value((dealer.hand)[i]);
		}
		*dealer_sum = sum;
		if (sum > 21)
		{
			status = WIN;
			next_move(dealer_sum, player_sum);
			return sum;
		}
		else
		{
			status = GOOD;
			next_move(dealer_sum, player_sum);
			return sum;
		}
	}

	int card_value(Card &duece)
	{
		int val = duece.get() % 13;

		if (val > 0 && val < 9) // If the card is 2 - 10
			return val++;

		if (val >= 9)
			return 10;

		if (val == 0)
			return 11;

		return 0;
	}

	void check_hand_for_double(void)
	{
		int card1 = card_value((player.hand)[0]), card2 = card_value((player.hand)[1]) + 1;
		if (card1 == 10 || card2 == 10)
		{
			doubsplit = DOUBLE;
			return;
		}
		doubsplit = NOTHING;
		return;
	}

	void evaluate_dealer(int *dealer_sum, int *player_sum)
	{
		int sum = 0;
		for (int i = 0; i < dealer.num_cards; i++)
		{
			sum += card_value((dealer.hand)[i]);
		}
		*dealer_sum = sum;
		if (*dealer_sum == 21)
		{
			status = BUST;
			next_move(dealer_sum, player_sum);
		}

		while (*dealer_sum < 17)
		{
			*dealer_sum = draw(dealer_sum, player_sum);
		}
		if (*dealer_sum > 21)
		{
			status = WIN;
			return;
		}
		return;
	}

	void evaluate_player(int *dealer_sum, int *player_sum)
	{
		int sumd = 0, i;
		for (i = 0; i < player.num_cards; i++)
		{
			sumd += card_value((player.hand)[i]);
		}
		*player_sum = sumd;
		if (sumd == 21)
		{
			status = BLACKJACK;
		}
		return;
	}

	void compare_hands(int *dealer_sum, int *player_sum)
	{
		int sumd = 0, sump = 0;
		for (int i = 0; i <= dealer.num_cards; i++)
		{
			sumd += card_value((dealer.hand)[i]);
		}
		for (int i = 0; i <= player.num_cards; i++)
		{
			sump += card_value((player.hand)[i]);
		}

		if (sumd == sump)
		{
			status = PUSH;
			next_move(dealer_sum, player_sum);
			return;
		}
		else if (sumd > sump)
		{
			status = BUST;
			next_move(dealer_sum, player_sum);
			return;
		}
		else
		{
			status = WIN;
			next_move(dealer_sum, player_sum);
			return;
		}
	}

	Hand player;
	Hand dealer;
};

#endif
