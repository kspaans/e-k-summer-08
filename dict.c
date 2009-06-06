/* Copyright 2008 Erik Louie, Kyle Spaans
 * elouie@student.cs.uwaterloo.ca, kspaans@student.math.uwaterloo.ca
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the Artistic License 2.0 as published by
 *   the Perl Foundation. You may obtain a copy of the license at
 *
 *   http://www.perlfoundation.org/artistic_license_2_0
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   Artistic License 2.0 for more details.
 *
 */
/* Erik & Kyle Summer 2008
 * Conway's Game of Life
 *
 * Main Program:
 * Calls the fundamental functions as needed, and has the printing routines for
 * visualization.
 */

#include <stdio.h>
#include <stdlib.h>
#include "dict.h"

int field_get(int x, int y)
{
	if ( (x<NCOLS) && (y<NROWS) ) { /* within bounds */
		return(fld[x][y]);
	} else {
		return(-1);
	}
}

int killf(int x, int y)
{
	if((x < NCOLS) && (y < NROWS)){
		fld[x][y] = 0;
		return(1);
	} else {
		printf("ERROR: The point (%d,%d) is out of bounds.", x, y);
		return(0);
	}
}

int spawn(int x, int y)
{
	if((x < NCOLS) && (y < NROWS)){
		fld[x][y] = 1;
		return(1);
	} else {
		printf("ERROR: The point (%d,%d) is out of bounds.", x, y);
		return(0);
	}
}

int friends(int x, int y)
{
	int count = 0;
	int i,j;

	/* LAWL NOOB nest(nest(nested!)ed!)ed! */
	if((x < NCOLS) && (y < NROWS)){
#		ifdef DEBUG
		printf("  friends are ");
#		endif /* DEBUG */
		for( j = -1; j < 2; j++){
			for( i = -1; i < 2; i++){
				if((x+i < NCOLS) && (y+j < NROWS) && (x+i >= 0) && (y+j >= 0)){
					if((i != 0) || (j != 0)){
#						ifdef DEBUG
						printf("%d ", fld[x+i][y+j]);
#						endif /* DEBUG */
						count += field_get(x + i, y + j); /* fld[x+i][y+j] */
					}
				}
			}
		}
#		ifdef DEBUG
		printf("\n");
#		endif /* DEBUG */
		return count;
	} else {
		printf("ERROR: The point (%d,%d) is out of bounds.", x, y);
		return -1;
	}
}

action_list *rule(int x, int y, int n)
{
	int test = field_get(x,y);
	action_list *result;

	result = malloc(sizeof(action_list));
	if (result == NULL) {
		printf("ERROR: rule: could not allocate result\n");
		exit(1);
	} /* if */
	result->x = x;
	result->y = y;
	result->next = NULL;

	/* If the cell is alive */
	if (test == 1) {
		switch (n) {
			case 2:  result->action = spawn; break;
			case 3:  result->action = spawn; break;
			default: result->action = killf; break;
		} /* switch */
	} else if (test == -1) {
		printf("ERROR: Points out of bounds in rule(): (%d,%d)", x, y);
		exit(1);
	/* If the cell is dead */
	} else {
		switch (n) {
			case 3:  result->action = spawn; break;
			default: result->action = killf; break;
		} /* switch */
	} /* if */
	return result;
} /* end rule */

/* Cells are being killed before the end of the generation!
 * When the next cell checks for it's neighbours, ones that should be
 * there are already dead...
 */
int generator(int n)
{
	int i,j;
	action_list *head = NULL;
	action_list **tail = &head;

#	if 0
	head = malloc(sizeof(action_list));
	if (head == NULL) {
		printf("ERROR: generator: could not allocate head\n");
		exit(1);
	} /* if */
	/* Ugh, terrible, style, how can I init head once outside of the loop?
	 */
	head->action = NULL;
	head->x = -1;
	head->y = -1;
	head->next = tail;
#	endif

	for(j = 0; j < NROWS ; j += 1) {
		for(i = 0; i < NCOLS; i += 1) {
			action_list *new = rule(i,j,friends(i,j));
			*tail = new;
			tail = &new->next;
#			ifdef DEBUG
			printf("Friends(%d,%d): %d\n", i, j, friends(i,j));
#			endif /* DEBUG */
		} /* for */
	} /* for */

	/* now traverse that list and perform the actions in it
	 */
	do {
		head->action(head->x, head->y);
		head = head->next;
	} while (head != NULL);

	return 0;
} /* end generator */
