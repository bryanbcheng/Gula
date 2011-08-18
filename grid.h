/*
 *  grid.h
 *  Gula
 *
 *  Created by Bryan Cheng on 8/16/11.
 *  Copyright 2011 Toucan Labs. All rights reserved.
 *
 */

#ifndef __GRID_H__
#define __GRID_H__

//#include "st.h"

#include <string>
using std::string;
#include <vector>
using std::vector;

class Grid
	{
	public:
		void Setup(int x, int y);
		void Draw(int x, int y, string action);
		
	private:
		int x_dim;
		int y_dim;
		vector<vector<bool> > gridMap;
	};

#endif // __GRID_H__
