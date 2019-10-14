#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


static void printDeck(CardDeck deck)
{
	int ind;
	for (ind = 0; ind  < deck.size; ind++)
	{
		printf("%c", deck.cards[ind]);
	}
	printf("\n");
}


void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  int counter;
  for (counter = 0; counter < origDeck.size - 1; counter++)
  {
    leftDeck[counter].size = counter + 1;
    rightDeck[counter].size = origDeck.size - (counter + 1);  
    memcpy(leftDeck[counter].cards, origDeck.cards, leftDeck[counter].size * sizeof(leftDeck[counter].cards[0]));
    memcpy(rightDeck[counter].cards, origDeck.cards + leftDeck[counter].size, rightDeck[counter].size * sizeof(rightDeck[counter].cards[0]));
  }
  
  
}

void helper(CardDeck leftDeck, CardDeck rightDeck, CardDeck outputDeck, int posL, int posR, int round)
{
	
	if (posL == leftDeck.size && posR == rightDeck.size)
	{
		round--;		
		shuffle(outputDeck,round);
	}

	if(posL < leftDeck.size && posR == rightDeck.size)
	{
		outputDeck.cards[posL + posR] = leftDeck.cards[posL];
		//posL++;
		helper(leftDeck, rightDeck, outputDeck, posL+1, posR, round); 
	}
	if(posR < rightDeck.size && posL == leftDeck.size)
	{
		outputDeck.cards[posL + posR] = rightDeck.cards[posR];
		//posR++;
		helper(leftDeck, rightDeck, outputDeck, posL, posR+1, round);
	}
	if (posL < leftDeck.size && posR < rightDeck.size)
	{
		outputDeck.cards[posL + posR] = leftDeck.cards[posL];
		//posL++;
		helper(leftDeck, rightDeck, outputDeck, posL+1, posR, round);
		outputDeck.cards[posL + posR] = rightDeck.cards[posR];
		//posR++;
		helper(leftDeck, rightDeck, outputDeck, posL, posR+1, round);
	}
		

}
void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
{
	
	//int counter;
	int posL = 0;
	int posR = 0;
	int totalCards = leftDeck.size + rightDeck.size;
	CardDeck outputDeck = 
	{
		.size = totalCards,
		.cards = {0}
	};
 
	helper(leftDeck, rightDeck, outputDeck, posL, posR, round);

}
  
  
void shuffle(CardDeck origDeck, int round)
{
	if (round == 0)
	{
		printDeck(origDeck);
		return;
	}

	int numPossDeck =  origDeck.size - 1;
	int counter = 0;
	
	CardDeck * leftDeck = malloc(sizeof(CardDeck) * numPossDeck);
	CardDeck * rightDeck = malloc(sizeof(CardDeck) * numPossDeck);
	
	divide(origDeck, leftDeck, rightDeck);
	
	while(counter < numPossDeck)
	{
		interleave(leftDeck[counter], rightDeck[counter], round);
		counter++;
	}
	free(leftDeck);
	free(rightDeck);
}

