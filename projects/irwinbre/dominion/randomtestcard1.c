/***************************************************************
* Filname: cardtest1.c
* Author: Brent Irwin
* Date: 28 January 2018
* Description: Test Village Card
***************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void randomize(struct gameState *G) {
	int k[13] = {copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int i;

	// Number and type of cards in deck
	int cardsInDeck = rand()%20;
	for (i=0; i<cardsInDeck; i++) {
		gainCard(k[rand()%13], G, 1, 1); // Insert cards from k
	}

	// Number and type of cards in hand
	int cardsInHand = rand()%5;
	for (i=0; i<MAX_HAND; i++) {
		G->hand[1][i] = -1;
	}
	G->hand[1][0] = village;
	for (i=1; i<cardsInHand; i++) {
		gainCard(k[rand()%13], G, 0, 1);
	}

	// Number and type of cards in discard pile
	// Make sure there's always SOME; the deck would never be totally empty
	int cardsInDiscard = rand()%20+5;
	for (i=0; i<cardsInDiscard; i++) {
		gainCard(k[rand()%13], G, 2, 1);
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
	int actionsBefore, actionsAfter;

	// Start the game
	initializeGame(2, k, seed, &G);

	// Let's randomize some stuff!
	randomize(&G);

	// Print expected results
	printf("For this test to pass, expect one more card and 2 more actions.\n");

	// Display cards before
	printf("Cards before: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");
	printf("Actions before: ");
	actionsBefore = G.numActions;
	printf("%i\n", actionsBefore);

	// Use the smithy card
	card_village(1, &G, 0);

	// Display cards after
	printf("Cards after: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");
	actionsAfter = G.numActions;
	printf("%i\n", actionsAfter);

	// Check results
	int success = 1;
	if (G.hand[1][0] == -1 ||
		G.hand[1][1] != -1 ||
		G.hand[1][2] != -1 ||
		G.hand[1][3] != -1 ||
		G.hand[1][4] != -1)
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
