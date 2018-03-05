//Test isGameOver

#include "dominion.h"
#include <stdio.h>
#include <string.h>


int main(){

    printf("===TESTING fullDeckCount===\n");

    struct gameState startingGameState;
    struct gameState endingGameState;

    //Test P0 3 count overall

    startingGameState.deckCount[0] = 10;
    startingGameState.handCount[0] = 10;
    startingGameState.discardCount[0] = 10;

    //Initialize hands to clean state
    int i;
    for(i=0; i< 10; i++){
        startingGameState.deck[0][i] = 5;
        startingGameState.hand[0][i] = 5;
        startingGameState.discard[0][i] = 5;
    }

    startingGameState.deck[0][3] = 4;
    startingGameState.hand[0][6] = 4;
    startingGameState.discard[0][2] = 4;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(fullDeckCount(0,4,&endingGameState) != 3 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: P0 3 count overall\n");
    }
    else{
        printf("-----PASSED: P0 3 count overall\n");
    }

    //Test P0 2 count deck+discard empty hand

    startingGameState.deckCount[0] = 10;
    startingGameState.handCount[0] = 0;
    startingGameState.discardCount[0] = 10;

    //Initialize hands to clean state
    for(i=0; i< 10; i++){
        startingGameState.deck[0][i] = 5;
        startingGameState.hand[0][i] = 5;
        startingGameState.discard[0][i] = 5;
    }

    startingGameState.deck[0][3] = 4;
    startingGameState.hand[0][6] = 4;
    startingGameState.discard[0][2] = 4;


    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(fullDeckCount(0,4,&endingGameState) != 2 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: P0 2 count deck+discard empty hand\n");
    }
    else{
        printf("-----PASSED: P0 2 count deck+discard empty hand\n");
    }

    //Test P0 0 count all empty

    startingGameState.deckCount[0] = 0;
    startingGameState.handCount[0] = 0;
    startingGameState.discardCount[0] = 0;

    //Initialize hands to clean state
    for(i=0; i< 10; i++){
        startingGameState.deck[0][i] = 5;
        startingGameState.hand[0][i] = 5;
        startingGameState.discard[0][i] = 5;
    }

    startingGameState.deck[0][3] = 4;
    startingGameState.hand[0][6] = 4;
    startingGameState.discard[0][2] = 4;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(fullDeckCount(0,4,&endingGameState) != 0 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: P0 0 count all empty\n");
    }
    else{
        printf("-----PASSED: P0 0 count all empty\n");
    }

    //Test P1 30 count deck+hand+discard

    startingGameState.deckCount[1] = 10;
    startingGameState.handCount[1] = 10;
    startingGameState.discardCount[1] = 10;

    //Initialize hands to clean state
    for(i=0; i< 10; i++){
        startingGameState.deck[1][i] = 5;
        startingGameState.hand[1][i] = 5;
        startingGameState.discard[1][i] = 5;
    }

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(fullDeckCount(1,5,&endingGameState) != 30 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: P1 30 count deck+hand+discard\n");
    }
    else{
        printf("-----PASSED: P1 30 count deck+hand+discard\n");
    }

    //Test P1 20 count hand+discard empty deck

    startingGameState.deckCount[1] = 10;
    startingGameState.handCount[1] = 10;
    startingGameState.discardCount[1] = 10;

    //Initialize hands to full state
    for(i=0; i< 10; i++){
        startingGameState.deck[1][i] = 0;
        startingGameState.hand[1][i] = 5;
        startingGameState.discard[1][i] = 5;
    }

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(fullDeckCount(1,5,&endingGameState) != 20 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: P1 20 count hand+discard empty deck\n");
    }
    else{
        printf("-----PASSED: P1 20 count hand+discard empty deck\n");
    }




}

