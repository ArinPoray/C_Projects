/*************************************************************************************************************************************
Filename :					VectorGraphic.cpp
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
Purpose :					Contains the function definitions and the definitions for the overloaded operators in VectorGraphic class
*************************************************************************************************************************************/

#include "Pair.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

/*************************************************************************************************************************************
* Function name:	default constructor for the VectorGraphic class
* Purpose:			constructs a vector of objects of type GraphicElement
* In parameters:	none
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
VectorGraphic::VectorGraphic(){}


/*************************************************************************************************************************************
* Function name:	destructor for the VectorGraphic class
* Purpose:			destroys objects of type VectorGraphic contained in a vector
* In parameters:	none
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
VectorGraphic::~VectorGraphic(){
	for (VectorGraphic::iterator i = begin(); i != end(); i++) {
		for (unsigned int j = 0; j < i->size(); j++) {
			delete i->at(j);
		}
	}
}

/*************************************************************************************************************************************
* Function name:	AddGraphicElement
* Purpose:			adds one GraphicElement per call at the end of a vector of GraphicElements
* In parameters:	none
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
void VectorGraphic::AddGraphicElement(){
	char elementName[256];
	char tempName[256];
	unsigned int numShapes;
	char choice;
	Shape** pShapesArray;
	double x, y;
	Pair* p1;
	Pair* p2;
	unsigned int i = 0;

	cout << "Adding a Graphic Element" << endl;
	cout << "Please enter the name of the new Graphic Element (<256 characters): ";
	cin.ignore();
	cin.getline(elementName, 256);
	cout << "Please enter the number of Shapes it contains: ";
	cin >> numShapes;
	pShapesArray = new Shape*[numShapes];
	while (numShapes != 0){
		cout << "Please enter the type (L for line, R for rectangle, E for ellipse) for Shape #" << i << endl;
		cin >> choice;
		switch (choice){
		case 'L':
			cout << "Please enter the name of the new line(<256 characters): ";
			cin.ignore();
			cin.getline(tempName, 256);
			cout << "please enter the coordinates of the start point: (x,y) ";
			cin >> x >> y;
			p1 = new Pair(x, y);
			cout << "please enter the coordinates of the end point: (x,y) ";
			cin >> x >> y;
			p2 = new Pair(x, y);
			pShapesArray[i] = new Line(tempName, *p1, *p2);
			break;
		case 'R':
			cout << "Please enter the name of the new Rectangle(<256 characters): ";
			cin.ignore();
			cin.getline(tempName, 256);
			cout << "please enter the coordinates of the top-left: (x,y) ";
			cin >> x >> y;
			p1 = new Pair(x, y);
			cout << "please enter the coordinates of the bottom-right: (x,y) ";
			cin >> x >> y;
			p2 = new Pair(x, y);
			pShapesArray[i] = new Rectangle(tempName, *p1, *p2);
			break;
		case 'E':
			cout << "Please enter the name of the new Ellipse(<256 characters): ";
			cin.ignore();
			cin.getline(tempName, 256);
			cout << "please enter the coordinates of the centre: (x,y) ";
			cin >> x >> y;
			p1 = new Pair(x, y);
			cout << "please enter the width and height: (width, height) ";
			cin >> x >> y;
			p2 = new Pair(x, y);
			pShapesArray[i] = new Ellipse(tempName, *p1, *p2);
			break;
		default:
			cout << "Invalid Choice" << endl;
			break;
		}
		numShapes--;
		i++;
		delete[]p1;
		delete[]p2;
	}
	GraphicElement temp(pShapesArray, elementName, i);
	push_back(temp);

	delete[]pShapesArray;
}

/*************************************************************************************************************************************
* Function name:	DeleteGraphicElement
* Purpose:			deletes a GraphicElement per call from a vector of GraphicElements
* In parameters:	none
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
void VectorGraphic::DeleteGraphicElement(){
	unsigned int deleteIndex;
	if (this->size() > 0){
		cout << "Deleting a Graphic Element" << endl;
		cout << "Please enter the index to delete in the range 0 to " << (this->size() - 1) << endl;
		cin >> deleteIndex;
		cout << "erase index = " << deleteIndex << endl;
		if (deleteIndex<size()){
			for (VectorGraphic::iterator i = begin() + deleteIndex; i < begin() + deleteIndex + 1; i++){
				for (unsigned int j = 0; j < i->size(); j++){
					delete i->at(j);
				}
			}
			erase(begin() + deleteIndex);
		}
		else{
			cout << "No GraphicElement at index " << deleteIndex << endl;
		}
	}
	else{
		cout << "No GraphicElement to delete" << endl;
	}
}

/*************************************************************************************************************************************
* Function name:	Overloaded output stream for VectorGraphic
* Purpose:			prints a VectorGraphic object on the standard output (screen)
* In parameters:	reference to a standard output stream object
*					reference to a GraphicElement object in memory
* Out parameters:	reference to the same standard output stream object received as input
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
ostream& operator<<(ostream& out, VectorGraphic& rVG){
	unsigned int j = 0;
	out << "VectorGraphice Report" << endl << endl;
	for (VectorGraphic::iterator i = rVG.begin(); i != rVG.end(); i++){
		out << "Reporting Graphic Element " << j << endl;
		out << *i << endl;
		j++;
	}
	out << endl;
	return out;
}