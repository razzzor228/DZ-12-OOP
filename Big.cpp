#include "Big.h"

Big::Big() {
}

Big::Big(vector<int>& x, vector<int>& y)
{
	for (int i = 0; i < x.size(); i++) {
		v.push_back(Koordinats(x[i], y[i]));
	}
	razmer = x.size();
	type = new string(typeid(Big).name());
	cout << *type << endl;
}

int Big::Size()
{
	return razmer;
}

int Big::Getx(int r)
{
	Koordinats V = v[r];
	return V.x;
}

int Big::Gety(int r)
{
	Koordinats V = v[r];
	return V.y;
}

void Big::GetInfo()
{
	type = new string(typeid(Big).name());
	cout << *type << endl;
}

Big::~Big() {
	delete type;
}
