// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
  FILE * fptr = fopen(filename, "r");
  
  if (fptr == NULL)
	  return false;

  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false

  seekStat = fseek(fptr, 0, SEEK_END);
  
  if (seekStat != 0)
  {
	  fclose(fptr);
	  return false;
  }
  
  // use ftell to determine the size of the file
  size = ftell(fptr);

  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  
  seekStat = fseek(fptr, size, SEEK_SET);
  // if fseek fails, fclose and return false
  
  if (seekStat != 0)
  {
	  fclose(fptr);
	  return false;
  }
  
  // the number of integers is the file's size divided by
  // size of int  
  
  numInt = size / sizeof(int);
 
  // allocate memory for the array
  
  * arr = malloc(sizeof(int) * numInt); 

  // if malloc fails, fclose and return false

  if (arr == NULL)
  {
	  fclose(fptr);
	  return false;
  }


  // use fread to read the number of integers in the file

  readStat = fread(arr, sizeof(int), numInt, fptr);
  
  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false
  
  if (readStat != numInt)
  {
	  free(arr);
	  fclose(fptr);
	  return false;
  }

  // if fread succeeds
  // close the file
  fclose(fptr);

  
  // update the argument for the array address


  
  // update the size of the array
  size = numInt;

  
  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  FILE * fptr = fopen(filename, "w");


  // if fopen fails, return false
  if (fptr == NULL)
	  return false;

  // use fwrite to write the entire array to a file
  numWrite = fwrite(arr, sizeof(int), size, fptr);
  
  // check whether all elements of the array have been written
  // fclose
  // if not all elements have been written, return false
  if (numWrite != size)
  {
	  fclose(fptr);
	  return false;
  }
 
  // if all elements have been written, return true

  return true;



}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif

  // if one or both of the arrays are empty, do nothing
  int i;
  int j;
  int k;
  if ((l == m) && (m == r))
	  return;
  
  int num1;
  int num2;
  
  int num1 = m - l + 1;
  int num2 = r - m;




  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write

  int L[num1], R[num2];
  
  for (i = 0; i < num1; i++)
    L[i] = arr[l+i];
  for (j = 0; j < num2; j++)
	  R[j] = arr[m+1+j];

  i = 0;
  j = 0;
  k = l;
  
  while (i < num1)
  {
	  arr[k] = L[i];
	  i++;
	  k++;
  }
  
  while (j < num2)
  {
    arr[k] = R[j];
	j++;
	k++;
  }


  // merge the two parts (each part is already sorted) of the array
  // into one sorted array

  




  


  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif

  // if the array has no or one element, do nothing
 if ((l == r) || (l == (r-1)))
	 return;
 
  // divide the array into two arrays
  if (l < r)
  {
	  int m = 1 + (r-1)/2;
	  
  // call mergeSort with each array
  mergeSort(arr, l, m);
  mergeSort(arr, m+1, r);
  
  // merge the two arrays into one
  merge(arr, l, m, r);
  }
  
  
  




} 
#endif
