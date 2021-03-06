// Shape.h
// abstract base class
#ifndef _SHAPE_H
#define _SHAPE_H

#include <string>

class Shape
{
protected:
	Pair p1;
	Pair p2;
	char name[256];
public:
	Shape(char* name, Pair p1, Pair p2) :p1(p1), p2(p2)
	{
		strcpy_s(this->name, name);
	};
	virtual ~Shape(){};
	virtual Pair CalculateCentre() = 0;// no body
	virtual void Report() = 0;	// no body
};

#endif