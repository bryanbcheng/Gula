/*
 *  main.cpp
 *  Gula
 *
 *  Created by Bryan Cheng on 8/16/11.
 *  Copyright 2011 Toucan Labs. All rights reserved.
 *
 */

// Standard libraries
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Standard classes
#include <string>
#include <vector>
using std::vector;
#include <iostream>
using namespace std;

// Project classes
#include "main.h"
#include "grid.h"
#include "ingredient.h"
#include "instruction.h"

// OpenGL library
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int win_width = 512;
int win_height = 512;

// A grid to draw.
static Grid grid;

vector<Ingredient *> ingredients; // list of all the ingredients
vector<Instruction *> instructions; // list of all the instructions

void Parse()
{
	// parse the instructions
	/*
	FILE * configFile = fopen(configFname, "r");
    char fileLine[BUFSIZ];
	
    if(!configFname)
    {
        fprintf(stderr, "Cannot open file %s\n", configFname);
        return;
    }
	
    while( fgets(fileLine, BUFSIZ, configFile) )
    {
        std::string fileLineStr(fileLine);
		
        // Parse windows newline correctly ("\r\n")
        if(fileLineStr[fileLineStr.size()-2] == '\r' &&
		   fileLineStr[fileLineStr.size()-1] == '\n' )
        {
            fileLineStr[fileLineStr.size()-2] = '\0';
        }
        // replace newline with NULL character
        else if(fileLineStr[fileLineStr.size()-1] == '\n')
        {
            fileLineStr[fileLineStr.size()-1] = '\0';
        }
		
        // read valid attribute/value pairs
        if(fileLineStr.substr(0,11) == "background1") {
            strcpy(image1fnameOut, fileLineStr.substr(12).c_str());
            *im1out = new STImage(image1fnameOut);
        }
        else if(fileLineStr.substr(0,11) == "background2") {
            strcpy(image2fnameOut, fileLineStr.substr(12).c_str());
            *im2out = new STImage(image2fnameOut);
        }
        else if(fileLineStr.substr(0,8) == "savefile") {
            strcpy(saveFnameOut, fileLineStr.substr(9).c_str());
        }
        else if(fileLineStr.substr(0,8) == "loadfile") {
            strcpy(loadFnameOut, fileLineStr.substr(9).c_str());
        }
    }
    fclose(configFile);
	 */
}

void Setup()
{
	Ingredient *i = new Ingredient(string("tomato"));
	Ingredient *i2 = new Ingredient(string("eggs"));
	ingredients.push_back(i);
	ingredients.push_back(i2);
	cout << i->getName();
	
	grid.Setup(instructions.size() + 1, ingredients.size());
	
	win_width = (instructions.size() + 1) * 60;
	win_height = ingredients.size() * 60;
	
	cout << "height: " << win_height << " width: " << win_width;
}

void Generate()
{
	// Fills first column with ingredients
	for (int i = 0; i < ingredients.size(); i++) {
		grid.Draw(0, i, "image " + ingredients[i]->getName());
	}
}

void display( void )
{
	glClear( GL_COLOR_BUFFER_BIT );
	
	glutSwapBuffers();
}

void reshape( int w, int h )
{
	/*
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	
	glOrtho( 0., 1., 0., 1., -1., 1. );
	glViewport( 0, 0, w, h );
	
	win_width = w;
	win_height = h;
	*/
	glutPostRedisplay();
}

void keyboard( unsigned char key, int x, int y ) {
	switch(key) {
		case 27: // Escape key
			exit(0);
			break;
	}
}

void mouse( int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		exit(0);
	}
}

int main (int argc, char *argv[]) {
	
	glutInit( &argc, argv );
	
	Parse();
	Setup();
	
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
	glutInitWindowSize( win_width, win_height );
	
	glutCreateWindow( "Gula" );
	
	Generate();
	
	glutDisplayFunc( display );
	glutReshapeFunc( reshape );
	glutKeyboardFunc( keyboard );
	glutMouseFunc( mouse );
	
	glutMainLoop();
}