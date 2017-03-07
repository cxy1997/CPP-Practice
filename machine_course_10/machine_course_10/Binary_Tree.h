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
	Color lineColor;
	char **text;
	bool arrow;
	Circle **circles;
	Line **lines;
	li **lis;
	Fl_Box **words;
public:
	Binary_tree(int levels, const Point& ROOT, int RADIUS, const string& s = "", bool ARROW = false, Color LINECOLOR = Color::black)
		:root(ROOT),lineColor(LINECOLOR),radius(RADIUS),arrow(ARROW),text(NULL),circles(NULL),lines(NULL),lis(NULL),words(NULL)
	{
		if (levels > 0)
		{
			int num = 1, i, j, k = 3;
			for (i = 0; i < levels; ++i) num *= 2;
			j = num/2;
			points = new Point[num];
			lineEnds[0] = new Point[num];
			lineEnds[1] = new Point[num];
			text = new char*[num];
			--num;
			Num = num;
			points[1] = root;
			for (i = 1; i <= num; ++i)
			{
				text[i] = new char[2];
				text[i][1] = '\0';
				if (i <= s.length()) text[i][0] = s[i - 1];
				else text[i][0] = ' ';
			}
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
		words = new Fl_Box*[Num + 1];
		if (arrow)
		{
			lis = new li*[Num + 1];
			for (i = 0; i <= Num; ++i)
			{
				lis[i] = NULL;
				circles[i] = NULL;
				words[i] = NULL;
			}
		}
		else
		{
			lines = new Line*[Num + 1];
			for (i = 0; i <= Num; ++i)
			{
				lines[i] = NULL;
				circles[i] = NULL;
				words[i] = NULL;
			}
		}
		for (i = 1; i <= Num; ++i)
		{
			circles[i] = new Circle(points[i], radius);
			circles[i]->set_color(lineColor);
			circles[i]->set_fill_color(Color::yellow);
			win.attach(*circles[i]);
			words[i] = new Fl_Box(points[i].x - 4, points[i].y - 3, 10, 10, text[i]);
			words[i]->box(FL_NO_BOX);
			words[i]->align(FL_ALIGN_INSIDE + FL_ALIGN_BOTTOM_LEFT);
			win.add(*words[i]);

			if (i >= 2)
			{
				if (arrow)
				{
					lis[i] = new li(lineEnds[0][i], lineEnds[1][i], lineColor);
					lis[i]->affiliate_to(win);
				}
				else
				{
					lines[i] = new Line(lineEnds[0][i], lineEnds[1][i]);
					lines[i]->set_color(lineColor);
					win.attach(*lines[i]);
				}
			}
		}
	}
	virtual ~Binary_tree()
	{
		int i;
		if (points!=NULL) delete [] points;
		if (lineEnds[0] != NULL) delete [] lineEnds[0];
		if (lineEnds[1] != NULL) delete [] lineEnds[1];
		if (text != NULL)
		{
			for (i = 1; i <= Num; ++i)
			{
				delete[] text[i];
			}
			delete[] text;
		}
		if (circles != NULL)
		{
			for (i = 0; i <= Num; ++i)
			{
				delete circles[i];
			}
			delete[] circles;
		}
		if (lines != NULL)
		{
			for (i = 0; i <= Num; ++i)
			{
				delete lines[i];
			}
			delete[] lines;
		}
		if (lis != NULL)
		{
			for (i = 0; i <= Num; ++i)
			{
				delete lis[i];
			}
			delete[] lis;
		}
		if (words != NULL)
		{
			for (i = 0; i <= Num; ++i)
			{
				delete words[i];
			}
			delete[] words;
		}
	}
};
class Triangle_tree:public Binary_tree
{
private:
	Graph_lib::Polygon *polys;
public:
	Triangle_tree(int levels, const Point& ROOT, int RADIUS, const string& s = "", bool ARROW = false, Color LINECOLOR = Color::black)
		:Binary_tree(levels, ROOT, RADIUS, s, ARROW, LINECOLOR), polys(NULL){}
	void affiliate_to(Graph_lib::Window& win)
	{
		int i;
		polys = new Graph_lib::Polygon[Num + 1];
		words = new Fl_Box*[Num + 1];
		if (arrow)
		{
			lis = new li*[Num + 1];
			for (i = 0; i <= Num; ++i)
			{
				lis[i] = NULL;
				words[i] = NULL;
			}
		}
		else
		{
			lines = new Line*[Num + 1];
			for (i = 0; i <= Num; ++i)
			{
				lines[i] = NULL;
				words[i] = NULL;
			}
		}
		for (i = 1; i <= Num; ++i)
		{
			polys[i].add(Point(points[i].x, points[i].y - radius));
			polys[i].add(Point(points[i].x - SQUAD * radius, points[i].y + radius * 0.5));
			polys[i].add(Point(points[i].x + SQUAD * radius, points[i].y + radius * 0.5));
			polys[i].set_color(lineColor);
			win.attach(polys[i]);
			words[i] = new Fl_Box(points[i].x - 4, points[i].y - 3, 10, 10, text[i]);
			words[i]->box(FL_NO_BOX);
			words[i]->align(FL_ALIGN_INSIDE + FL_ALIGN_BOTTOM_LEFT);
			win.add(*words[i]);

			if (i >= 2)
			{
				if (arrow)
				{
					lis[i] = new li(lineEnds[0][i], lineEnds[1][i], lineColor);
					lis[i]->affiliate_to(win);
				}
				else
				{
					lines[i] = new Line(lineEnds[0][i], lineEnds[1][i]);
					lines[i]->set_color(lineColor);
					win.attach(*lines[i]);
				}
			}
		}
	}
	virtual ~Triangle_tree()
	{
		if (polys != NULL) delete[] polys;
	}
};
#endif
