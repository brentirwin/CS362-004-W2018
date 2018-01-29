CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: tests.out

tests.out: cardtest1.c cardtest2.c ../dominion.o ../rngs.o
	echo "Result for running tests:" > unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c ../dominion.o ../rngs.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov ../dominion.c >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c ../dominion.o ../rngs.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov ../dominion.c >> unittestresults.out
	
