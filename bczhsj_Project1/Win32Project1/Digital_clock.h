#ifndef DIGITAL_CLOCK
#define DIGITAL_CLOCK
#include "Point.h"
#include "Window.h"
#include "Graph.h"
using namespace Graph_lib;
const bool how_to_print[10][7] = { 1,1,1,0,1,1,1,
					0,0,1,0,0,1,0,
					1,0,1,1,1,0,1,
					1,0,1,1,0,1,1,
					0,1,1,1,0,1,0,
					1,1,0,1,0,1,1,
					1,1,0,1,1,1,1,
					1,0,1,0,0,1,0,
					1,1,1,1,1,1,1,
					1,1,1,1,0,1,1 };
class Digit
{
private:
	Point Center;
	Graph_lib::Polygon up;
	Graph_lib::Polygon upleft;
	Graph_lib::Polygon downleft;
	Graph_lib::Polygon down;
	Graph_lib::Polygon upright;
	Graph_lib::Polygon downright;
	Graph_lib::Polygon center;
	int num;
public:
	Digit(const Point& p, const double length, int n, Graph_lib::Window& win)
	{
		Center = p; num = n;
		center.add(Point(Center.x - length, Center.y));
		center.add(Point(Center.x - length * 3 / 4, Center.y + length / 4));
		center.add(Point(Center.x + length * 3 / 4, Center.y + length / 4));
		center.add(Point(Center.x + length, Center.y));
		center.add(Point(Center.x + length * 3 / 4, Center.y - length / 4));
		center.add(Point(Center.x - length * 3 / 4, Center.y - length / 4));
		center.set_color(Color::black);
		center.set_fill_color(Color::black);
		upleft.add(Point(Center.x - length * 9 / 8, Center.y - length / 8));
		upleft.add(Point(Center.x - length * 7 / 8, Center.y - length * 3 / 8));
		upleft.add(Point(Center.x - length * 7 / 8, Center.y - length * 15 / 8));
		upleft.add(Point(Center.x - length * 9 / 8, Center.y - length * 17 / 8));
		upleft.add(Point(Center.x - length * 11 / 8, Center.y - length * 15 / 8));
		upleft.add(Point(Center.x - length * 11 / 8, Center.y - length * 3 / 8));
		upleft.set_color(Color::black);
		upleft.set_fill_color(Color::black);
		downleft.add(Point(Center.x - length * 9 / 8, Center.y + length / 8));
		downleft.add(Point(Center.x - length * 7 / 8, Center.y + length * 3 / 8));
		downleft.add(Point(Center.x - length * 7 / 8, Center.y + length * 15 / 8));
		downleft.add(Point(Center.x - length * 9 / 8, Center.y + length * 17 / 8));
		downleft.add(Point(Center.x - length * 11 / 8, Center.y + length * 15 / 8));
		downleft.add(Point(Center.x - length * 11 / 8, Center.y + length * 3 / 8));
		downleft.set_color(Color::black);
		downleft.set_fill_color(Color::black);
		upright.add(Point(Center.x + length * 9 / 8, Center.y - length / 8));
		upright.add(Point(Center.x + length * 7 / 8, Center.y - length * 3 / 8));
		upright.add(Point(Center.x + length * 7 / 8, Center.y - length * 15 / 8));
		upright.add(Point(Center.x + length * 9 / 8, Center.y - length * 17 / 8));
		upright.add(Point(Center.x + length * 11 / 8, Center.y - length * 15 / 8));
		upright.add(Point(Center.x + length * 11 / 8, Center.y - length * 3 / 8));
		upright.set_color(Color::black);
		upright.set_fill_color(Color::black);
		downright.add(Point(Center.x + length * 9 / 8, Center.y + length / 8));
		downright.add(Point(Center.x + length * 7 / 8, Center.y + length * 3 / 8));
		downright.add(Point(Center.x + length * 7 / 8, Center.y + length * 15 / 8));
		downright.add(Point(Center.x + length * 9 / 8, Center.y + length * 17 / 8));
		downright.add(Point(Center.x + length * 11 / 8, Center.y + length * 15 / 8));
		downright.add(Point(Center.x + length * 11 / 8, Center.y + length * 3 / 8));
		downright.set_color(Color::black);
		downright.set_fill_color(Color::black);
		up.add(Point(Center.x - length, Center.y - length * 9 / 4));
		up.add(Point(Center.x - length * 3 / 4, Center.y - length * 2));
		up.add(Point(Center.x + length * 3 / 4, Center.y - length * 2));
		up.add(Point(Center.x + length, Center.y - length * 9 / 4));
		up.add(Point(Center.x + length * 3 / 4, Center.y - length * 5 / 2));
		up.add(Point(Center.x - length * 3 / 4, Center.y - length * 5 / 2));
		up.set_color(Color::black);
		up.set_fill_color(Color::black);
		down.add(Point(Center.x - length, Center.y + length * 9 / 4));
		down.add(Point(Center.x - length * 3 / 4, Center.y + 2 * length));
		down.add(Point(Center.x + length * 3 / 4, Center.y + 2 * length));
		down.add(Point(Center.x + length, Center.y + length * 9 / 4));
		down.add(Point(Center.x + length * 3 / 4, Center.y + length * 5 / 2));
		down.add(Point(Center.x - length * 3 / 4, Center.y + length * 5 / 2));
		down.set_color(Color::black);
		down.set_fill_color(Color::black);
		if (how_to_print[n][0]) win.attach(up);
		if (how_to_print[n][1]) win.attach(upleft);
		if (how_to_print[n][2]) win.attach(upright);
		if (how_to_print[n][3]) win.attach(center);
		if (how_to_print[n][4]) win.attach(downleft);
		if (how_to_print[n][5]) win.attach(downright);
		if (how_to_print[n][6]) win.attach(down);
	}
	void set(int n, Graph_lib::Window& win)
	{
		if (how_to_print[num][0]) win.detach(up);
		if (how_to_print[num][1]) win.detach(upleft);
		if (how_to_print[num][2]) win.detach(upright);
		if (how_to_print[num][3]) win.detach(center);
		if (how_to_print[num][4]) win.detach(downleft);
		if (how_to_print[num][5]) win.detach(downright);
		if (how_to_print[num][6]) win.detach(down);
		if (how_to_print[n][0]) win.attach(up);
		if (how_to_print[n][1]) win.attach(upleft);
		if (how_to_print[n][2]) win.attach(upright);
		if (how_to_print[n][3]) win.attach(center);
		if (how_to_print[n][4]) win.attach(downleft);
		if (how_to_print[n][5]) win.attach(downright);
		if (how_to_print[n][6]) win.attach(down);
		num = n;
	}
};
class Digital_clock
{
private:
	Digit a, b, c, d, e, f;
	Graph_lib::Polygon p1, p2, p3, p4;
	int Hour, Min, Sec;
public:
	Digital_clock(const Point& p, int h, int m, int s, Graph_lib::Window& win):
		Hour(h),Min(m),Sec(s),
		a(Point(p.x-150, p.y), 15, h/10, win), b(Point(p.x - 100, p.y), 15, h%10, win), c(Point(p.x - 25, p.y), 15, m/10, win),
		d(Point(p.x +25, p.y), 15, m%10, win), e(Point(p.x +100, p.y), 15, s/10, win), f(Point(p.x +150, p.y), 15, s%10, win)
	{
		p1.add(Point(p.x - 68.5, p.y+12));
		p1.add(Point(p.x - 62.5, p.y+18));
		p1.add(Point(p.x - 56.5, p.y+12));
		p1.add(Point(p.x - 62.5, p.y+6));
		p1.set_color(Color::black);
		p1.set_fill_color(Color::black);
		win.attach(p1);
		p2.add(Point(p.x - 68.5, p.y - 12));
		p2.add(Point(p.x - 62.5, p.y - 18));
		p2.add(Point(p.x - 56.5, p.y - 12));
		p2.add(Point(p.x - 62.5, p.y - 6));
		p2.set_color(Color::black);
		p2.set_fill_color(Color::black);
		win.attach(p2);
		p3.add(Point(p.x + 68.5, p.y + 12));
		p3.add(Point(p.x + 62.5, p.y + 18));
		p3.add(Point(p.x + 56.5, p.y + 12));
		p3.add(Point(p.x + 62.5, p.y + 6));
		p3.set_color(Color::black);
		p3.set_fill_color(Color::black);
		win.attach(p3);
		p4.add(Point(p.x + 68.5, p.y - 12));
		p4.add(Point(p.x + 62.5, p.y - 18));
		p4.add(Point(p.x + 56.5, p.y - 12));
		p4.add(Point(p.x + 62.5, p.y - 6));
		p4.set_color(Color::black);
		p4.set_fill_color(Color::black);
		win.attach(p4);
	}
	void plus_one_sec(Graph_lib::Window& win)
	{
		int h = Hour, m = Min, s = Sec;
		s = (s + 1) % 60;
		if (s == 0) m = (m + 1) % 60;
		if (s == 0 && m == 0) h = (h + 1) % 24;
		if (s % 10 != Sec % 10) f.set(s % 10, win);
		if (s / 10 != Sec / 10) e.set(s / 10, win);
		if (m % 10 != Min % 10) d.set(m % 10, win);
		if (m / 10 != Min / 10) c.set(m / 10, win);
		if (h % 10 != Hour % 10) b.set(h % 10, win);
		if (h / 10 != Hour / 10) a.set(h / 10, win);
		Hour = h; Min = m; Sec = s;
	}
	void minus_one_sec(Graph_lib::Window& win)
	{
		int h = Hour, m = Min, s = Sec;
		s = (s + 59) % 60;
		if (s == 59) m = (m + 59) % 60;
		if (s == 59 && m == 59) h = h - 1;
		if (s % 10 != Sec % 10) f.set(s % 10, win);
		if (s / 10 != Sec / 10) e.set(s / 10, win);
		if (m % 10 != Min % 10) d.set(m % 10, win);
		if (m / 10 != Min / 10) c.set(m / 10, win);
		if (h % 10 != Hour % 10) b.set(h % 10, win);
		if (h / 10 != Hour / 10) a.set(h / 10, win);
		Hour = h; Min = m; Sec = s;
	}
};
#endif
