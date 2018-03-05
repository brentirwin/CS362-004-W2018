//Test isGameOver

#include "dominion.h"
#include <stdio.h>
#include <string.h>


int main(){

    printf("===TESTING isGameOver===\n");

    /*int seed = 1000;
    int numPlayer = 2;
    int cards[10] = {adventurer, council_room, feast, gardens, mine
            , remodel, smithy, village, baron, great_hall};
    */
    struct gameState startingGameState;
    struct gameState endingGameState;

    //Test No Game Over Conditions Met
    startingGameState.supplyCount[province] = 10;
  	int i;
  for (i = 0; i <25 ; ++i) {
        startingGameState.supplyCount[i] = 20;
    }

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(isGameOver(&endingGameState) || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: No Game Over Conditions Met\n");
    }
    else{
        printf("-----PASSED: No Game Over Condition Met\n");
    }

    //Test Province Cards Stack Empty Game Over
    startingGameState.supplyCount[province] =0;
    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(!isGameOver(&endingGameState) || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: Province Cards Stack Empty Game Over\n");
    }
    else{
        printf("-----PASSED: Province Cards Stack Empty Game Over\n");
    }

    //Test Supply Pile 3 Empty Game Over

    startingGameState.supplyCount[province] = 10;
    startingGameState.supplyCount[2] = 0;
    startingGameState.supplyCount[5] = 0;
    startingGameState.supplyCount[6] = 0;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(!isGameOver(&endingGameState) || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: Supply Pile 3 Empty Game Over\n");
    }
    else{
        printf("-----PASSED: Supply Pile 3 Empty Game Over\n");
    }

    // Test No Game Over Supply Pile 2 Empty
    startingGameState.supplyCount[province] = 10;
    startingGameState.supplyCount[2] = 0;
    startingGameState.supplyCount[5] = 0;
    startingGameState.supplyCount[6] = 20;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(isGameOver(&endingGameState) || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: No Game Over: 2 Supply Empty\n");
    }
    else{
        printf("-----PASSED: No Game Over: 2 Supply Empty\n");
    }


    // Test All Game Over Conditions Met
    startingGameState.supplyCount[province] = 0;
    startingGameState.supplyCount[2] = 0;
    startingGameState.supplyCount[5] = 0;
    startingGameState.supplyCount[6] = 0;

    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    if(!isGameOver(&endingGameState) || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: All Game Over Conditions Met\n");
    }
    else{
        printf("-----PASSED: All Game Over Conditions Met\n");
    }


}

