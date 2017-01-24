/*************************************************************************************************************************************
Filename :					GraphicElement.cpp
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
Purpose :					Contains the function definitions and the definitions for the overloaded operators in GraphicElement class
*************************************************************************************************************************************/


#include "Pair.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"
#include <string>

/*************************************************************************************************************************************
* Function name:	3 argument constructor for the GraphicElement class
* Purpose:			instantiates an object of GraphicElement
* In parameters:	pointer to an array of Shape pointers,
*					pointer to an array of character array and
*					number of Shapes in the soon-to-be instantiated GraphicElement
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
GraphicElement::GraphicElement(Shape **rS, char *name, unsigned int numShapes){
	strcpy_s(this->name, name);
	for (unsigned int i = 0; i < numShapes; i++) {
		push_back(rS[i]);
	}
}

/*************************************************************************************************************************************
* Function name:	destructor for the GraphicElement class
* Purpose:			destroys an object of GraphicElement
* In parameters:	none
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
GraphicElement::~GraphicElement(){}

/*************************************************************************************************************************************
* Function name:	Copy constructor for the GraphicElement class
* Purpose:			instantiates an object of GraphicElement which is a copy of the GraphicElement received as argument
* In parameters:	reference to the GraphicElement which needs to be copied
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
GraphicElement::GraphicElement(const GraphicElement& rGE){
	strcpy_s(this->name, rGE.name);
	for (GraphicElement::const_iterator i = rGE.begin(); i != rGE.end(); i++) {
		push_back(*i);
	}
}

/*************************************************************************************************************************************
* Function name:	Overloaded operator = for GraphicElement
* Purpose:			returns a reference to a Graphic Element which is a copy of the GraphicElement received as argument
* In parameters:	reference to a GraphicElement which needs to be copied
* Out parameters:	reference to a GraphicElement just copied into
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
GraphicElement& GraphicElement::operator=(GraphicElement& rGE){
	clear();
	strcpy_s(this->name, rGE.name);
	for (GraphicElement::const_iterator i = rGE.begin(); i != rGE.end(); i++) {
		push_back(*i);
	}
	return *this;
}

/*************************************************************************************************************************************
* Function name:	Overloaded output stream for GraphicElement
* Purpose:			prints a GraphicElement object on the standard output (screen)
* In parameters:	reference to a standard output stream object
*					reference to a GraphicElement object in memory
* Out parameters:	reference to the same standard output stream object received as input
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
ostream& operator<<(ostream& out, GraphicElement& rGE){
	Pair centre;
	out << "Graphic Element " << rGE.name << endl;
	for (GraphicElement::iterator i = rGE.begin(); i != rGE.end(); i++){
		centre = centre + (*i)->CalculateCentre();
	}
	centre = centre / rGE.size();
	out << "The Centre = ";
	centre.Report();
	out << "List of Shapes in " << rGE.name << endl;
	for (GraphicElement::iterator i = rGE.begin(); i != rGE.end(); i++){
		(*i)->Report();
	}
	out << endl;
	return out;
}

