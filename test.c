/* A program to test the field-printer function.
 * Kyle Spaans, August 2008
 * meant to be included with main.c
 */

#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef DICT_H
#include "dict.h"
#define DICT_H
#endif

/* For the testing print loop */
//#define TEST
/**********/

int tester(void)
{
	int i,j;

	fld = malloc(NROWS * sizeof(int *));/*[5][5] = {
	    {1,6,11,16,21},
	    {2,7,12,17,22},
	    {3,8,13,18,23},
	    {4,9,14,19,24},
	    {5,10,15,20,25}
	};*/
	if(fld == NULL){
		printf("Oops, couldn't ``malloc''?");
		return(1);
	}
	for(i=0; i<NROWS; i++){
		fld[i] = malloc(NCOLS * sizeof(int));
		if(fld[i] == NULL){
			printf("Hmm, couldn't do the second-dimension ``malloc''.");
			return(1);
		}
	}

	/* Initialize the array! */
	int e = 0;
	for(j=0;j<NROWS;j++){
		for(i=0;i<NCOLS;i++){
			fld[i][j] = e;
			e++;
		}
	}
			

	#ifdef TEST
	for(j=0;j<NROWS;j++){
		for(i=0;i<NCOLS;i++){
			printf("%d\t",fld[i][j]);
			if((i+1) == x) printf("\n");
		}
	}
	#endif

	printf("About to test the printer function.\n\n");
	viz(fld);
	/* Should show:
	0	1	2
	3	4	5
	6	7	8
	Or some similar such, depending on NCOLS and NROWS
	*/

	/* Kill all cells! They should be all 0's now.*/
	for(j=0;j<NROWS;j++){
		for(i=0;i<NCOLS;i++){
			killf(i,j);
		}
	}
	viz(fld);
	/* Spawn all cells! They should be all 1's now.*/
	for(j=0;j<NROWS;j++){
		for(i=0;i<NCOLS;i++){
			spawn(i,j);
		}
	}
	viz(fld);

	printf("A corner cell should have 3 live neighbours: %d\n", friends(0,0));
	printf("A middle cell should have 8 live neighbours: %d\n", friends(1,1));
	printf("A  side  cell should have 5 live neighbours: %d\n", friends(1,0));

	/* Try some basic tests of the generator and rule. */
	for(j=0;j<NROWS;j++){
		for(i=0;i<NCOLS;i++){
			killf(i,j);
		}
	}
	spawn(0,1);
	spawn(1,1);
	spawn(2,1);
	viz(fld);
	generator(1);
	viz(fld);
	generator(1);
	viz(fld);

	

	printf("\n\nDone testing.\n\n");
	return(0);
}
