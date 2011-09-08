/*
 *  instruction.cpp
 *  Gula
 *
 *  Created by Bryan Cheng on 8/16/11.
 *  Copyright 2011 Toucan Labs. All rights reserved.
 *
 */

#include "instruction.h"

Instruction::Instruction()
{
	
}

Instruction::Instruction(vector<Ingredient> _ingredients, string _action, string _quality, string _temperature, string _duration, string _time_measurement, string _location)
{
	ingredients = _ingredients;
	action = _action;
	quality = _quality;
	temperature = _temperature;
	duration = _duration;
	time_measurement = _time_measurement;
	location = _location;
}

Instruction::~Instruction()
{
	
}
