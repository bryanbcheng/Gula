/*
 *  instruction.h
 *  Gula
 *
 *  Created by Bryan Cheng on 8/16/11.
 *  Copyright 2011 Toucan Labs. All rights reserved.
 *
 */

#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <vector>

#include "ingredient.h"
//#include "st.h"

class Instruction
	{
	public:
		//void Setup();
		//void Draw();
		
	private:
		std::vector<Ingredient> ingredients;
		char * action;
		float quanity;
		char * measurement;
	};

#endif // __INSTRUCTION_H__
