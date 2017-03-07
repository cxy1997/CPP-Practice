#ifndef HEAXGON
#define HEAXGON
#include "Point.h"
#include "Window.h"
#include <cmath>
#include "Graph.h"
using namespace Graph_lib;
const double yoo = sqrt(3) / 2;
class Hexagon
{
private:
	Point center;
	int size;
	Graph_lib::Polygon edge;
public:
	Hexagon(const Point& c,int s):center(c),size(s)
	{
		edge.add(Point(center.x - s / 2, center.y + s * yoo));
		edge.add(Point(center.x + s / 2, center.y + s * yoo));
		edge.add(Point(center.x + s, center.y));
		edge.add(Point(center.x + s / 2, center.y - s * yoo));
		edge.add(Point(center.x - s / 2, center.y - s * yoo));
		edge.add(Point(center.x - s, center.y));
		edge.set_color(Color::black);
		edge.set_fill_color(Color::cyan);
	}
	void affiliate_to(Graph_lib::Window& win)
	{
		win.attach(edge);
	}
};
#endif
