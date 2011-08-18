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

#include <string>
using std::string;
#include <vector>
using std::vector;

#include "ingredient.h"
//#include "st.h"

class Instruction
	{
	public:
		Instruction();
		~Instruction();
		
		//void Setup();
		//void Draw();
		
	private:
		vector<Ingredient> ingredients;
		string action;
		float quanity;
		string measurement;
		float duration;
		string time_measurement;
	};

#endif // __INSTRUCTION_H__
