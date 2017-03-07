#ifndef PHYSICAL_CLOCK
#define PHYSICAL_CLOCK
#include "Point.h"
#include "Window.h"
#include "Graph.h"
#include <cmath>
#include "gettime.h"
using namespace Graph_lib;
class Physical_clock
{
private:
	Point center;
	int hour, min, sec;
	Circle edge;
	Line twelve_0, twelve_1, twelve_2, twelve_3, twelve_4, twelve_5, 
		 twelve_6, twelve_7, twelve_8, twelve_9, twelve_10, twelve_11,
	     *sz, *fz, *mz;

public:
	Physical_clock(const Point& p, int h, int m, int s):center(p),edge(p,180),
	twelve_0(Point(p.x + 180, p.y + 0), Point(p.x + 150, p.y + 0)),
	twelve_1(Point(p.x + 155.885, p.y + 90), Point(p.x + 138.564, p.y + 80)),
	twelve_2(Point(p.x + 90, p.y + 155.885), Point(p.x + 80, p.y + 138.564)),
	twelve_3(Point(p.x + 0, p.y + 180), Point(p.x + 0, p.y + 150)),
	twelve_4(Point(p.x -90, p.y + 155.885), Point(p.x -80, p.y + 138.564)),
	twelve_5(Point(p.x -155.885, p.y + 90), Point(p.x -138.564, p.y + 80)),
	twelve_6(Point(p.x -180, p.y + 0), Point(p.x -150, p.y + 0)),
	twelve_7(Point(p.x -155.885, p.y -90), Point(p.x -138.564, p.y -80)),
	twelve_8(Point(p.x -90, p.y -155.885), Point(p.x -80, p.y -138.564)),
	twelve_9(Point(p.x + 0, p.y -180), Point(p.x +0, p.y + -150)),
	twelve_10(Point(p.x + 90, p.y -155.885), Point(p.x + 80, p.y -138.564)),
	twelve_11(Point(p.x + 155.885, p.y -90), Point(p.x + 138.564, p.y -80))
	{
		hour = h; min = m; sec = s;
	    sz = new Line(Point(p.x, p.y), Point(p.x + 90 * sin((30 * h + 0.5 * m) / 180.0*3.14159265358679323846264), p.y - 90 * cos((30 * h + 0.5 * m) / 180.0*3.14159265358679323846264)));
		fz = new Line(Point(p.x, p.y), Point(p.x + 150 * sin(6 * m / 180.0*3.14159265358679323846264), p.y - 150 * cos(6 * m / 180.0*3.14159265358679323846264)));
		mz = new Line(Point(p.x - 40 * sin(6 * s / 180.0*3.14159265358679323846264), p.y + 40 * cos(6 * s / 180.0*3.14159265358679323846264)), Point(p.x + 160 * sin(6 * s / 180.0*3.14159265358679323846264), p.y - 160 * cos(6 * s / 180.0*3.14159265358679323846264)));
		sz->set_color(Color::red);
		fz->set_color(Color::blue);
	}
	void set_time(int h, int m, int s)
	{
		hour = h; min = m; sec = s;
		delete sz;
		delete mz;
		delete fz;
		sz = new Line(center, Point(center.x + 90 * sin((30 * h + 0.5 * m) / 180.0*3.14159265358679323846264), center.y - 90 * cos((30 * h + 0.5 * m) / 180.0*3.14159265358679323846264)));
		fz = new Line(center, Point(center.x + 150 * sin(6 * m / 180.0*3.14159265358679323846264), center.y - 150 * cos(6 * m / 180.0*3.14159265358679323846264)));
		mz = new Line(Point(center.x - 40 * sin(6 * s / 180.0*3.14159265358679323846264), center.y + 40 * cos(6 * s / 180.0*3.14159265358679323846264)), Point(center.x + 160 * sin(6 * s / 180.0*3.14159265358679323846264), center.y - 160 * cos(6 * s / 180.0*3.14159265358679323846264)));
		sz->set_color(Color::red);
		fz->set_color(Color::blue);
	}
	void be_attached_to(Graph_lib::Window& win)
	{
		win.attach(edge);
		win.attach(twelve_0);
		win.attach(twelve_1);
		win.attach(twelve_2);
		win.attach(twelve_3);
		win.attach(twelve_4);
		win.attach(twelve_5);
		win.attach(twelve_6);
		win.attach(twelve_7);
		win.attach(twelve_8);
		win.attach(twelve_9);
		win.attach(twelve_10);
		win.attach(twelve_11);
		win.attach(*sz);
		win.attach(*fz);
		win.attach(*mz);
	}
	void plus_one_sec(Graph_lib::Window& win)
	{
		int h = hour, m = min, s = sec;
		s = (s + 1) % 60;
		if (s == 0) m = (m + 1) % 60;
		if (s == 0 && m == 0) h = (h + 1) % 24;
		win.detach(*mz);
		delete mz;
		mz = new Line(Point(center.x - 40 * sin(6 * s / 180.0*3.14159265358679323846264), center.y + 40 * cos(6 * s / 180.0*3.14159265358679323846264)), Point(center.x + 160 * sin(6 * s / 180.0*3.14159265358679323846264), center.y - 160 * cos(6 * s / 180.0*3.14159265358679323846264)));
		win.attach(*mz);
		mz->set_color(Color::black);
		if (m != min)
		{
			win.detach(*fz);
			delete fz;
			fz = new Line(center, Point(center.x + 150 * sin(6 * m / 180.0*3.14159265358679323846264), center.y - 150 * cos(6 * m / 180.0*3.14159265358679323846264)));
			win.attach(*fz);
			fz->set_color(Color::blue);
			win.detach(*sz);
			delete sz;
			sz = new Line(center, Point(center.x + 90 * sin((30 * h + 0.5 * m) / 180.0*3.14159265358679323846264), center.y - 90 * cos((30 * h + 0.5 * m) / 180.0*3.14159265358679323846264)));
			win.attach(*sz);
			sz->set_color(Color::red);
		}
		hour = h;
		min = m;
		sec = s;
	}
};
#endif
