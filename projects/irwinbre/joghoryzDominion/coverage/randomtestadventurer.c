//Test isGameOver

#include "dominion.h"
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
int main(){

    printf("+++RANDOM TESTING adventurer+++\n");

    //Testing empty deck


    srand(time(0));
    PutSeed(rand());
    SelectStream(1);
	int i,j,k;

    for (j = 0; j < 100000 ; ++j) {
        struct gameState startingGameState;
        struct gameState endingGameState;

        unsigned int random = (rand()%MAX_DECK);

        unsigned int deck_cards = MAX_DECK - random;

        random = (rand()%deck_cards) - 1;
        unsigned int hand_cards = deck_cards - random;
        startingGameState.deckCount[1] = deck_cards;
        startingGameState.discardCount[1] = MAX_DECK-deck_cards-hand_cards;
        startingGameState.handCount[1] = hand_cards;

        //printf("deck_cards: %d\n hand_cards: %d\n discard_cards: %d\n",startingGameState.deckCount[1],startingGameState.handCount[1],startingGameState.discardCount[1]);

       // fflush(stdout);
        for (k = 0; k <startingGameState.discardCount[1] ; ++k) {
            unsigned int rand_card= rand() % 25;
            startingGameState.discard[1][k] = rand_card;
        }
        for (k = 0; k <startingGameState.deckCount[1] ; ++k) {
            unsigned int rand_card= rand() % 25;
            startingGameState.deck[1][k] = rand_card;
        }
        startingGameState.handCount[1] = hand_cards;
        for (k = 0; k <startingGameState.handCount[1] ; ++k) {
            unsigned int rand_card= rand() % 25;
            startingGameState.hand[1][k] = rand_card;
        }

        int treasureCount =0;

        while(treasureCount <= 5){
            unsigned int card_index = rand() % deck_cards;
            //printf("ci: %d dc %d\n",card_index,deck_cards);
            fflush(stdout);
            startingGameState.deck[1][card_index] = gold;
            treasureCount++;
        }



        //printf("deck_cards %d\n",deck_cards);


        startingGameState.whoseTurn = 1;

        int temphand[MAX_HAND];
        int result;
        memcpy(&endingGameState, &startingGameState, sizeof(struct gameState));


        result = cardEffect_adventurer(0, &endingGameState, 1, 0, temphand);

        if (result != 0) {
            printf("-----FAILED: General error\n");
        }

        if ((memcmp(&endingGameState, &startingGameState, sizeof(struct gameState)) == 0)) {
            printf("-----FAILED: State changed\n");

        }

        int treasure =0;
        for (i = 0; i < endingGameState.handCount[1]; ++i) {
            if (endingGameState.hand[1][i] == silver) {
                treasure++;
            }
            if (endingGameState.hand[1][i] == copper) {
                treasure++;
            }
            if (endingGameState.hand[1][i] == gold) {
                treasure++;
            }
        }


        if (treasure < 2) {
            printf("-----FAILED: Minimum treasure not met\n");
        }

    }

    printf("+++RANDOM TESTING adventurer+++ Completed!\n");

}

