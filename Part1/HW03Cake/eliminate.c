// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)

// 100% of the score
//void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
    
  // initialize all elements
    int i;
	int ar;
	int count; 
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
    //printf("reached 2");
    for (i = 0; i < n; i++)
    {
        arr[i] = i;
        //printf("%d\n", arr[i]);
    }
    
    i = -1;
    for (ar = 1; ar <= n; ar++)
    {
        
        count = 0;
        while (count < k)
            {
                i++;
                i = i % n;
                if (arr[i] != -1)
                {
                    count++;                
                }
            
            } 
        arr[i] = -1;
		// print the last one
		printf("%d\n",i);
    }
  // release the memory of the array
  free (arr);
}
#endif