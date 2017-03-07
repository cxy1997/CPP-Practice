#include "Window.h";
#include "Graph.h";
#include <cmath>
#include <iostream>
#include <vector>
#include "Poly.h"
using namespace std;
using namespace Graph_lib;
int main()
{
	int n, i, x, y;
	vector<Point> v;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> x >> y;
		v.push_back(Point(x, y));
	}
	Poly *p;
	try
	{
		p = new Poly(v, Color::cyan); 
		Graph_lib::Window win(800, 600, "1");
		p->affiliate_to(win);
		win.show();
		return Fl::run();
	}
	catch (...) { cout << "Error!\n"; system("pause"); }
	
}