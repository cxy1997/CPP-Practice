#include "Window.h";
#include "Graph.h";
#include <cmath>
#include <iostream>
#include "windows.h"
#include "Hexagon.h"

using namespace Graph_lib;
using namespace std;
int main()
{
	Graph_lib::Window win(800, 600, "2");
	Hexagon p1(Point(200, 300), 50);
	p1.affiliate_to(win);
	Hexagon p2(Point(275, 343), 50);
	p2.affiliate_to(win);
	Hexagon p3(Point(275, 257), 50);
	p3.affiliate_to(win);
	Hexagon p4(Point(350, 300), 50);
	p4.affiliate_to(win);
	Hexagon p5(Point(350, 386), 50);
	p5.affiliate_to(win);
	Hexagon p6(Point(425, 343), 50);
	p6.affiliate_to(win);
	Hexagon p7(Point(200, 386), 50);
	p7.affiliate_to(win);
	Hexagon p8(Point(275, 429), 50);
	p8.affiliate_to(win);
	Hexagon p9(Point(350, 214), 50);
	p9.affiliate_to(win);
	Hexagon p10(Point(425, 257), 50);
	p10.affiliate_to(win);

	return Fl::run();
}