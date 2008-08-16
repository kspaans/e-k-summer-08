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

int field_get(int x, int y)
{
	if ( (x<NCOLS) && (y<NROWS) ) { //within bounds
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
		for( j = -1; j < 2; j++){
			for( i = -1; i < 2; i++){
				if((x+i < NCOLS) && (y+j < NROWS) && (x+i >= 0) && (y+j >= 0)){
					if((i != 0) || (j != 0)){
						count += fld[x+i][y+j];
					}
				}
			}
		}
		return(count);
	} else {
		printf("ERROR: The point (%d,%d) is out of bounds.", x, y);
		return(-1);
	}
}

int rule(int x, int y, int n)
{
/*	switch( n ) {
		case 2: // do nothing?
		case 3: spawn(x, y);
		default: killf(x, y);
	}*/
	int test = field_get(x,y);

	if ( test == 1 ) { // If the cell is alive (1)
		switch(n) {
			case 2 : spawn(x,y); //do nothing?
			case 3 : spawn(x,y); //do nothing?
			default : killf(x,y);
		}
		return(0);
	} else if ( test == -1 ) {
		printf("ERROR: Points out of bounds in rule(): (%d,%d)", x, y);
		return(test);
	} else { // The cell is dead (0)
		switch(n) {
			case 3 : spawn(x,y);
			default : killf(x,y); //do nothing?
		}
		return(0);
	}

}

int generator(int n)
{
	for( int j = 0; j < NROWS ; j++ ) {
		for( int i = 0; i < NCOLS; i++ ) {
			rule(i,j,friends(i,j));
		}
	}	
	return(0);
}
