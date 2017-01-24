// Ellipse.h
#ifndef _ELL_H
#define _ELL_H

class Ellipse :public Shape
{
public:
	Ellipse::Ellipse(char* name, Pair centre, Pair axes) :Shape(name, centre, axes){}
	~Ellipse(){}
	Pair CalculateCentre();
	void Report();
};

#endif
