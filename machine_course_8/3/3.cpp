#include "Window.h";
#include "Graph.h";
#include <cmath>
#include <iostream>
#include "windows.h"
#include "Star.h"
using namespace Graph_lib;
using namespace std;
int main()
{
	Graph_lib::Window win(800, 600, "3");
	Star s(Point(400, 300), 5, 200);
	s.affiliate_to(win);
	Fl::run();
}