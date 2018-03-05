//Test isGameOver

#include "dominion.h"
#include <stdio.h>
#include <string.h>


int main(){

    printf("===TESTING adventurer===\n");

    //Testing empty deck

    struct gameState startingGameState;
    struct gameState endingGameState;



    startingGameState.handCount[1] = 0;
    startingGameState.whoseTurn = 1;
    startingGameState.deckCount[1]=0;
    startingGameState.discard[1][0] = silver;
    startingGameState.discard[1][1] = gold;
    startingGameState.discard[1][2] = adventurer;
    startingGameState.discard[1][3] = ambassador;
    startingGameState.discard[1][4] = smithy;
    startingGameState.discard[1][5] = silver;
    startingGameState.discard[1][6] = great_hall;
    startingGameState.discard[1][7] = embargo;
    startingGameState.discardCount[1] = 8;

    int temphand[MAX_HAND];
    int result;
    int i,j;
	memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));


    result = cardEffect_adventurer(0,&endingGameState,1,0,temphand);

    if(result != 0){
        printf("-----FAILED: Empty deck\n");
        return 1;
    }

    if((memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: Empty deck\n");
        return  1;
    }
    if(endingGameState.handCount[1] != 3){
        printf("-----FAILED: Empty deck\n");
        return  1;
    }
    for (i = 0; i < endingGameState.handCount[1] ; ++i) {
        if(endingGameState.hand[1][i] != silver){
            if(endingGameState.hand[1][i] != gold){
                printf("-----FAILED: Empty deck\n");
                return 1;
            }
        }
    }

    printf("-----PASSED: Empty deck\n");

    //Testing partial deck
    for (j = 0; j < MAX_HAND ; ++j) {
        temphand[j] = 0;
    }

    result = 0;

    startingGameState.handCount[1] = 0;
    startingGameState.whoseTurn = 1;
    startingGameState.discardCount[1]=0;
    startingGameState.deck[1][0] = silver;
    startingGameState.deck[1][1] = gold;
    startingGameState.deck[1][2] = adventurer;
    startingGameState.deck[1][3] = ambassador;
    startingGameState.deck[1][4] = smithy;
    startingGameState.deck[1][5] = silver;
    startingGameState.deck[1][6] = great_hall;
    startingGameState.deck[1][7] = embargo;
    startingGameState.deckCount[1] = 8;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));


    result = cardEffect_adventurer(0,&endingGameState,1,0,temphand);

    if(result != 0){
        printf("-----FAILED: Partial deck\n");
        return 1;
    }

    if((memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: Partial deck\n");
        return  1;
    }
    if(endingGameState.handCount[1] != 3){
        printf("-----FAILED: Partial deck\n");
        return  1;
    }
    for (i = 0; i < endingGameState.handCount[1] ; ++i) {
        if(endingGameState.hand[1][i] != silver){
            if(endingGameState.hand[1][i] != gold){
                printf("-----FAILED: Partial deck\n");
                return 1;
            }
        }
    }

    printf("-----PASSED: Partial deck\n");




}

