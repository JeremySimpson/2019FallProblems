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
    int pos1;
    int pos2;
    int swapPos;
    int tempPos;
    
    
    printf("The Sorted Array is:\n");
    
    for (pos1 = 0; pos1 < (size); pos1++)
    {
        tempPos = pos1;
        
        for (pos2 = pos1 + 1; pos2 <= size ; pos2++)  
        {
            if (arr[tempPos] > arr[pos2])
                tempPos = pos2;
        }
        if (tempPos != pos1)
        {
            swapPos = arr[pos1];
            arr[pos1] = arr[tempPos];
            arr[tempPos] = swapPos;
        }
    }
    
    pos1 = 0;
    while (pos1 != size)
    {
        printf("%d\n",arr[pos1]);
        pos1 ++;
    }
    
    return;
}
#endif
