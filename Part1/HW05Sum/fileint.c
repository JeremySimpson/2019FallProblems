// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
	FILE * fptr = fopen(filename, "r"); //opens a file named "filename" and reads it

	if (fptr == NULL) //returns FALSE if file cannot be opened
	{
		return false;
	}
	
	//int onechar; //index of character in file
	
	* sum = 0;
	int sumtemp = 0;
	//int sumtotal = 0;
	//int *sumnum = 0;
	while ((fscanf(fptr,"%d",&sumtemp) == 1)) //assigns the character at fptr to onechar
	{
		
		*sum += sumtemp;
		
		//printf("7gvftm = %d\n", *sum);	
		//sumtemp = *sumnum;
	}
	//printf("sum = %d\n", *sum);	
			
	/*
	while (onechar != EOF) //continues until end of file
	{

		if (onechar >= 0 && onechar <= (size - 1)) //counts if onechar is within file
		{
			counts[onechar] ++; //counts the frequency of the character
		}
		onechar = fgetc(fptr); //moves forward in the file
	}  
	*/
	
	fclose (fptr); //closes the file
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  //
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
	FILE * fptr = fopen(filename, "w");
	
	if (fptr == NULL) //returns FALSE if file cannot be opened
	{
		return false;
	}
	
        fprintf(fptr, "%d\n", sum);
	fclose(fptr);
  // open a file whose name is filename for writing
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //
  return true;
}
#endif
