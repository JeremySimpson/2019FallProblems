// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"
	

#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
	// count the number of vectors in the file and return the number
	// The input is a binary file. You must use fread.
	// You must not use fscanf(, "%d", ) 
	//
	FILE * fptr = fopen(filename,"r");
	if (fptr == NULL){
		return -1;
	} 
	// If fopen fails, return -1
	//
	//
	int sum = 0;
	Vector temp;
	// int count = 0;

	while (fread(&temp, sizeof(Vector), 1, fptr) == 1)
	{
		sum++;
	}
	fclose(fptr);
	return sum;
	// For the mode of fopen, you may use "r" without b
	//
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
	FILE * fptr = fopen(filename, "r");
	// if fopen fails, return false
	if (fptr == NULL)
		return false;
	// read Vectors from the file.
	// 
	int numInt;
	numInt = fread(vecArr, sizeof(Vector), size, fptr);
	//
	// if the number of integers is different from size (too
	// few or too many) return false
	// 
	//int numInt = 0;
	if (numInt != size)
	{
		fclose(fptr);
		return false;
	}

	// if everything is fine, fclose and return true
	fclose(fptr);
	return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
	// compare the x attribute first
	// If the first vector's x is less than the second vector's x
	// return -1
	/*
	   if (*(int*)p1 < *(int*)p2)
	   return -1;
	   if (*(int*)p1 > *(int*)p2)
	   return 1;
	   if (*(int*)p1 == *(int*)p2)
	   */

	Vector * vptr1 = (Vector*) p1;
	Vector * vptr2 = (Vector*) p2;

	if ((vptr1 -> x) < (vptr2 -> x))
		return -1;
	else if ((vptr1 -> x) > (vptr2 -> x))
		return 1;
	else if ((vptr1 -> x) == (vptr2 -> x))
	{
		if ((vptr1 -> y) < (vptr2 -> y))
			return -1;
		else if ((vptr1 -> y) > (vptr2 -> y))
			return 1;
		else if ((vptr1 -> y) == (vptr2 -> y))
		{
			if ((vptr1 -> z) < (vptr2 -> z))
				return -1;
			else if ((vptr1 -> z) > (vptr2 -> z))
				return 1;
		}  
	}
	return 0;
	// If the first vector's x is greater than the second vector's x
	// return 1
	// If the two vectors' x is the same, compare the y attribute
	//
	// If the first vector's y is less than the second vector's y
	// return -1
	// If the first vector's y is greater than the second vector's y
	// return 1
	// If the two vectors' y is the same, compare the z attribute
	//
	// If the first vector's z is less than the second vector's z
	// return -1
	// If the first vector's z is greater than the second vector's z
	// return 1
	// If the two vectors' x, y, z are the same (pairwise), return 0
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
	FILE * fptr = fopen(filename, "w");
	// if fopen fails, return false
	if (fptr == NULL)
		return false;
	
	int numWrite = 0;
	//numWrite = fwrite(vecArr, size, sizeof(Vector), fptr);
	numWrite = fwrite(vecArr, sizeof(Vector), size, fptr);

	// write the array to file using fwrite
	// need to check how many have been written
	// if not all are written, fclose and return false
	// 
	if (numWrite != size)
	{
		fclose(fptr);
		return false;
	}
	fclose(fptr);
	return true;
	// fclose and return true
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size) 
{
	int ind = 0;
	for (ind = 0; ind < size; ind ++)
	{
		printf("%6d %6d %6d\n",
				vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
	}
}
