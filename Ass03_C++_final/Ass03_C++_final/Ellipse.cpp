/*************************************************************************************************************************************
Filename :					Ellipse.cpp
Version :					1.0
Author / Student name :		Arin Kumar Poray
Student number :			040797800
Course name and number :	C++ programming  ( CST8219 )
Lab section number :		300
Assignment number :			3
Assignment name :			Vector Graphic
Due date :					3rd December, 2016
Submission date :			3rd December, 2016
Professor's name :			Andrew Tyler
Purpose :					Contains the function definitions in Ellipse class
*************************************************************************************************************************************/

#include "Pair.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

#include <iostream>
using namespace std;

Pair Ellipse::CalculateCentre(){
	return p1;
}

void Ellipse::Report(){
	cout << "Shape ELLIPSE " << this->name << endl;
	cout << "centre coordinates: ";
	CalculateCentre().Report();
	cout << "axes dimensions: ";
	p2.Report();
}