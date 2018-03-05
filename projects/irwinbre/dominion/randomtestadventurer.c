/***************************************************************
* Filname: cardtest1.c
* Author: Brent Irwin
* Date: 18 February 2018
* Description: Test Adventurer Card
***************************************************************/

#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void randomize(struct gameState *G) {
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int t[3] = {copper, silver, gold};
	int i;
	int treasuresInDraw, othersInDraw, beforeFirst, beforeSecond;

	// 0, 1, or 2 treasure cards in draw pile
	treasuresInDraw = rand()%3;
	othersInDraw = rand()%10;
	beforeFirst = rand()%10;
	beforeSecond = rand()%10;

	// If 0
	if (treasuresInDraw == 0) {
		// No treasures in draw
		for (i=0; i<othersInDraw; i++)
			gainCard(k[rand()%10], G, 1, 1);
		// Some non-treasures followed by a treasure in discard
		for (i=0; i<beforeFirst; i++)
			gainCard(k[rand()%10], G, 0, 1);
		gainCard(t[rand()%3], G, 0, 1);
		// Some non-treasures followed by a treasure in discard
		for (i=0; i<beforeSecond; i++)
			gainCard(k[rand()%10], G, 0, 1);
		gainCard(t[rand()%3], G, 0, 1);
	}

	// If 1
	else if (treasuresInDraw == 1) {
		// Some non-treasures followed by a treasure in draw
		for (i=0; i<beforeFirst; i++)
			gainCard(k[rand()%10], G, 1, 1);
		gainCard(t[rand()%3], G, 1, 1);
		// Some non-treasures after
		for (i=0; i<othersInDraw; i++)
			gainCard(k[rand()%10], G, 1, 1);
		// Some non-treasures followed by a treasure in discard
		for (i=0; i<beforeSecond; i++)
			gainCard(k[rand()%10], G, 0, 1);
		gainCard(t[rand()%3], G, 0, 1);
	}

	// If 2
	else if (treasuresInDraw == 2) {
		// Some non-treasures followed by a treasure in draw
		for (i=0; i<beforeFirst; i++)
			gainCard(k[rand()%10], G, 1, 1);
		gainCard(t[rand()%3], G, 1, 1);
		// Some non-treasures followed by a treasure in draw
		for (i=0; i<beforeSecond; i++)
			gainCard(k[rand()%10], G, 1, 1);
		gainCard(t[rand()%3], G, 1, 1);
	}
}

int test_card() {
	// Create variables
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = rand();
	int i;

	// Start the game
	for (i=0; i<MAX_HAND; i++) G.hand[1][i] = -1;
	initializeGame(2, k, seed, &G);
	
	// Let's randomize some stuff!
	randomize(&G);

	// Print expected results
	printf("For this test to pass, expect 2 treasures in hand after.\n");

	// Initialize hand
	G.hand[1][0] = adventurer;

	// Display cards before
	printf("Cards before: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");

	// Use the adventurer card
	card_adventurer(&G, 1);

	// Display cards after
	printf("Cards after: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");

	// Check results
	int success = 0;
	if ((G.hand[1][0] == copper ||
		G.hand[1][0] == silver ||
		G.hand[1][0] == gold) &&
		(G.hand[1][1] == copper ||
		G.hand[1][1] == silver ||
		G.hand[1][1] == gold))
		success = 1;

	if (success) printf("TEST SUCCESSFULLY COMPLETED.\n");
	else printf("TEST FAILED.\n");

	return 0;
}

int main() {
	srand(time(0));
	int i;
	for (i=0; i<100; i++) {
		test_card();
	}
	return 0;
}
