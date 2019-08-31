// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{
    int pos1; //lower position
    int pos2; //higher position
    int swapPos; //temporary position used to reorder terms
    int tempPos; //temporary position used to store the lower position
    int lastTerms; //index of last term in array
    
    lastTerms = size - 1; //converts size of array to last index

    for (pos1 = 0; pos1 < lastTerms; pos1++) //continues for all indexes except for last
    {
        tempPos = pos1; //saves lower position as the potential lower value
        
        for (pos2 = pos1 + 1; pos2 <= lastTerms ; pos2++) //repeats for all indees except for first 
        {
            if (arr[tempPos] > arr[pos2])
                tempPos = pos2; //saves higher position if value at index is lower
        }
        if (tempPos != pos1) //performs if value in higher position is lower
        {
            swapPos = arr[pos1];
            arr[pos1] = arr[tempPos];
            arr[tempPos] = swapPos; //these three lines swap the two values
        }
    }
    return;
}
#endif
