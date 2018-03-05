/***************************************************************
* Filname: randomtestcard1.c
* Author: Brent Irwin
* Date: 18 February 2018
* Description: Random Test Village Card
***************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void randomize(struct gameState *G) {
	int k[12] = {copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, baron, great_hall};
	int i;

	// Number and type of cards in deck
	int cardsInDeck = rand()%20;
	for (i=0; i<cardsInDeck; i++) {
		gainCard(k[rand()%12], G, 1, 1); // Insert cards from k
	}

	// Number and type of cards in hand
	int cardsInHand = rand()%5;
	for (i=0; i<MAX_HAND; i++) {
		G->hand[1][i] = -1;
	}
	G->hand[1][0] = village;
	for (i=1; i<cardsInHand; i++) {
		gainCard(k[rand()%12], G, 2, 1);
	}

	// Number and type of cards in discard pile
	// Make sure there's always SOME; the deck would never be totally empty
	int cardsInDiscard = rand()%20+5;
	for (i=0; i<cardsInDiscard; i++) {
		gainCard(k[rand()%12], G, 0, 1);
	}

	// Number of actions the player has
	G->numActions = rand()%5+1;
}

int test_card() {
	// Create variables
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = rand();
	int i;
	int actionsBefore, actionsAfter, cardsBefore, cardsAfter;

	// Start the game
	for (i=0; i<MAX_HAND; i++) G.hand[1][i] = -1;
	initializeGame(2, k, seed, &G);

	// Let's randomize some stuff!
	randomize(&G);

	// Print expected results
	printf("For this test to pass, expect the same number of cards and 1 more action.\n");

	// Display cards before
	actionsBefore = G.numActions;
	cardsBefore = 0;
	for (i=0; i<MAX_HAND; i++) {
		if (G.hand[1][i] == -1) break;
		else cardsBefore++;
	}

	// Use the smithy card
	card_village(1, &G, 0);

	// Display cards after
	actionsAfter = G.numActions;

	cardsAfter = 0;
	for (i=0; i<MAX_HAND; i++) {
		if (G.hand[1][i] == -1) break;
		else cardsAfter++;
	}

	// Check results
	int success = 1;

	printf("Cards before: %d, cards after: %d\n", cardsBefore, cardsAfter);
	printf("Actions before: %d, actions after: %d\n", actionsBefore, actionsAfter);

	if (G.hand[1][0] == village)
		success = 0;

	if (cardsAfter != cardsBefore)
		success = 0;

	if (actionsBefore + 2 != actionsAfter)
		success = 0;

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
