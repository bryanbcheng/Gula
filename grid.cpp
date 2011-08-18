/*
 *  grid.cpp
 *  Gula
 *
 *  Created by Bryan Cheng on 8/16/11.
 *  Copyright 2011 Toucan Labs. All rights reserved.
 *
 */

#include <stdio.h>
#include <iostream>
using namespace std;

#include "grid.h"
//#include "stgl.h"
//#include "stglut.h"

/**
 * Setup the grid
 */
void Grid::Setup(int x, int y)
{
	x_dim = x;
	y_dim = y;
	
	// Set up sizes
	gridMap.resize(x);
	for (int i = 0; i < x; ++i)
		gridMap[i].resize(y);
}


/**
 * Draw your grid here
 */
void Grid::Draw(int x, int y, string action)
{
	// parse action
	
	// if image call something to place the image in that block
	
	
	gridMap[x][y] = true;
}
