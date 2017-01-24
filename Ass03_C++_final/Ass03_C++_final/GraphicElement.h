// GraphicElement.h
#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#include <vector>
#include <iostream>
using namespace std;

class GraphicElement : public vector<Shape*>
{
	static const int SIZE = 256;
	char name[SIZE];
public:
	GraphicElement(Shape **, char *, unsigned int);
	GraphicElement(const GraphicElement&);
	GraphicElement& operator=(GraphicElement&);
	~GraphicElement();
	friend ostream& operator<<(ostream&, GraphicElement&);
};

#endif