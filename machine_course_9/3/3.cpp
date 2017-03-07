#include "Window.h";
#include "Graph.h";
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_draw.H"
#include "Li.h"
#include <cmath>
#include <iostream>
#include <vector>
#include "Poles.h"
#include <string>
using namespace std;
using namespace Graph_lib;
double cvt(const string& s)
{
	double res = 0, f=1;
	bool pos = (s[0] != '-');
	int l = s.length(), i = 1 - pos;
	while (i < l && s[i] != '.')
	{
		res = res * 10 + s[i] - '0';
		++i;
	}
	if (i == l) return res; else ++i;
	while (i < l)
	{
		f /= 10;
		res += f*(s[i] - '0');
		++i;
	}
	return res;
}
int main()
{
	vector<string> v1;
	vector<double> v2;
	int n, i;
	string t;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		v1.push_back(t);
		v2.push_back(cvt(t));
	}
	try
	{
		Poles p(v1,v2);
		Graph_lib::Window win(800, 600, "3");
		li ax(Point(100, 500), Point(760, 500));
		ax.affiliate_to(win);
		li ay(Point(100, 500), Point(100, 50));
		ay.affiliate_to(win);
		p.affiliate_to(win);
		win.show();
		return Fl::run();
	}
	catch (...) { cout << "Error!\n"; system("pause"); }
}