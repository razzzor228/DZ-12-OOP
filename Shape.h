#pragma once
#include "Koordinats.h"
class Shape
{
	int razmer;
public:
	Shape();
	virtual int Size();
	virtual int Getx(int r);
	virtual int Gety(int r);
	virtual void GetInfo();
	virtual ~Shape();
};


