/***************************************************************
* Filname: cardtest1.c
* Author: Brent Irwin
* Date: 28 January 2018
* Description: Unit Test fullDeckCount(int player, int card, gameState*) 
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
	printf("fullDeckCount():\n");

	// Create variables
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(0));
	int seed = rand();
	int card, num;
	int i;

	// Initialize game
	initializeGame(2, k, seed, &G);

	// 0 of card
	printf("0 of a card\n");
	card = k[rand()%10];
	assert(fullDeckCount(1, card, &G), 0);

	// Card in hand but not in deck
	printf("Card in hand but not in deck\n");
	card = k[rand()%10];
	gainCard(card, &G, 2, 1);
	assert(fullDeckCount(1, card, &G), 1);
	resetDeck(&G);

	// Card in deck but not in hand
	printf("Card in deck but not in hand\n");
	card = k[rand()%10];
	gainCard(card, &G, 1, 1);
	assert(fullDeckCount(1, card, &G), 1);
	resetDeck(&G);

	// Card in deck and hand
	printf("Card in deck and hand\n");
	card = k[rand()%10];
	gainCard(card, &G, 1, 1);
	gainCard(card, &G, 2, 1);
	assert(fullDeckCount(1, card, &G), 2);
	resetDeck(&G);

	// Multiple in hand
	printf("Multiple in hand\n");
	card = k[rand()%10];
	num = rand()%5+1;
	for (i=0; i<num; i++)
		gainCard(card, &G, 2, 1);
	assert(fullDeckCount(1, card, &G), num);
	resetDeck(&G);

	// Multiple in deck
	printf("Multiple in deck\n");
	card = k[rand()%10];
	num = rand()%5+1;
	for (i=0; i<num; i++)
		gainCard(card, &G, 1, 1);
	assert(fullDeckCount(1, card, &G), num);
	resetDeck(&G);

	return 0;
}
