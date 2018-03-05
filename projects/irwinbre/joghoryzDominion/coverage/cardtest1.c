//Test isGameOver

#include "dominion.h"
#include <stdio.h>
#include <string.h>


int main(){

    printf("===TESTING great_hall===\n");

    //Testing normal run

    struct gameState startingGameState;
    struct gameState endingGameState;

    startingGameState.whoseTurn = 1;
    startingGameState.deck[1][0] = silver;
    startingGameState.deck[1][1] = gold;
    startingGameState.deck[1][2] = adventurer;
    startingGameState.deck[1][3] = ambassador;
    startingGameState.deck[1][4] = smithy;
    startingGameState.deck[1][5] = silver;
    startingGameState.deck[1][6] = great_hall;
    startingGameState.deck[1][7] = embargo;
    startingGameState.handCount[1] = 3;
    startingGameState.hand[1][0] = silver;
    startingGameState.hand[1][1] = smithy;
    startingGameState.hand[1][2] = ambassador;
    startingGameState.deckCount[0] = 0;
    startingGameState.deckCount[1] = 8;
    startingGameState.numActions  = 2;

    int result;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));


    result = cardEffect_great_hall(&endingGameState, 1, 2);

    if(result != 0){
        printf("-----FAILED: general error\n");
        return 1;
    }

    if((memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: no state change when expected\n");
        return  2;
    }
    if(endingGameState.handCount[1] != 3){
        printf("-----FAILED: hand count mismatch\n");
        return  3;
    }
    if(endingGameState.numActions != 3){
        printf("-----FAILED: numactions mismatch\n");
        return  4;
    }

    printf("-----PASSED: normal run\n");




}

