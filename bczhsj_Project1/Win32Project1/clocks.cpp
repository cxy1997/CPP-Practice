#include "Window.h";
#include "Graph.h";
#include "gettime.h"
#include <cmath>
#include <iostream>
#include "windows.h"
#include "Physical_clock.h"
#include "Digital_clock.h"
using namespace Graph_lib;
using namespace std;
int hour = 1, min = 0, sec = 0;
Graph_lib::Window *win;
Physical_clock *pc;
Digital_clock *dc;
void callback(void*) {
	puts("TICK");
	pc->plus_one_sec(*win);
	dc->plus_one_sec(*win);
	Fl::redraw();
	Fl::repeat_timeout(1.0, callback);
}
int main()
{
	win = new Graph_lib::Window(800, 600, "Clocks");
	get_time(hour, min, sec);
	pc = new Physical_clock(Point(200, 300), hour, min, sec);
	pc->be_attached_to(*win);
	dc=new Digital_clock(Point(600, 300), hour, min, sec, *win);
	win->show();
	
	Fl::add_timeout(1.0, callback);
	return Fl::run();
}