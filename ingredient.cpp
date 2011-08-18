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

Ingredient::Ingredient(string n)
{
	name = n;
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