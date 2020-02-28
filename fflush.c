/* In this project, we've used an universal method of getting input
	 * This is because scanf() and gets() don't work together well (they cause problems for each other)
	 * so the universal method of getting input contains following steps
	 *
	 *  STEP 1: Capture everything the user types in a string (large enough) using fgets()
	 *  STEP 2: Convert that string into any desired data type
	 *
	 * In this project, tmp[50] works as the large variable to store everything user types.
	 * Then, we can use
	 *       strtol() function to convert it into integer

	 strtol(temp, NULL, 10);
	* converts string into long integer (str-to-l)
	 * temp = string to be converted
	 * NULL = variable to put the rest of the invalid string (after conversion)
	 * 10 = base (10 for decimal, 16 for hexa, etc...
	 *
	 * We used this way to prevent problems caused by scanf() and gets()

        strtof() function to convert it into float
        strtof(temp, NULL); /* converts string into floating number (str-to-f)*/
#include "project.h"
/* This function is a modified version of fgets()
 * It is required because scanf() and gets() don't work together well!
 * Plus, the fgets() has a slight problem
 */
char *getstr(char* string, int size, FILE* fptr)
{
	int len;

	fgets(string, size, fptr);
	len = strlen(string);

	/* after typing the text, we hit [Enter] key to submit the text.
	 * but fgets() takes that [Enter] character (which is '\n') as a part of the input.
	 * So when we print the string, a new line is automatically printed at the end.
	 * To solve this problem, we create a new function that converts that last '\n' into '0\
	 */

	if (len>0 && string[len-1]=='\n')
		string[len-1] = '\0';
		return string;

}




