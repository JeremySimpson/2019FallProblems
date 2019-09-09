// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{

	FILE * fptr = fopen(filename, "r"); //opens a file named "filename" and reads it

	if (fptr == NULL) //returns FALSE if file cannot be opened
	{
		return false;
	}


	int onechar; //index of character in file
	onechar = fgetc(fptr); //assigns the character at fptr to onechar
	while (onechar != EOF) //continues until end of file
	{

		if (onechar >= 0 && onechar <= (size - 1)) //counts if onechar is within file
		{
			counts[onechar] ++; //counts the frequency of the character
		}
		onechar = fgetc(fptr); //moves forward in the file
	}  

	fclose (fptr); //closes the file

	return true; //returns successful
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{ 
	int onechar; //initializes counter variable

	for (onechar = 0; onechar <= size - 1; onechar++) //continues throughout entire document
	{
		if (counts[onechar] !=0) //counts if the character appears in document
		{
			if (onechar < 65 || (onechar > 90 && onechar < 97) || (onechar > 122)) //prints space if character is not a lowercase or uppercase letter
				printf("%d,  , %d\n", onechar, counts[onechar]);
			else //prints letter
				printf("%d, %c, %d\n", onechar, onechar, counts[onechar]);
		}
	}
}
#endif
