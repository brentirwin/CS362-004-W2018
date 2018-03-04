/***************************************************************
* Filname: cardtest1.c
* Author: Brent Irwin
* Date: 28 January 2018
* Description: Unit Test drawCard() 
***************************************************************/

#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int assert(int a, int b) {
	if (a == b) {
		printf("TEST SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED\n");
		return 0;
	}
}

void resetDeck(struct gameState *G) {
	int i;
	for (i=0; i<MAX_HAND; i++)
		G->hand[1][i] = -1;
	for (i=0; i<MAX_DECK; i++)
		G->hand[1][i] = -1;
}

int main() {
	// Create variables
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(0));
	int seed = rand();
	int card, i;

	// Initialize game
	initializeGame(2, k, seed, &G);

	// Draw top card from deck
	printf("Draw top card from deck\n");
	card = k[rand()%10];
	G.deck[1][0] = card;
	drawCard(1, &G);
	for (i=0; i<5; i++) {
		printf("%i ", G.hand[1][i]);
	}
	printf("- %i ", card);
	assert(G.hand[1][0], card);
	resetDeck(&G);

	// Empty deck, discard only
	printf("Empty deck, discard only\n");
	card = k[rand()%10];
	G.discard[1][0] = card;
	drawCard(1, &G);
	for (i=0; i<5; i++) {
		printf("%i ", G.hand[1][i]);
	}
	printf("- %i ", card);
	assert(G.hand[1][0], card);
	resetDeck(&G);

	// Empty deck and empty discard
	printf("Empty deck and empty discard pile\n");
	for (i=0; i<5; i++) {
		printf("%i ", G.hand[1][i]);
	}
	printf("- %i ", card);
	assert(drawCard(1, &G), -1);

	return 0;
}
