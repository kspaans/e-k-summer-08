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
#include "dict.h"

int main(int argc, char *argv[]);
{
	return 0;
}

/* IDEA: print to stdout (which can be redirected to a file) the
 * contents of the array.
 * This will get real ugly, real fast. :D
 * Takes:
 *  - (2D) Array of arrays representing the field
 *  - An integer, x, the horizontal width of the field
 *  - An integer, y, the vertical  height of the field
 */

void viz(int field[][], int x, int y)
{
	int i,j; //i is the width, j the height

	printf("CONWAY'S GAME OF LIFE\nHere is the state of the field\n");
	for(j=0;j<y;j++){
		for(i=0;i<x;i++){
			printf("%d",field[i][j]);
			if((i-1) == x)
				printf("\n");
		}
	}
}
