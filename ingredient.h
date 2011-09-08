/*
 *  ingredient.h
 *  Gula
 *
 *  Created by Bryan Cheng on 8/16/11.
 *  Copyright 2011 Toucan Labs. All rights reserved.
 *
 */


#ifndef __INGREDIENT_H__
#define __INGREDIENT_H__

//#include "st.h"

#include <string>
using std::string;

class Ingredient
	{
	public:
		Ingredient();
		Ingredient(string _name, string _quantity, string _measurement);
		~Ingredient();
		
		//void Setup();
		//void Draw();
		string getName();
		void setName(string n);
		
	private:
		string name;
		string quantity;
		string measurement;
		int id;
	};

#endif // __INGREDIENT_H__
