#ifndef POLY
#define POLY
#include "Point.h"
#include "Window.h"
#include <vector>
#include "Graph.h"
using namespace Graph_lib;
class Poly_error{};
int multiply(const Point& a, const Point& b)
{
	return (a.x*b.y - a.y*b.x);
}
bool conflict(const Point& a1, const Point& a2, const Point& b1, const Point& b2)
{
	Point p31 = Point(a1.x - b1.x, a1.y - b1.y);
	Point p34 = Point(b2.x - b1.x, b2.y - b1.y);
	Point p32 = Point(a2.x - b1.x, a2.y - b1.y);
	Point p12 = Point(a2.x - a1.x, a2.y - a1.y);
	Point p14 = Point(b2.x - a1.x, b2.y - a1.y);
	int d1 = multiply(p31, p34), d2 = multiply(p32, p34), d3 = -multiply(p31, p12), d4 = multiply(p14, p12);
	return (d1*d2 < 0 && d3*d4 < 0);

}
class Poly
{
private:
	vector<Point> points;
	Graph_lib::Polygon edges;
public:
	Poly(const vector<Point> p, Color cc):points(p)
	{
		int i, j, k;
		if (points.size() < 3) throw Poly_error();
		for (i = 3; i < points.size(); ++i) for (j = 0; j < i - 2; ++j)
			if (conflict(points[j], points[j + 1], points[i - 1], points[i])) throw Poly_error();
		for (i = 0; i < points.size(); ++i) edges.add(points[i]);
		edges.set_color(Color::black);
		edges.set_fill_color(cc);
	}
	void affiliate_to(Graph_lib::Window& win)
	{
		win.attach(edges);
	}
};
#endif