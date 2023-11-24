#pragma once
#include "Shape.h"
class Big : public Shape
{
	vector<Koordinats> v;
	int razmer;
	string* type;
public:
	Big();
	Big(vector <int>& x, vector <int>& y);
	int Size();
	int Getx(int r);
	int Gety(int r);
	void GetInfo();
	~Big();
};

