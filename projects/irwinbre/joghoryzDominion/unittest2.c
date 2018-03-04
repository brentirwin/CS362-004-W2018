/***************************************************************
* Filname: cardtest1.c
* Author: Brent Irwin
* Date: 28 January 2018
* Description: Unit Test gainCard() 
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

int main() {
	printf("gainCard():\n");	

	// Create variables
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(0));
	int seed = rand();
	int card, before, after;
	int i;

	// Initialize game
	initializeGame(2, k, seed, &G);

	// Gain to hand (2 hand, 1 deck, else trash)
	printf("1 in hand\n");
	card = k[rand()%10];
	before = G.supplyCount[card];
	gainCard(card, &G, 2, 1);
	after = G.supplyCount[card];
	assert(G.hand[1][0], card);
	assert(before, after+1);

	// Gain to deck
	printf("1 in deck\n");card = k[rand()%10];
	before = G.supplyCount[card];
	gainCard(card, &G, 1, 1);
	after = G.supplyCount[card];
	int foundIt = 0;
	for (i=0; i<G.deckCount[1]; i++) {
		if (G.deck[1][i] == card)
			assert(1,1);
			foundIt = 1;
			break;
	}
	if (!foundIt) assert(1,0);
	assert(before, after+1);

	// Gain to trash
	printf("One goes to trash\n");
	card = k[rand()%10];
	before = G.supplyCount[card];
	gainCard(card, &G, 0, 1);
	after = G.supplyCount[card];
	assert(before, after+1);

	// No card left to draw
	printf("Empty deck\n");
	card = k[rand()%10];
	G.supplyCount[card] = 0;
	assert(gainCard(card, &G, 1, 1), -1);

	return 0;
}
