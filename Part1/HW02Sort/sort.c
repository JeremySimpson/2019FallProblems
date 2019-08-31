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
      int arr[10] = {6, 9, 3, 4, 7, 5, 1, 10, 2, 8};
    int size = 10;
    int pos1;
    int pos2;
    int swap;
    int position;
    
    
    printf("The Sorted Array is:\n");
    
    for (pos1 = 0; pos1 < (size - 1); pos1++)
    {
        position = pos1;
        
        for (pos2 = pos1 + 1; pos2 < size ; pos2++)  
        {
            if (arr[position] > arr[pos2])
                position = pos2;
        }
        if (position != pos1)
        {
            swap = arr[pos1];
            arr[pos1] = arr[position];
            arr[position] = swap;
        }
    }
    
    pos1 = 0;
    while (pos1 != size)
    {
        printf("%d\n",arr[pos1]);
        pos1 ++;
    }
    
    return 0;
}
#endif
