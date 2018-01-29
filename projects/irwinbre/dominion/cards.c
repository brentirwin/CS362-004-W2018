#include "cards.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int card_adventurer(int* drawntreasure, struct gameState *state, int currentPlayer, int* cardDrawn, int* temphand, int* z) {
	while (*drawntreasure < 2) {
		if (state->deckCount[currentPlayer] < 1) { // if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		*cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1]; // top card of hand is most recently drawn card.
		if (*cardDrawn == copper || *cardDrawn == silver || *cardDrawn == gold)
			(*drawntreasure)++;
		else {
			temphand[*z] = *cardDrawn;
			state->handCount[currentPlayer]--; // this should just remove the top card (the most recently drawn one).
			(*z)++;
		}
	}
	while (z-1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[*z-1]; // discard all cards in play that have been drawn
		*z = *z-1;
	}
	return 0;
}

int card_smithy(int currentPlayer, struct gameState *state, int handPos) {
	// +3 Cards
	int i;
	for (i=1; i<3; i++) {
		drawCard(currentPlayer, state);
	}

	// discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}

int card_village(int currentPlayer, struct gameState *state, int handPos) {
	// +1 Card
	drawCard(currentPlayer, state);

	// +2 Actions
	state->numActions = state->numActions + 2;

	// discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}

int card_great_hall(int currentPlayer, struct gameState *state, int handPos) {
	// +1 Card
	drawCard(currentPlayer, state);

	// +1 Actions
	state->numActions++;

	// discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}

int card_steward(int choice1, int choice2, int choice3, int currentPlayer, struct gameState *state, int handPos) {
	if (choice1 == 1) {
		// +2 cards
		drawCard(currentPlayer, state);
		drawCard(currentPlayer, state);
	}
	else if (choice1 == 2) {
		// +2 coins
		state->coins = state->coins + 2;
	}
	else {
		// trash 2 cards in hand
		discardCard(choice2, currentPlayer, state, 1);
		discardCard(choice3, currentPlayer, state, 1);
	}
	
	// discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}
