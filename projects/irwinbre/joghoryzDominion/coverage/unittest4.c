//Test isGameOver

#include "dominion.h"
#include <stdio.h>
#include <string.h>


int main(){

    printf("===TESTING handCard===\n");

    struct gameState startingGameState;
    struct gameState endingGameState;



    startingGameState.whoseTurn = 1;
    startingGameState.hand[1][5] = 6;
    startingGameState.hand[1][3] = 9;



    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));

    //Test P1 has C6 Pos 5

    if(handCard(5,&endingGameState) != 6 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: P1 has C6 Pos 5\n");
    }
    else{
        printf("-----PASSED: P1 has C6 Pos 5\n");
    }

    //Test P1 has C9 Pos 3

    if(handCard(3,&endingGameState) != 9 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: P1 has C9 Pos 3\n");
    }
    else{
        printf("-----PASSED: P1 has C9 Pos 3\n");
    }

    startingGameState.whoseTurn = 0;
    startingGameState.hand[0][0] = 8;
    startingGameState.hand[0][0] = 0;
    memcpy(&endingGameState,&startingGameState,sizeof(struct gameState));


    //Test P0 has C0 Pos 0

    if(handCard(0,&endingGameState) != 0 || !(memcmp(&endingGameState,&startingGameState,sizeof(struct gameState)) ==0)){
        printf("-----FAILED: P0 has C0 Pos 0\n");
    }
    else{
        printf("-----PASSED: P0 has C0 Pos 0\n");
    }
}

