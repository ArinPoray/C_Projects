// ass3.cpp
#include <crtdbg.h>
#include <iostream>
using namespace std;
#include <vector>
#include "Pair.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

#define _CRTDBG_MAP_ALLOC

enum{ RUNNING = 1 };

int main()
{
	char response;
	VectorGraphic Image;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	while (RUNNING)
	{
		cout << endl << "Please select an option:" << endl;
		cout << "1. Add a Graphic Element" << endl;
		cout << "2. Delete a GraphicElement" << endl;
		cout << "3. List all the Graphic Elements" << endl;
		cout << "q. Quit" << endl;
		cout << "CHOICE: ";
		cin >> response;
		switch (response)
		{
		case '1':Image.AddGraphicElement(); break;
		case '2':Image.DeleteGraphicElement(); break;
		case '3':cout << Image; break;
		case 'q': return 0;
		default:cout << "Please enter a valid option\n";
		}
		cout << endl;
	}
}
