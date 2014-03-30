// game.cpp
/* A poker generator. */

#include <iostream>
#include <string>

#include "BlackJackMain.h"

using namespace std;

Blackjack::Blackjack()
{
	player.new_hand(deck);
	dealer.new_hand(deck);
}

int main() {
	Blackjack game = Blackjack();
	game.play_game();

	return 0;
}
