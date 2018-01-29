/***************************************************************
* Filname: cardtest1.c
* Author: Brent Irwin
* Date: 28 January 2018
* Description: Unit Test isGameOver() 
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
	printf("isGameOver():\n");

	// Create variables
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(0));
	int seed = rand();
	int card1, card2, card3;

	// Is there one province?
	initializeGame(2, k, seed, &G);
	printf("One province left: Game still going\n");
	G.supplyCount[province] = 1;
	assert(isGameOver(&G), 0);

	// Zero provinces
	initializeGame(2, k, seed, &G);
	printf("No provinces left: Game over\n");
	G.supplyCount[province] = 0;
	assert(isGameOver(&G), 1);
	
	// Two empty supply decks
	initializeGame(2, k, seed, &G);
	printf("Two empty supply decks: Game still going\n");
	card1 = k[rand()%10];
	do {
		card2 = k[rand()%10];
	} while (card1 == card2);
	G.supplyCount[card1] = 0;
	G.supplyCount[card2] = 0;
	G.supplyCount[province] = 1;
	assert(isGameOver(&G), 0);

	// Three empty supply decks
	initializeGame(2, k, seed, &G);
	printf("Three empty supply decks: Game over\n");
	do {
		card3 = k[rand()%10];
	} while (card3 == card2 || card3 == card1);
	G.supplyCount[card3] = 0;	
	assert(isGameOver(&G), 1);

	// Zero provinces and three empty supply decks
	initializeGame(2, k, seed, &G);
	printf("Three empty supply decks and no provinces: Game over\n");
	G.supplyCount[province] = 0;
	assert(isGameOver(&G), 1);

	return 0;
}
