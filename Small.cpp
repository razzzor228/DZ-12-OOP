#include "Small.h"

Small::Small() {
}

Small::Small(vector<int>& x, vector<int>& y)
{
	for (int i = 0; i < x.size(); i++) {
		v.push_back(Koordinats(x[i], y[i]));
	}
	razmer = x.size();
	type = new string(typeid(Small).name());
	cout << *type << endl;
}

int Small::Size()
{
	return razmer;
}

int Small::Getx(int r)
{
	Koordinats V = v[r];
	return V.x;
}

int Small::Gety(int r)
{
	Koordinats V = v[r];
	return V.y;
}

void Small::GetInfo()
{
	type = new string(typeid(Small).name());
	cout << *type << endl;
}

Small::~Small() {
	delete type;
}
