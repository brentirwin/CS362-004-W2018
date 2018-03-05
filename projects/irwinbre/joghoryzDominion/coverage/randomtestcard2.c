//Test isGameOver

#include "dominion.h"
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

    printf("+++RANDOM TESTING smithy+++\n");

    //Testing empty deck

    PutSeed(6548);
    SelectStream(1);
    srand(Random());
	int i,j,k;

    for (j = 0; j < 25000 ; ++j) {
        struct gameState startingGameState;
        struct gameState endingGameState;

        unsigned int random = (rand()%MAX_DECK) - 1;

        unsigned int deck_cards = MAX_DECK - random;

        random = (rand()%deck_cards) - 1;
        unsigned int hand_cards = deck_cards - random;
        startingGameState.deckCount[1] = deck_cards;
        startingGameState.discardCount[1] = MAX_DECK-deck_cards-hand_cards;
        startingGameState.handCount[1] = hand_cards;
        startingGameState.numActions = rand() % 500;

        //printf("deck_cards: %d\n hand_cards: %d\n discard_cards: %d\n",startingGameState.deckCount[1],startingGameState.handCount[1],startingGameState.discardCount[1]);

       // fflush(stdout);
        srand(Random());
        for (k = 0; k <startingGameState.discardCount[1] ; ++k) {
            unsigned int rand_card= rand() % 25;
            startingGameState.discard[1][k] = rand_card;
        }
        for (k = 0; k <startingGameState.deckCount[1] ; ++k) {
            unsigned int rand_card= rand() % 25;
            startingGameState.deck[1][k] = rand_card;
        }
        srand(Random());
        startingGameState.handCount[1] = hand_cards;
        for (k = 0; k <startingGameState.handCount[1] ; ++k) {
            unsigned int rand_card= rand() % 25;
            startingGameState.hand[1][k] = rand_card;
        }



        //printf("deck_cards %d\n",deck_cards);


        startingGameState.whoseTurn = 1;

        int result;
        memcpy(&endingGameState, &startingGameState, sizeof(struct gameState));

        int handPos = rand() % hand_cards;

        result = cardEffect_smithy(&endingGameState, 1, handPos);

        if(result != 0){
            printf("-----FAILED: general error\n");
        }

        if((memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
            printf("-----FAILED: no state change when expected\n");
        }
        if(endingGameState.handCount[1] == startingGameState.handCount[1]+3){
            printf("-----FAILED: hand count mismatch\n");
        }




    }

    printf("+++RANDOM TESTING smithy+++ Completed!\n");

}

