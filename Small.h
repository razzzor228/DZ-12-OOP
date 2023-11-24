#pragma once
#include "Shape.h"
class Small : public Shape
{
	vector<Koordinats> v;
	int razmer;
	string* type;
public:
	Small();
	Small(vector <int>& x, vector <int>& y);
	int Size();
	int Getx(int r);
	int Gety(int r);
	void GetInfo();
	~Small();
};

