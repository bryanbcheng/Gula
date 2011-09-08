/*
 *  ingredient.cpp
 *  Gula
 *
 *  Created by Bryan Cheng on 8/16/11.
 *  Copyright 2011 Toucan Labs. All rights reserved.
 *
 */

#include "ingredient.h"

Ingredient::Ingredient()
{
	
}

Ingredient::Ingredient(string _name, string _quantity, string _measurement)
{
	name = _name;
	quantity = _quantity;
	measurement = _measurement;
}

Ingredient::~Ingredient()
{
	
}

string Ingredient::getName()
{
	return name;
}

void Ingredient::setName(string n)
{
	name = n;
}