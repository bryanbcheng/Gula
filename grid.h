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

class Grid
	{
	public:
		void Setup(int x, int y);
		void Draw();
		
	private:
		float x_dim;
		float y_dim;
	};

#endif // __GRID_H__
