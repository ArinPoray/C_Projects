/*************************************************************************************************************************************
Filename :					Pair.cpp
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
Purpose :					Contains the function definitions in Pair class
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

Pair Pair::operator+(Pair& rP){
	Pair tempPair;
	tempPair.x = x + rP.x;
	tempPair.y = y + rP.y;
	return tempPair;
}

Pair Pair::operator/(double divisor){
	Pair tempPair;
	tempPair.x = x / divisor;
	tempPair.y = y / divisor;
	return tempPair;
}

void Pair::Report(){
	cout << "x = " << x << "; y = " << y << endl;
}

