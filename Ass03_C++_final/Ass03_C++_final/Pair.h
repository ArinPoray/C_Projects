// Pair.h
#ifndef _PAIR_H
#define _PAIR_H

class Pair
{
	double x, y;
public:
	Pair() :x(0), y(0){}
	Pair(double x, double y) :x(x), y(y){}
	Pair operator+(Pair&);
	Pair operator/(double);
	void Report();
};

#endif