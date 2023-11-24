#include "Big.h"
#include "Small.h"

struct Leaks {
    ~Leaks() {
        _CrtDumpMemoryLeaks();
    }
};
Leaks _l;

int main()
{
	vector <Shape*> obj;
	char chaR;
	string s;
	ifstream in("test (3).hpg");
	for (; in; ) {
		in.get(chaR);
		if (in.eof()) break;
		s = s + chaR;
	}
	vector<int> x;
	vector<int> y;
	string sx, sy;
	int c = 0, check = 0, checkx = 0, checky = 0;
	for (int i = 45; i < s.size(); i++) {
		if (s[i - 1] == 'P' && s[i] == 'U') {
			if (check == 0) {
				check = 1;
				c = 0;
				continue;
			}
			else if (check == 1) {
				if (c <= 2) {
					obj.push_back(new Small(x, y));
				}
				else {
					obj.push_back(new Big(x, y));
				}
				int sumx = 0, sumy = 0;
				int flag_min = 0, flag_max = 0;
				int xmin, ymin, xmax, ymax;
				for (int i = 0; i < x.size(); i++) {
					cout << "(" << x[i] << ";" << y[i] << ")" << endl;
					sumx = sumx + x[i];
					sumy = sumy + y[i];
					if (flag_min == 0) {
						xmin = x[i];
						ymin = y[i];
						flag_min = 1;
					}
					if (flag_max == 0) {
						xmax = x[i];
						ymax = y[i];
						flag_max = 1;
						continue;
					}
					if (xmax < x[i]) {
						xmax = x[i];
					}else
					if (ymax < y[i]) {
						ymax = y[i];
					}
					else
					if (xmin > x[i]) {
						xmin = x[i];
					}
					else
					if (ymin > y[i]) {
						ymin = y[i];
					}
				}
				cout << "Maximalnya koordinata X = " << xmax << endl;
				cout << "Minimalnaya koordinata X = " << xmin << endl;
				cout << "Maximalnya koordinata Y = " << ymax << endl;
				cout << "Minimalnaya koordinata Y = " << ymin << endl;
				cout << "Centr figuri = " << "(" << sumx / x.size() << ";" << sumy / y.size() << ")" << endl;
				cout << endl;
				x.clear();
				y.clear();
				c = 0;
				check = 1;
			}
			continue;
		}
		if (check == 1 && s[i] == 'D' && s[i - 1] == 'P') {
			continue;
		}
		if (s[i] == 'A' && s[i - 1] == 'P') {
			checkx = 1;
			continue;
		}
		if (checkx == 1 && s[i] >= '0' && s[i] <= '9') {
			sx = sx + s[i];
		}
		else if (s[i] == ',') {
			int ch;
			ch = atoi(sx.c_str());
			sx = "";
			x.push_back(ch);
			ch = 0;
			checkx = 0;
			checky = 1;
			continue;
		}
		if (checky == 1 && s[i] >= '0' && s[i] <= '9') {
			sy = sy + s[i];
		}
		else if (s[i] == ';' && sy != "") {
			int ch;
			ch = atoi(sy.c_str());
			sy = "";
			y.push_back(ch);
			ch = 0;
			checky = 0;
			checkx = 1;
			c++;
		}
	}
	for (int i = 0; i < obj.size(); i++) {
		delete obj[i];
		obj[i] = 0;
	}
}
