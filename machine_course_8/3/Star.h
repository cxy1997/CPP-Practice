#ifndef STAR
#define STAR
#include "Point.h"
#include "Window.h"
#include <cmath>
#include "Graph.h"
using namespace Graph_lib;
const double PI = 3.14159265358979323846264;
class Star
{
private:
	Point center;
	int n, size;
	Graph_lib::Polygon edge;
public:
	Star(const Point& c, int nn, int s) :center(c), n(nn), size(s)
	{
		double sita = -PI / 2.0, delta = PI / n;
		double length[2] = { size,size / sin(PI * (n+2) / 2 / n) * sin(PI * (n - 4) / 2 /n) };
		//double length[2] = { size,size / sin(PI /180*126) * sin(PI/180*18) };
		for (int i = 0; i < n * 2; ++i)
		{
			edge.add(Point(center.x + length[i % 2] * cos(sita + i * delta), center.y + length[i % 2] * sin(sita + i * delta)));
		}
		edge.set_color(Color::black);
		edge.set_fill_color(Color::cyan);
	}
	void affiliate_to(Graph_lib::Window& win)
	{
		win.attach(edge);
	}
};
#endif
