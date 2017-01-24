// Line.h
#ifndef _LINE_H
#define _LINE_H

class Line :public Shape
{
public:
	Line(char* name, Pair start, Pair end) :Shape(name, start, end){};
	~Line(){}
	Pair CalculateCentre();
	void Report();
};

#endif