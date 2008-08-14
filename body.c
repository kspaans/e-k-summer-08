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
