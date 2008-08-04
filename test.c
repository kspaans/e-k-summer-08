/* A program to test the field-printer function.
 * Kyle Spaans, August 2008
 * meant to be included with main.c
 */

#include <stdio.h>
#include "dict.h"

int tester(void)
{
	int f[5][5] = {
	    {1,6,11,16,21},
	    {2,7,12,17,22},
	    {3,8,13,18,23},
	    {4,9,14,19,24},
	    {5,10,15,20,25}
	};
	int x = 5;
	int y = 5;

	printf("About to test the printer function.\n\n");
	viz(f,x,y);
	printf("\n\nDone testing.");
	return(0);
}
