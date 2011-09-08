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
		Instruction(vector<Ingredient> _ingredients, string _action, string _quality, string _temperature, string _duration, string _time_measurement, string _location);
		~Instruction();
		
		//void Setup();
		//void Draw();
		
	private:
		vector<Ingredient> ingredients;
		string action;
		string quality;
		string temperature;
		
		string duration;
		string time_measurement;
		
		string location;
	};

#endif // __INSTRUCTION_H__
