CFLAGS = -Wall -fpic -coverage -lm

all: playdom player testDrawCard testBuyCard badTestDrawCard

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

testresults.out: random-adventurer.c random-smithy.c unit-adventurer.c unit-greathall.c unit-smithy.c dominion.o rngs.o
	echo "Result for running tests:" > testresults.out
	
	echo "random-adventurer.c:" >> testresults.out
	gcc -o random-adventurer random-adventurer.c dominion.o rngs.o $(CFLAGS)
	random-adventurer >> testresults.out
	gcov dominion.c >> testresults.out
	
	echo "random-smithy.c:" >> testresults.out
	gcc -o random-smithy random-smithy.c dominion.o rngs.o $(CFLAGS)
	random-smithy >> testresults.out
	gcov dominion.c >> testresults.out
	
	echo "unit-adventurer.c" >> testresults.out
	gcc -o unit-adventurer unit-adventurer.c dominion.o rngs.o $(CFLAGS)
	unit-adventurer >> testresults.out
	gcov dominion.c >> testresults.out
	
#	echo "unit-greathall.c" >> testresults.out
#	gcc -o unit-greathall unit-greathall.c dominion.o rngs.o $(CLFAGS)
#	unit-greathall >> testresults.out
#	gcov dominion.c >> testresults.out
	
	echo "unit-smithy.c" >> testresults.out
	gcc -o unit-smithy unit-smithy.c dominion.o rngs.o $(CFLAGS)
	unit-smithy >> testresults.out
	gcov dominion.c >> testresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
