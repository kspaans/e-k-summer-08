/* A program to test the field-printer function.
 * Kyle Spaans, August 2008
 * meant to be included with main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "dict.h"

/* For the testing print loop */
//#define TEST
/**********/

int tester(void)
{
	int x = 5;
	int y = 5;
	int i,j;
	int **f = malloc(y * sizeof(int *));/*[5][5] = {
	    {1,6,11,16,21},
	    {2,7,12,17,22},
	    {3,8,13,18,23},
	    {4,9,14,19,24},
	    {5,10,15,20,25}
	};*/
	if(f == NULL){
		printf("Oops, couldn't ``malloc''?");
		return(1);
	}
	for(i=0; i<y; i++){
		f[i] = malloc(x * sizeof(int));
		if(f[i] == NULL){
			printf("Hmm, couldn't do the second-dimension ``malloc''.");
			return(1);
		}
	}

	/* Initialize the array! */
	int e = 0;
	for(j=0;j<y;j++){
		for(i=0;i<x;i++){
			f[i][j] = e;
			e++;
		}
	}
			

	#ifdef TEST
	for(j=0;j<y;j++){
		for(i=0;i<x;i++){
			printf("%d\t",f[i][j]);
			if((i+1) == x) printf("\n");
		}
	}
	#endif

	printf("About to test the printer function.\n\n");
	viz(f,x,y);
	printf("\n\nDone testing.\n\n");
	return(0);
}
