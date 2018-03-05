//Test isGameOver

#include "dominion.h"
#include <stdio.h>
#include <string.h>


int main(){

    printf("===TESTING supplyCount===\n");

    struct gameState startingGameState;
    struct gameState endingGameState;

    //Test 10 count

    startingGameState.supplyCount[5] = 10;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(supplyCount(5,&endingGameState)!= 10 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: 5-10 count\n");
    }
    else{
        printf("-----PASSED: 5-10 count\n");
    }

    //Test 0 count

    startingGameState.supplyCount[5] = 0;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(supplyCount(5,&endingGameState)!= 0 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: 5-0 count\n");
    }
    else{
        printf("-----PASSED: 5-0 count\n");
    }

    //Test 1000 count

    startingGameState.supplyCount[5] = 1000;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(supplyCount(5,&endingGameState)!= 1000 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: 5-1000 count\n");
    }
    else{
        printf("-----PASSED: 5-1000 count\n");
    }

    //Test 23 count

    startingGameState.supplyCount[3] = 23;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(supplyCount(3,&endingGameState)!= 23 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: 3-23 count\n");
    }
    else{
        printf("-----PASSED: 3-23 count\n");
    }

    //Test none existing

    startingGameState.supplyCount[0] = 0;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(supplyCount(0,&endingGameState)!= 0 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: 0-0 count\n");
    }
    else{
        printf("-----PASSED: 0-0 count\n");
    }
}

