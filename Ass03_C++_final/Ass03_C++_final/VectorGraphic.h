// VectorGraphic.h
#ifndef _VECTORG_H
#define _VECTORG_H

#include <iostream>
using namespace std;

class VectorGraphic : public vector<GraphicElement>
{
public:
	VectorGraphic();
	~VectorGraphic();
	void AddGraphicElement();
	void DeleteGraphicElement();
	friend ostream& operator<<(ostream&, VectorGraphic&);
};

#endif