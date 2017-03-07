#include "Window.h";
#include "Graph.h";
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_draw.H"
#include "Li.h"
#include <cmath>
#include <iostream>
using namespace std;
using namespace Graph_lib;
double a1(double n) { return cos(n) + sin(n); }
double a2(double n) { return 1; }
int main()
{
	Graph_lib::Window win(800, 600, "2");
	Function s1(sin, -10, 10, Point(400, 300), 400, 30, 130);
	s1.set_color(Color::black);
	win.attach(s1);
	Function s2(cos, -10, 10, Point(400, 300), 400, 30, 130);
	s2.set_color(Color::red);
	win.attach(s2);
	Function s3(a1, -10, 10, Point(400, 300), 400, 30, 130);
	s3.set_color(Color::blue);
	win.attach(s3);
	Function s4(a2, -10, 10, Point(400, 300), 400, 30, 130);
	s4.set_color(Color::magenta);
	win.attach(s4);
	Axis x(Axis::x, Point(40, 300), 690, 23);
	li xp(Point(720, 300), Point(760, 300));
	Axis y(Axis::y, Point(400, 560), 390, 3);
	li yp(Point(400, 170), Point(400, 40));
	y.set_color(Color::black);
	x.set_color(Color::black);
	xp.affiliate_to(win);
	yp.affiliate_to(win);
	win.attach(x);
	win.attach(y);
	Fl_Box rx(750, 304, 10, 10, "x");
	rx.box(FL_NO_BOX);
	rx.align(FL_ALIGN_INSIDE + FL_ALIGN_LEFT);
	win.add(rx);
	Fl_Box r0(386, 304, 10, 10, "0");
	r0.box(FL_NO_BOX);
	r0.align(FL_ALIGN_INSIDE + FL_ALIGN_LEFT);
	win.add(r0);
	Fl_Box rx1(425, 304, 10, 10, "1");
	rx1.box(FL_NO_BOX);
	rx1.align(FL_ALIGN_INSIDE + FL_ALIGN_LEFT);
	win.add(rx1);
	Fl_Box ry1(386, 170, 10, 10, "1");
	ry1.box(FL_NO_BOX);
	ry1.align(FL_ALIGN_INSIDE + FL_ALIGN_LEFT);
	win.add(ry1);
	Fl_Box ry(386, 40, 10, 10, "y");
	ry.box(FL_NO_BOX);
	ry.align(FL_ALIGN_INSIDE + FL_ALIGN_LEFT);
	win.add(ry);
	Line p1(Point(630, 60), Point(670, 60));
	p1.set_color(Color::black);
	win.attach(p1);
	Fl_Box r1(675, 55, 30, 10, "y=sin(x)");
	r1.box(FL_NO_BOX);
	r1.align(FL_ALIGN_INSIDE + FL_ALIGN_LEFT);
	win.add(r1);
	Line p2(Point(630, 80), Point(670, 80));
	p2.set_color(Color::red);
	win.attach(p2);
	Fl_Box r2(675, 75, 30, 10, "y=cos(x)");
	r2.box(FL_NO_BOX);
	r2.align(FL_ALIGN_INSIDE + FL_ALIGN_LEFT);
	win.add(r2);
	Line p3(Point(630, 100), Point(670, 100));
	p3.set_color(Color::blue);
	win.attach(p3);
	Fl_Box r3(675, 95, 30, 10, "y=sin(x)+cos(x)");
	r3.box(FL_NO_BOX);
	r3.align(FL_ALIGN_INSIDE + FL_ALIGN_LEFT);
	win.add(r3);
	Line p4(Point(630, 120), Point(670, 120));
	p4.set_color(Color::magenta);
	win.attach(p4);
	Fl_Box r4(675, 115, 50, 10, "y=sin(x)^2+cos(x)^2");
	r4.box(FL_NO_BOX);
	r4.align(FL_ALIGN_INSIDE + FL_ALIGN_LEFT);
	win.add(r4);
	win.show();
	return Fl::run();
}