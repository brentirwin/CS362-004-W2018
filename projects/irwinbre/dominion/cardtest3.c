/***************************************************************
* Filname: cardtest1.c
* Author: Brent Irwin
* Date: 28 January 2018
* Description: Test Great Hall Card
***************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	// Create variables
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(0));
	int seed = rand();
	int i;
	int actionsBefore, actionsAfter;

	// Start the game
	initializeGame(2, k, seed, &G);
	// Put some card in their hand
	for (i=0; i<10; i++) {
		gainCard(k[rand()%10], &G, 1, 1);
		gainCard(rand()%3+4, &G, 1, 1);
	}

	// Print expected results
	printf("For this test to pass, expect one more card and 1 more action.\n");

	// Initialize hand
	for (i=0; i<MAX_HAND; i++) {
		G.hand[1][i] = -1;
	}
	G.hand[1][0] = great_hall;

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
	card_great_hall(1, &G, 0);

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
	
	if (actionsBefore + 1 != actionsAfter)
		success = 0;

	if (success) printf("TEST SUCCESSFULLY COMPLETED.\n");
	else printf("TEST FAILED.\n");

	return 0;
}
