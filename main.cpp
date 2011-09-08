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
#include <fstream>
using namespace std;

// Project classes
#include "main.h"
#include "grid.h"
#include "ingredient.h"
#include "instruction.h"

// XML Parser
#include "tinyxml.h"
#include "tinystr.h"

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

const char * getIndent( unsigned int numIndents )
{
    static const char * pINDENT = "                                      + ";
    static const unsigned int LENGTH = strlen( pINDENT );
	
    if ( numIndents > LENGTH ) numIndents = LENGTH;
	
    return &pINDENT[ LENGTH-numIndents ];
}

void dump_to_stdout( TiXmlNode * pParent, unsigned int indent = 0 )
{
    if ( !pParent ) return;
	
    TiXmlText *pText;
    int t = pParent->Type();
    printf( "%s", getIndent( indent));
	
    switch ( t )
    {
		case TiXmlNode::TINYXML_DOCUMENT:
			printf( "Document" );
			break;
			
		case TiXmlNode::TINYXML_ELEMENT:
			printf( "Element \"%s\"", pParent->Value() );
			break;
			
		case TiXmlNode::TINYXML_COMMENT:
			printf( "Comment: \"%s\"", pParent->Value());
			break;
			
		case TiXmlNode::TINYXML_UNKNOWN:
			printf( "Unknown" );
			break;
			
		case TiXmlNode::TINYXML_TEXT:
			pText = pParent->ToText();
			printf( "Text: [%s]", pText->Value() );
			break;
			
		case TiXmlNode::TINYXML_DECLARATION:
			printf( "Declaration" );
			break;
		default:
			break;
    }
    printf( "\n" );
	
    TiXmlNode * pChild;
	
    for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) 
    {
        dump_to_stdout( pChild, indent+2 );
    }
}

void parse_ingredient( TiXmlNode * pParent )
{
	TiXmlNode * pChild;
	
	string name, quantity, measurement;
	
	for (pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
	{
		if (strcmp(pChild->Value(), "name") == 0) {
			name = pChild->ToElement()->GetText();
		} else if (strcmp(pChild->Value(), "quantity") == 0) {
			quantity = pChild->ToElement()->GetText();
		} else if (strcmp(pChild->Value(), "measurement") == 0) {
			measurement = pChild->ToElement()->GetText();
		}
	}
	
	Ingredient *i = new Ingredient(name, quantity, measurement);
	ingredients.push_back(i);
}

void parse_instruction( TiXmlNode * pParent )
{
	TiXmlNode * pChild;
	
	vector<Ingredient> _ingredients;
	string action, quality, temperature, duration, time_measurement, location;
	
	for (pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
	{
		if (strcmp(pChild->Value(), "ingredient") == 0) {
			//_ingredients = pChild->ToElement()->GetText();
		} else if (strcmp(pChild->Value(), "action") == 0) {
			action = pChild->ToElement()->GetText();
		} else if (strcmp(pChild->Value(), "quality") == 0) {
			quality = pChild->ToElement()->GetText();
		} else if (strcmp(pChild->Value(), "temperature") == 0) {
			temperature = pChild->ToElement()->GetText();
		} else if (strcmp(pChild->Value(), "duration") == 0) {
			duration = pChild->ToElement()->GetText();
		} else if (strcmp(pChild->Value(), "time_measurement") == 0) {
			time_measurement = pChild->ToElement()->GetText();
		} else if (strcmp(pChild->Value(), "location") == 0) {
			location = pChild->ToElement()->GetText();
		}
	}
	
	Instruction *i = new Instruction(_ingredients, action, quality, temperature, duration, time_measurement, location);
	instructions.push_back(i);
}

void parse_xml( TiXmlNode * pRoot )
{
	int t = pRoot->Type();
	
	if (t == TiXmlNode::TINYXML_DOCUMENT)
	{
		TiXmlNode * pParent;
		for (pParent = pRoot->FirstChild(); pParent != 0; pParent = pParent->NextSibling()) 
		{
			if (pParent->Type() == TiXmlNode::TINYXML_ELEMENT && strcmp(pParent->Value(), "recipe") == 0)
			{
				TiXmlNode * pChild;
				for (pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
				{
					if (strcmp(pChild->Value(), "title") == 0) {
						// title = pChild->FirstChild()->ToText()->Value();
					} else if (strcmp(pChild->Value(), "description") == 0) {
						// description = pChild->FirstChild()->ToText()->Value();
					} else if (strcmp(pChild->Value(), "ingredient") == 0) {
						parse_ingredient( pChild );
					} else if (strcmp(pChild->Value(), "instruction") == 0) {
						parse_instruction( pChild );
					}
				}
			}
		}
	} else {
		printf("Error (not document)");
	}
}

void Parse()
{	
	const char* pFilename = "template.xml";
	TiXmlDocument doc( pFilename );
	
	bool loadOkay = doc.LoadFile();
	//cout << "load file: " << doc.LoadFile() << endl;
	//cout << "error: " << doc.Error() << " id: " << doc.ErrorId() << " descp: " << doc.ErrorDesc() << " " << doc.ErrorRow() << ", " << doc.ErrorCol() << endl;
	if (loadOkay)
	{
		printf("\n%s:\n", pFilename);
		parse_xml( &doc );
		//dump_to_stdout( &doc );
	}
	else
	{
		printf("Failed to load file \"%s\"\n", pFilename);
	}
}

void Setup()
{
	//cout << "instruc size"
	
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