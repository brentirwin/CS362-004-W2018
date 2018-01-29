#ifndef CARDS_H
#define CARDS_H

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int card_adventurer(int*, struct gameState*, int, int*, int*, int*);
int card_smithy(int, struct gameState*, int);
int card_village(int, struct gameState*, int);
int card_great_hall(int, struct gameState*, int);
int card_steward(int, int, int, int, struct gameState*, int);

#endif
