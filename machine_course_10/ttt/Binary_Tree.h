#ifndef BINARY_TREE
#define BINARY_TREE
#include "Point.h"
#include "Window.h"
#include <cmath>
#include "Graph.h"
#include "Li.h"
#include <string>
const double SQUAD = 0.8660254038;
using namespace Graph_lib;
using namespace std;
class Binary_tree:public Shape
{
protected:
	int radius, Num;
	Point root;
	Point *points;
	Point *lineEnds[2];
	Circle **circles;
	Line **lines;
public:
	Binary_tree(int levels, const Point& ROOT, int RADIUS)
		:root(ROOT),radius(RADIUS),circles(NULL),lines(NULL)
	{
		if (levels > 0)
		{
			int num = 1, i, j, k = 3;
			for (i = 0; i < levels; ++i) num *= 2;
			j = num/2;
			points = new Point[num];
			lineEnds[0] = new Point[num];
			lineEnds[1] = new Point[num];
			--num;
			Num = num;
			points[1] = root;
			for (i = 2; i <= num; ++i)
			{
				points[i].y = points[i / 2].y + 4 * radius;
				lineEnds[0][i].y = points[i / 2].y + radius*0.5;
				if (i % 2)
				{
					points[i].x = points[i / 2].x + j*radius;
					lineEnds[0][i].x = points[i / 2].x + SQUAD*radius;
				}
				else
				{
					points[i].x = points[i / 2].x - j*radius;
					lineEnds[0][i].x = points[i / 2].x - SQUAD*radius;
				}
				lineEnds[1][i] = Point(points[i].x, points[i].y - radius);
				if (i == k)
				{
					j /= 2;
					k = 2 * k + 1;
				}
			}
		}
	}
	virtual void affiliate_to(Graph_lib::Window& win)
	{
		int i;
		circles = new Circle*[Num + 1];
		lines = new Line*[Num + 1];
		for (i = 0; i <= Num; ++i)
		{
			lines[i] = NULL;
			circles[i] = NULL;
		}
		for (i = 1; i <= Num; ++i)
		{
			circles[i] = new Circle(points[i], radius);
			circles[i]->set_color(Color::black);
			circles[i]->set_fill_color(Color::yellow);
			win.attach(*circles[i]);

			if (i >= 2)
			{
				lines[i] = new Line(lineEnds[0][i], lineEnds[1][i]);
				lines[i]->set_color(Color::black);
				win.attach(*lines[i]);
			}
		}
	}
};
#endif
