/*************************************************************************************************************************************
Filename :					Rectangle.cpp
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
Purpose :					Contains the function definitions in Rectangle class
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

Pair Rectangle::CalculateCentre(){
	return (p1 + p2) / 2;
}

void Rectangle::Report(){
	cout << "Shape RECTANGLE " << this->name << endl;
	cout << "top left coordinates: ";
	p1.Report();
	cout << "bottom right coordinates: ";
	p2.Report();
}