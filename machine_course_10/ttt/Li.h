#ifndef LI
#define LI
#include "Point.h"
#include "Window.h"
#include <cmath>
#include "Graph.h"
const double PI = 3.14159265358979323846264;
using namespace Graph_lib;
class li
{
private:
	Point p1, p2;
	Graph_lib::Line l;
	Graph_lib::Polygon p;
public:
	li(const Point& pp1,const Point& pp2, Color cc = Color::black):p1(pp1),p2(pp2),l(pp1,pp2)
	{
		p.add(p2);
		double s = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
		double arrowlength = 2 * sqrt(10);
		double COS = 3 / sqrt(10), SIN = 1 / sqrt(10);
		double xx = (p1.x - p2.x) / s, yy = (p1.y - p2.y) / s;
		p.add(Point(p2.x + arrowlength*(xx*COS - yy*SIN), p2.y + arrowlength*(xx*SIN + yy*COS)));
		p.add(Point(p2.x + arrowlength*(xx*COS + yy*SIN), p2.y + arrowlength*(-xx*SIN + yy*COS)));
		l.set_color(cc);
		p.set_color(cc);
		p.set_fill_color(cc);
	}
	void affiliate_to(Graph_lib::Window& win)
	{
		win.attach(l);
		win.attach(p);
	}
};
#endif