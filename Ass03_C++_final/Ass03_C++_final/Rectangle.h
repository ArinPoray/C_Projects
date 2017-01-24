// Rectangle.h
#ifndef _RECT_H
#define _RECT_H

class Rectangle :public Shape
{
public:
	Rectangle(char* name, Pair topLeft, Pair bottomRight) :Shape(name, topLeft, bottomRight){};
	~Rectangle(){}
	Pair CalculateCentre();
	void Report();
};

#endif